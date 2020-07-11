/*
 * DebugLog.cpp
 *
 *  Created on: Jul 11, 2020
 *      Author: Chipotle
 */

#include "DebugLogger.hpp"

#include <cstdio>
#include <stdarg.h>

void DebugLogger::log(const char *format, ...) {

	if (currentLine < MAX_LINES) {
		va_list args;
		va_start(args, format);
		vsprintf(lines[this->currentLine++], format, args);
		va_end(args);
	}

}

bool DebugLogger::hasLineToConsume() {
	return this->currentLine > 0;
}

char* DebugLogger::consumeLine() {
	return this->lines[--this->currentLine];
}
