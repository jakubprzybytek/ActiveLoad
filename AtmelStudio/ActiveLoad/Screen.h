/* 
* Screen.h
*
* Created: 2018-03-11 12:46:53
* Author: Rodos
*/


#ifndef __SCREEN_H__
#define __SCREEN_H__

#include <avr/io.h>

#include "Devices/SSD1306.h"

class Screen {
private:
	SSD1306 sdd1306;

	uint8_t currentLineNumber;
	uint8_t buffer[256];
	char textBuffer[20];

	uint8_t temperatureBuffer;
	uint16_t voltageBuffer;
	uint16_t currentBuffer;
	uint16_t drainSettingBuffer;
	uint16_t fanSettingBuffer;

public:
	Screen() : currentLineNumber(0) {};

	void drawTemperature(uint8_t temperature);
	void drawVoltage(uint16_t voltage);
	void drawCurrent(uint16_t current);
	void drawDrainSetting(uint8_t drainSetting, bool highlight, bool forceDraw);
	void drawFanSetting(uint8_t fanSetting, bool autoFan, bool highlight, bool forceDraw);

	void drawTextLine(uint8_t lineNumber, const char * textLine);
	void drawTextLine12x16(uint8_t lineNumber, const char * textLine);
};

#endif //__SCREEN_H__
