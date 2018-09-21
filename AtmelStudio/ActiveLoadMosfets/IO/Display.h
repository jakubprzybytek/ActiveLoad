/*
 * Display.h
 *
 * Created: 2018-09-09 01:30:25
 *  Author: Rodos
 */ 


#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "../Devices/SCT.h"

#define DIGITS_INIT	PORTA.DIRSET = PIN5_bm | PIN6_bm | PIN7_bm
#define DIGITS_OFF	PORTA.OUTSET = PIN5_bm | PIN6_bm | PIN7_bm
#define DIGIT1_ON	PORTA.OUTCLR = PIN5_bm
#define DIGIT2_ON	PORTA.OUTCLR = PIN6_bm
#define DIGIT3_ON	PORTA.OUTCLR = PIN7_bm

class Display {

private:
	SCT sct;
	uint8_t currentColumn;

	uint8_t leftDotPosition;
	uint8_t rightDotPosition;

	uint8_t leftDigits[3];
	uint8_t rightDigits[3];

public:
	void init();
	void drawNextColumn();

	void setLeftNumber(uint16_t value);
	void setRightNumber(uint16_t value);
};

#endif /* DISPLAY_H_ */