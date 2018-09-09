/*
 * ActiveLoadMosfets.cpp
 *
 * Created: 2018-09-08 11:48:31
 * Author : Rodos
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "Peripheral/ADC.h"

#include "IO/Display.h"

#include "Tools/Timer.hpp"

#define LED_INIT	PORTC.DIRSET = PIN2_bm
#define LED_TOGGLE	PORTC.OUTTGL = PIN2_bm

ADC adc;
Display display;

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
	adc.setInput(ADC11);
	adc.start();
	LED_TOGGLE;
}

/* *****************
 * ADCA: Conversion Complete interrupt
 ***************** */
ISR (ADCA_CH0_vect) {
 	uint16_t a = adc.readCH0();
	 
}

int main(void)
{
    LED_INIT;

	Timer displayTimer(&TCC5, 2);
	Timer adcTimer(&TCD5, 200);

	display.init();

	displayTimer.Init();
	adcTimer.Init();

	adc.init();

	adc.setInput(ADC11);
	adc.start();

	// enable interrupts
	PMIC.CTRL = PMIC_HILVLEN_bm | PMIC_MEDLVLEN_bm | PMIC_LOLVLEN_bm;
	sei();

	displayTimer.Enable();
	adcTimer.Enable();

	display.setLeftNumber(12);
	display.setRightNumber(12);
	_delay_ms(200);

	display.setLeftNumber(345);
	display.setRightNumber(345);
	_delay_ms(200);

	display.setLeftNumber(678);
	display.setRightNumber(678);
	_delay_ms(200);

	display.setLeftNumber(990);
	display.setRightNumber(990);
	_delay_ms(200);

    while (1) {}
}


