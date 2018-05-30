/* 
* Screen.cpp
*
* Created: 2018-03-11 12:46:53
* Author: Rodos
*/

#include <stdio.h>
#include <string.h>

#include "Screen.h"
#include "Resources/font6x8.h"
#include "Resources/font12x16.h"

void Screen::drawTemperature(uint8_t temperature) {
	if (temperature != temperatureBuffer) {
		sprintf(textBuffer, "t=%dC", temperature);
		drawTextLine(7, textBuffer);
		temperatureBuffer = temperature;
	}
}

void Screen::drawVoltage(uint16_t voltage) {
	if (voltage != voltageBuffer) {
		sprintf(textBuffer, "Ui=%u.%uV", voltage / 10, voltage % 10);
		drawTextLine12x16(0, textBuffer);
		voltageBuffer = voltage;
	}
}

void Screen::drawCurrent(uint16_t current) {
	if (current != currentBuffer) {
		sprintf(textBuffer, "Ii=%u", current);
		drawTextLine12x16(2, textBuffer);
		currentBuffer = current;
	}
}

void Screen::drawDrainSetting(uint16_t drainSetting) {
	if (drainSetting != drainSettingBuffer) {
		sprintf(textBuffer, "drainDAC=%uC", drainSetting);
		drawTextLine(5, textBuffer);
		drainSettingBuffer = drainSetting;
	}
}

void Screen::drawFanSetting(uint16_t fanSetting) {
	if (fanSetting != fanSettingBuffer) {
		sprintf(textBuffer, "fanDAC=%uC", fanSetting);
		drawTextLine(4, textBuffer);
		fanSettingBuffer = fanSetting;
	}
}

void Screen::drawTextLine12x16(uint8_t lineNumber, const char * textLine) {
	sdd1306.setDrawingArea(0, 127, lineNumber, lineNumber + 1);

	uint16_t col = 0;
	const char * currentChar = textLine;
	while (*currentChar != '\0') {
		memcpy(buffer + col, font12x16[(uint8_t) *currentChar++ - 32], 12);
		col += 12;
	}
	memset(buffer + col, 0, 128 - col);
	col = 128;

	currentChar = textLine;
	while (*currentChar != '\0') {
		memcpy(buffer + col, font12x16[(uint8_t) *currentChar++ - 32] + 12, 12);
		col += 12;
	}
	memset(buffer + col, 0, 256 - col);

	sdd1306.sendFramebuffer(buffer, 256);
}

void Screen::drawTextLine(uint8_t lineNumber, const char * textLine) {
	sdd1306.setDrawingArea(0, 127, lineNumber, lineNumber);
	
	uint8_t col = 0;
	while (*textLine != '\0') {
		memcpy(buffer + col, font6x8[(uint8_t) *textLine++ - 32], 6);
		col += 6;
	}

	memset(buffer + col, 0, 128 - col);

	sdd1306.sendFramebuffer(buffer, 128);
}
