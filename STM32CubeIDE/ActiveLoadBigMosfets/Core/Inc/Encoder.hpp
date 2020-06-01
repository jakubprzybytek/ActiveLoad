/*
 * Encoder.hpp
 *
 *  Created on: Jun 1, 2020
 *      Author: Chipotle
 */

#ifndef INC_ENCODER_HPP_
#define INC_ENCODER_HPP_

#include <stm32l1xx_hal.h>

class Encoder {

private:
	uint16_t value;
	uint16_t minValue;
	uint16_t maxValue;
	uint16_t step;

public:
	void reset(uint16_t value, uint16_t minValue, uint16_t maxValue, uint16_t step);
	uint16_t getValue();
	void up();
	void down();
};

#endif /* INC_ENCODER_HPP_ */
