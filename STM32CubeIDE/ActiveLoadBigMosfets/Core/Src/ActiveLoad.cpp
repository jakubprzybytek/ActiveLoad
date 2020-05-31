#include <touchgfx/hal/OSWrappers.hpp>
#include "app_touchgfx.h"

#include "stdio.h"
#include "ApplicationState.hpp"
#include "FanController.hpp"
#include "LoadController.hpp"

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

	HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_ALL);

	ina233.init();

	// main ticks
	HAL_NVIC_EnableIRQ(TIM5_IRQn);
	HAL_TIM_Base_Start_IT(&htim5);

	//HAL_TIM_Base_Start(&htim4);
	//HAL_TIM_IC_Start(&htim4, TIM_CHANNEL_4);
}

void ActiveLoad_loop() {
	MX_TouchGFX_Process();
	HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
}

#define FAN_PULSES_COUNT 50
uint16_t fanPulsesCount;
uint16_t previousFanTick;

// tick every 20ms
void ActiveLoad_tick() {

	applicationState.voltage = ina233.readVoltage();
	applicationState.current = ina233.readCurrent();

	applicationState.fanDutyCycle = TIM3->CNT;
	fanController.setSpeed(applicationState.fanDutyCycle);
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
	tick = tick >= 49 ? 0 : tick + 1;
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	if (GPIO_Pin == Fan_Sensor_Pin) {
		fanPulsesCount++;
		if (fanPulsesCount == FAN_PULSES_COUNT) {
			uint16_t currentFanTick = HAL_GetTick();
			uint16_t ticks = currentFanTick - previousFanTick;
			applicationState.fanRPM = 60000 * (FAN_PULSES_COUNT / 2) / ticks;
			previousFanTick = currentFanTick;
			fanPulsesCount = 0;
		}
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (htim == &htim5) {
		ActiveLoad_tick();
	}
}
