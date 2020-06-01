#include <touchgfx/hal/OSWrappers.hpp>
#include "app_touchgfx.h"

#include "stdio.h"
#include "ApplicationState.hpp"
#include "FanController.hpp"
#include "LoadController.hpp"
#include "Encoder.hpp"

#include "devices/INA233.hpp"
#include "devices/TC74.hpp"
#include "devices/RVT28AETNWC00.hpp"
#include "devices/FT6206.hpp"

#include "ActiveLoad.h"

extern DAC_HandleTypeDef hdac;
extern I2C_HandleTypeDef hi2c2;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim5;
extern TIM_HandleTypeDef htim4;
extern RTC_HandleTypeDef hrtc;

ApplicationState applicationState;
FanController fanController(&htim2);
LoadController loadController(&hdac);

Encoder encoder;

INA233 ina233(&hi2c2);
TC74 tc74(&hi2c2);
RVT28AETNWC00 display;
FT6206 touchPad(&hi2c2);

int16_t tick = 0;

void ActiveLoad_init() {
	fanController.setSpeed(0);
	loadController.setLoad(0);

	MX_TouchGFX_Init();

	HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);

	display.init();
	touchPad.init();
	HAL_GPIO_WritePin(Display_LED_Ctrl_GPIO_Port, Display_LED_Ctrl_Pin, GPIO_PIN_SET);

	ina233.init();

	encoder.reset(0, 0, 8000, 100);

	// encoder
	htim3.Instance->CNT = 50;
	HAL_TIM_Encoder_Start_IT(&htim3, TIM_CHANNEL_ALL);

	// main ticks
	HAL_TIM_Base_Start_IT(&htim5);

	// ticks for measuring fan RPM
	HAL_TIM_Base_Start(&htim4);

	// enable interrupts
	HAL_NVIC_EnableIRQ(TIM5_IRQn);
}

void ActiveLoad_loop() {
	MX_TouchGFX_Process();
	HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
}

// tick every 20ms
void ActiveLoad_tick() {

	applicationState.voltage = ina233.readVoltage();
	applicationState.current = ina233.readCurrent();

	applicationState.fanDutyCycle = TIM3->CNT;
	//fanController.setSpeed(applicationState.fanDutyCycle);
	//fanController.setSpeed(TIM3->CNT);
	//loadController.setLoad(applicationState.fanDutyCycle * 10);

	if (touchPad.checkIfTouched()) {
		applicationState.touched = true;
		touchPad.getTouch(applicationState.touchX, applicationState.touchY);
	} else {
		applicationState.touched = false;
	}

	// once a second
	if (tick == 0) {
		applicationState.temperature = tc74.readTemperature();

		// rtc
		RTC_DateTypeDef date;
		HAL_RTC_GetTime(&hrtc, &applicationState.time, RTC_FORMAT_BIN);
		HAL_RTC_GetDate(&hrtc, &date, RTC_FORMAT_BIN);
	}

	touchgfx::OSWrappers::signalVSync();

	// 50 x 20ms = 1s
	tick = tick >= 49 ? 0 : tick + 1;
}

#define FAN_PULSES_COUNT 50
uint16_t fanPulsesCount;
uint16_t previousFanTick;

// Ticks from htim4 = 100us
void ActiveLoad_fanPulse() {
	fanPulsesCount++;
	if (fanPulsesCount == FAN_PULSES_COUNT) {
		uint16_t currentFanTick = htim4.Instance->CNT;
		uint16_t ticks = currentFanTick - previousFanTick;
		applicationState.fanRPM = 600000 * (FAN_PULSES_COUNT / 2) / ticks;
		previousFanTick = currentFanTick;
		fanPulsesCount = 0;
	}
}



void ActiveLoad_EncoderTick() {
	if (htim3.Instance->CNT < 50) {
		encoder.down();
	} else if (htim3.Instance->CNT > 50) {
		encoder.up();
	}
	applicationState.currentLimit = (float) encoder.getValue() * 0.001;
	htim3.Instance->CNT = 50;
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	if (GPIO_Pin == Fan_Sensor_Pin) {
		ActiveLoad_fanPulse();
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (htim == &htim5) {
		ActiveLoad_tick();
	}
}
