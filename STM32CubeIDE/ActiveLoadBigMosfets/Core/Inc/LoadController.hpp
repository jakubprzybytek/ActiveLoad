/*
 * LoadController.hpp
 *
 *  Created on: May 15, 2020
 *      Author: Chipotle
 */

#ifndef INC_LOADCONTROLLER_HPP_
#define INC_LOADCONTROLLER_HPP_

#include "main.h"

class LoadController {

private:
	DAC_HandleTypeDef *hdac;
	bool enabled = false;

	void enable();
	void disable();

public:
	LoadController(DAC_HandleTypeDef *hdac) : hdac(hdac) {}

	void setLoad(uint16_t loadLevel);
};

#endif /* INC_LOADCONTROLLER_HPP_ */
