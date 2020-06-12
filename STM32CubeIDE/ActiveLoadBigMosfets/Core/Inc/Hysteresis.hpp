/*
 * Hysteresis.hpp
 *
 *  Created on: Jun 12, 2020
 *      Author: Chipotle
 */

#ifndef INC_HYSTERESIS_HPP_
#define INC_HYSTERESIS_HPP_

#include "stm32l1xx_hal.h"

class Hysteresis {

private:
	uint8_t hysteresis;

	uint8_t previouslyReturnedValue;

	uint8_t lowLimit;
	uint8_t highLimit;

public:
	Hysteresis(uint8_t hysteresis, uint8_t initValue, uint8_t initLowLimit, uint8_t initHighLimit) : hysteresis(hysteresis), previouslyReturnedValue(initValue), lowLimit(
			initLowLimit), highLimit(initHighLimit) {
	}

	uint8_t update(uint8_t newSetValue);

};

#endif /* INC_HYSTERESIS_HPP_ */
