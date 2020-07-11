/*
 * DebugLog.hpp
 *
 *  Created on: Jul 11, 2020
 *      Author: Chipotle
 */

#ifndef INC_DEBUGLOG_HPP_
#define INC_DEBUGLOG_HPP_

#include "stm32l1xx_hal.h"

#define MAX_LINES 5

class DebugLogger {

private:
	char lines[5][20];
	uint8_t currentLine;

public:
	void log(const char *format, ...);

	bool hasLineToConsume();
	char* consumeLine();
};

#endif /* INC_DEBUGLOG_HPP_ */
