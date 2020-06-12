/*
 * LoadState.hpp
 *
 *  Created on: May 10, 2020
 *      Author: Chipotle
 */

#ifndef INC_APPLICATIONSTATE_HPP_
#define INC_APPLICATIONSTATE_HPP_

#include <stdio.h>
#include <stm32l1xx_hal.h>

class ApplicationState {

public:
	RTC_TimeTypeDef time;

	float voltageReadout;
	float currentReadout;
	float powerReadout;

	bool loadSinkEnabled = false;
	bool voltageLimitEnabled = false;
	float voltageLimit = 5.0;
	float currentLimit = 0.1;

	uint64_t chargeMiliAmpSeconds;
	float chargeAmpHours;
	uint64_t chargeMiliWattSeconds;
	float chargeWattHours;

	uint16_t loadLevel;

	int8_t temperature;
	uint8_t fanDutyCycleSetValue;
	uint8_t fanDutyCycle;
	uint16_t fanRPM;

	bool touched;
	int32_t touchX;
	int32_t touchY;

	bool currentLimitInEdit = true;
	bool fieldToEditChanged = false;
};

#endif /* INC_APPLICATIONSTATE_HPP_ */
