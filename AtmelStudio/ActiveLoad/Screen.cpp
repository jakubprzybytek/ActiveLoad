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

#define MAX_COLUMNS 128

void Screen::drawTemperature(uint8_t temperature) {
	if (temperature != temperatureBuffer) {
		sprintf(textBuffer, "              T=%d$C", temperature);
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
		sprintf(textBuffer, "Ii=%umA", current);
		drawTextLine12x16(2, textBuffer);
		currentBuffer = current;
	}
}

void Screen::drawDrainSetting(uint8_t drainSetting, bool highlight, bool forceDraw) {
	if (forceDraw || drainSetting != drainSettingBuffer) {

		if (drainSetting == 0) {
			sprintf(textBuffer, "Drain=off");
		} else {
			sprintf(textBuffer, "Drain=%u%%", drainSetting);
		}

		if (highlight) {
			drawTextLine12x16(4, textBuffer);
		} else {
			drawTextLine(4, textBuffer);
		}

		drainSettingBuffer = drainSetting;
	}
}

void Screen::drawFanSetting(uint8_t fanSetting, bool autoFan, bool highlight, bool forceDraw) {
	if (forceDraw || fanSetting != fanSettingBuffer) {

		if (fanSetting == 0) {
			sprintf(textBuffer, "Fan=off");
		} else {
			sprintf(textBuffer, "Fan=%u%%", fanSetting);
		}

		if (autoFan) {
			sprintf(textBuffer + strlen(textBuffer), " A");
		}

		if (highlight) {
			drawTextLine12x16(5, textBuffer);
		} else {
			drawTextLine(6, textBuffer);
		}

		fanSettingBuffer = fanSetting;
	}
}

void Screen::drawTextLine12x16(uint8_t lineNumber, const char * textLine) {
	sdd1306.setDrawingArea(0, 127, lineNumber, lineNumber + 1);

	uint16_t col = 0;
	const char * currentChar = textLine;
	while (*currentChar != '\0' && col < (MAX_COLUMNS - 12)) {
		memcpy(buffer + col, font12x16[(uint8_t) *currentChar++ - 32], 12);
		col += 12;
	}

	if (col < MAX_COLUMNS) {
		memset(buffer + col, 0, MAX_COLUMNS - col);
	}
	col = 128;

	currentChar = textLine;
	while (*currentChar != '\0' && col < (MAX_COLUMNS * 2 - 12)) {
		memcpy(buffer + col, font12x16[(uint8_t) *currentChar++ - 32] + 12, 12);
		col += 12;
	}

	if (col < (MAX_COLUMNS * 2)) {
		memset(buffer + col, 0, (MAX_COLUMNS * 2) - col);
	}

	sdd1306.sendFramebuffer(buffer, MAX_COLUMNS * 2);
}

void Screen::drawTextLine(uint8_t lineNumber, const char * textLine) {
	sdd1306.setDrawingArea(0, 127, lineNumber, lineNumber);
	
	uint8_t col = 0;
	while (*textLine != '\0' && col < (MAX_COLUMNS - 6)) {
		memcpy(buffer + col, font6x8[(uint8_t) *textLine++ - 32], 6);
		col += 6;
	}

	if (col < MAX_COLUMNS) {
		memset(buffer + col, 0, MAX_COLUMNS - col);
	}

	sdd1306.sendFramebuffer(buffer, MAX_COLUMNS);
}
