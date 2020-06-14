#include <touchgfx/hal/OSWrappers.hpp>
#include "app_touchgfx.h"

#include "stdio.h"
#include "ApplicationState.hpp"
#include "MessageQueue.hpp"
#include "FanController.hpp"
#include "LoadController.hpp"
#include "Encoder.hpp"
#include "EEPROM.hpp"
#include "PID.hpp"
#include "Hysteresis.hpp"

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

#define TICK_TIME 0.02f // 20ms
#define CURRENT_STEP_FOR_VOLTAGE_LIMIT 0.1f

ApplicationState applicationState;
FanController fanController(&htim2);
LoadController loadController(&hdac);
EEPROM eeprom;
Encoder encoder;

INA233 ina233(&hi2c2);
TC74 tc74(&hi2c2);
RVT28AETNWC00 display;
FT6206 touchPad(&hi2c2);

PID loadControllerPID(400.0f, 1000.0f, TICK_TIME, 0.0f, 3000.0f);
PID fanControllerPID(5.0f, 0.0f, 1.0f, 0.0f, 100.0f);
Hysteresis fanHysteresis(5, 0, 0, 6);

int16_t tick = 0;

void ActiveLoad_init() {
	fanController.setSpeed(0);
	loadController.setLoad(0);

	HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);

	ina233.init();

	encoder.reset(applicationState.currentLimit * 1000, 0, 8000, 100);

	// encoder
	htim3.Instance->CNT = 50;
	HAL_TIM_Encoder_Start_IT(&htim3, TIM_CHANNEL_ALL);

	// main ticks
	HAL_TIM_Base_Start_IT(&htim5);

	// ticks for measuring fan RPM
	HAL_TIM_Base_Start(&htim4);

	eeprom.read(applicationState);
	HAL_RTC_SetTime(&hrtc, &applicationState.time, RTC_FORMAT_BIN);

	display.init();
	touchPad.init();
	HAL_GPIO_WritePin(Display_LED_Ctrl_GPIO_Port, Display_LED_Ctrl_Pin, GPIO_PIN_SET);

	MX_TouchGFX_Init();
}

void ActiveLoad_loop() {
	MX_TouchGFX_Process();
	HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
}

// tick every 20ms
void ActiveLoad_tick() {

	applicationState.voltageReadout = ina233.readVoltage();
	applicationState.currentReadout = ina233.readCurrent();
	applicationState.powerReadout = ina233.readPower();

	applicationState.chargeMiliAmpSeconds += applicationState.currentReadout * 1000.0f * TICK_TIME;
	applicationState.chargeAmpHours = applicationState.chargeMiliAmpSeconds / 1000.0f / 3600.0f;

	applicationState.chargeMiliWattSeconds += applicationState.powerReadout * 1000.0f * TICK_TIME;
	applicationState.chargeWattHours = applicationState.chargeMiliWattSeconds / 1000.0f / 3600.0f;

	// check touch panel
	if (touchPad.checkIfTouched()) {
		applicationState.touched = true;
		touchPad.getTouch(applicationState.touchX, applicationState.touchY);
	} else {
		applicationState.touched = false;
	}

	ActiveLoad_processMessages();

	if (applicationState.loadSinkEnabled) {
		// PID for load controller
		applicationState.loadLevel = loadControllerPID.update(applicationState.currentLimit, applicationState.currentReadout);
		loadController.setLoad(applicationState.loadLevel);
	}

	// once a second
	if (tick == 0) {
		// read temperature
		applicationState.temperature = tc74.readTemperature();

		// PID for load controller
		applicationState.fanDutyCycleSetValue = fanControllerPID.update(applicationState.temperature, 30.0f);
		applicationState.fanDutyCycle = fanHysteresis.update(applicationState.fanDutyCycleSetValue);
		fanController.setSpeed(applicationState.fanDutyCycle);

		// read rtc
		RTC_DateTypeDef date;
		HAL_RTC_GetTime(&hrtc, &applicationState.time, RTC_FORMAT_BIN);
		HAL_RTC_GetDate(&hrtc, &date, RTC_FORMAT_BIN);

		// apply voltageReadout limit
		if (applicationState.loadSinkEnabled && applicationState.voltageLimitEnabled) {
			if (applicationState.currentLimit > 0.0f && applicationState.voltageReadout <= applicationState.voltageLimit) {
				applicationState.currentLimit -= CURRENT_STEP_FOR_VOLTAGE_LIMIT;
				if (applicationState.currentLimitInEdit) {
					encoder.reset(applicationState.currentLimit * 1000, 0, 8000, 100);
				}
			}
		}
	}

	touchgfx::OSWrappers::signalVSync();

	// 50 x 20ms = 1s
	tick = tick >= 49 ? 0 : tick + 1;
}

void ActiveLoad_processMessages() {
	while (MessageQueue::getInstance().messageWaiting()) {
		switch (MessageQueue::getInstance().getMessage()) {
		case SELECT_VOLTAGE_LIMIT_FOR_EDIT:
			encoder.reset(applicationState.voltageLimit * 1000, 5000, 30000, 100);
			applicationState.currentLimitInEdit = false;
			break;
		case SELECT_CURRENT_LIMIT_FOR_EDIT:
			encoder.reset(applicationState.currentLimit * 1000, 0, 8000, 100);
			applicationState.currentLimitInEdit = true;
			break;
		case RESET_COUNTERS:
			applicationState.chargeMiliAmpSeconds = 0;
			applicationState.chargeMiliWattSeconds = 0;
			applicationState.time.Hours = 0;
			applicationState.time.Minutes = 0;
			applicationState.time.Seconds = 0;
			HAL_RTC_SetTime(&hrtc, &applicationState.time, RTC_FORMAT_BIN);
			break;
		case START_LOAD_SINK:
			applicationState.loadSinkEnabled = true;
			break;
		case STOP_LOAD_SINK:
			applicationState.loadSinkEnabled = false;
			applicationState.loadLevel = 0;
			loadController.setLoad(applicationState.loadLevel);
			break;
		case ENABLE_VOLTAGE_LIMIT:
			applicationState.voltageLimitEnabled = true;
			break;
		case DISABLE_VOLTAGE_LIMIT:
			applicationState.voltageLimitEnabled = false;
			break;
		}
	}
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

	if (applicationState.currentLimitInEdit) {
		applicationState.currentLimit = (float) encoder.getValue() * 0.001;
	} else {
		applicationState.voltageLimit = (float) encoder.getValue() * 0.001;
	}
	htim3.Instance->CNT = 50;
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	if (GPIO_Pin == Fan_Sensor_Pin) {
		ActiveLoad_fanPulse();
	} else if (GPIO_Pin == Encoder_Switch_Pin) {
		//eeprom.write(applicationState);
		//eeprom.read(applicationState);
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (htim == &htim5) {
		ActiveLoad_tick();
	}
}

void HAL_PWR_PVDCallback() {
	HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(Display_LED_Ctrl_GPIO_Port, Display_LED_Ctrl_Pin, GPIO_PIN_RESET);

	loadController.setLoad(0);
	fanController.setSpeed(0);

	display.deinit();
	ina233.deinit();
	tc74.deinit();

	eeprom.write(applicationState);
}
