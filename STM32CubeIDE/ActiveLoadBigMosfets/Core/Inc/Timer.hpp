/*
 * Timer.hpp
 *
 *  Created on: Jun 20, 2020
 *      Author: Chipotle
 */

#ifndef INC_TIMER_HPP_
#define INC_TIMER_HPP_

#include <stm32l1xx_hal.h>

class Timer {

public:
	uint8_t seconds;
	uint8_t minutes;
	uint8_t hours;

	void reset();
	void tick();

};

#endif /* INC_TIMER_HPP_ */
