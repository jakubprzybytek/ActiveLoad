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

	float voltage;
	float current;

	int8_t temperature;
	uint8_t fanDutyCycle;
	uint16_t fanRPM;
};

#endif /* INC_APPLICATIONSTATE_HPP_ */
