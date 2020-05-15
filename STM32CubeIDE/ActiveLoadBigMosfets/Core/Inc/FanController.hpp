/*
 * FanController.hpp
 *
 *  Created on: May 15, 2020
 *      Author: Chipotle
 */

#ifndef INC_FANCONTROLLER_HPP_
#define INC_FANCONTROLLER_HPP_

#include "main.h"

class FanController {

private:
	TIM_HandleTypeDef *htim;
	bool running = false;

	void startFan();
	void stopFan();

public:
	FanController(TIM_HandleTypeDef *htim) : htim (htim) {}

	void setSpeed(uint8_t dutyCycle);

};

#endif /* INC_FANCONTROLLER_HPP_ */
