/*
 * Display.cpp
 *
 * Created: 2018-09-09 01:30:37
 *  Author: Rodos
 */ 

#include "Display.h"

uint8_t leftDigitPatterns[] = {95, 65, 157, 217, 195, 218, 222, 73, 223, 219, 32, 0};

uint8_t rightDigitPatterns[] = {219, 24, 179, 186, 120, 234, 235, 152, 251, 250, 4, 0};

void Display::init(uint8_t leftDotPosition, uint8_t rightDotPosition) {
	sct.init();
	DIGITS_INIT;

	this->leftDotPosition = leftDotPosition;
	this->rightDotPosition = rightDotPosition;
}

void Display::drawNextColumn() {
	currentColumn = (currentColumn + 1) % 3;

	uint8_t rightDigitPattern = rightDigits[currentColumn] + (currentColumn == rightDotPosition ? rightDigitPatterns[10] : 0);
	uint8_t leftDigitPattern = leftDigits[currentColumn] + (currentColumn == leftDotPosition ? leftDigitPatterns[10] : 0);

	sct.send(rightDigitPattern, leftDigitPattern);
	
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
	leftDigits[2] = leftDigitPatterns[value % 10];
	value /= 10;
	leftDigits[1] = leftDigitPatterns[value % 10];
	value /= 10;
	leftDigits[0] = leftDigitPatterns[value % 10];
}

void Display::setRightNumber(uint16_t value) {
	rightDigits[2] = rightDigitPatterns[value % 10];
	value /= 10;
	rightDigits[1] = rightDigitPatterns[value % 10];
	value /= 10;
	rightDigits[0] = rightDigitPatterns[value % 10];
}

void Display::setLeftPO() {
	leftDigits[0] = 159 - 16;
	leftDigits[1] = 212;
	leftDigits[2] = 0;
}

void Display::setRightDotPosition(uint8_t value) {
	this->rightDotPosition = value;
}

void Display::setLeftDotPosition(uint8_t value) {
	this->leftDotPosition = value;
}
