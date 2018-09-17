/*
 * ActiveLoadMosfets.cpp
 *
 * Created: 2018-09-08 11:48:31
 * Author : Rodos
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "IO/Display.h"
#include "IO/Metter.h"

#include "Tools/Timer.hpp"

#define LED_INIT	PORTC.DIRSET = PIN2_bm
#define LED_TOGGLE	PORTC.OUTTGL = PIN2_bm

Display display;
Metter metter;

/* *****************
 * TCC5: Display refresh timer interrupt
 ***************** */
ISR (TCC5_OVF_vect) {
	TCC5.INTFLAGS = TC5_OVFIF_bm;
	display.drawNextColumn();
}

/* *****************
 * TCD5: ADC conversion trigger timer interrupt
 ***************** */
ISR (TCD5_OVF_vect) {
	TCD5.INTFLAGS = TC5_OVFIF_bm;

	metter.toggleInput();
	metter.start();

	LED_TOGGLE;
}

/* *****************
 * ADCA: Conversion Complete interrupt
 ***************** */
ISR (ADCA_CH0_vect) {
	metter.storeReadout();

	uint16_t readout = metter.currentValue;
	display.setLeftNumber(readout / 1000);
	display.setRightNumber(readout % 1000); 
}

int main(void)
{
    LED_INIT;

	Timer displayTimer(&TCC5, 2);
	Timer adcTimer(&TCD5, 400);

	displayTimer.Init();
	adcTimer.Init();

	display.init();

	// enable interrupts
	PMIC.CTRL = PMIC_HILVLEN_bm | PMIC_MEDLVLEN_bm;
	sei();

	displayTimer.Enable();

	display.setLeftNumber(12);
	display.setRightNumber(12);
	_delay_ms(200);

	display.setLeftNumber(234);
	display.setRightNumber(234);
	_delay_ms(200);

	display.setLeftNumber(456);
	display.setRightNumber(456);
	_delay_ms(200);

	display.setLeftNumber(789);
	display.setRightNumber(789);
	_delay_ms(200);

	metter.init();

	adcTimer.Enable();

    while (1) {}
}


