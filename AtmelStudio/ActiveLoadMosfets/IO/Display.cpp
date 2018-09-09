/*
 * Display.cpp
 *
 * Created: 2018-09-09 01:30:37
 *  Author: Rodos
 */ 

#include "Display.h"

uint8_t leftDigitPatterns[] = {95, 65, 157, 217, 195, 218, 222, 73, 223, 219, 0};

uint8_t rightDigitPatterns[] = {219, 24, 179, 186, 122, 234, 235, 152, 251, 250, 0};

void Display::init() {
	sct.init();
	DIGITS_INIT;
}

void Display::drawNextColumn() {
	currentColumn = (currentColumn + 1) % 3;

	sct.send(rightDigitPatterns[rightDigits[currentColumn]], leftDigitPatterns[leftDigits[currentColumn]]);
	
	DIGITS_OFF;

	sct.latch();

	switch (currentColumn) {
		case 0 :
			DIGIT1_ON;
			break;
		case 1 :
			DIGIT2_ON;
			break;
		case 2 :
			DIGIT3_ON;
			break;
	}
}

void Display::setLeftNumber(uint16_t value) {
	leftDigits[2] = value % 10;
	value /= 10;
	leftDigits[1] = value % 10;
	value /= 10;
	leftDigits[0] = value % 10;
}

void Display::setRightNumber(uint16_t value) {
	rightDigits[2] = value % 10;
	value /= 10;
	rightDigits[1] = value % 10;
	value /= 10;
	rightDigits[0] = value % 10;
}
