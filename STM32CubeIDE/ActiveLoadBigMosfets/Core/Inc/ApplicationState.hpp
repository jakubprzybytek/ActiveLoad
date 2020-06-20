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

	uint16_t voltageReadout; // mV
	uint16_t currentReadout; // mA
	uint32_t powerReadout;   // mW

	bool loadSinkEnabled = false;
	bool voltageLimitEnabled = false;
	uint16_t voltageLimit = 5000; // mV
	uint16_t currentLimit = 100; // mA

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
