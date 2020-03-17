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
#include "Tools/Switch.hpp"

#define LED_INIT	PORTC.DIRSET = PIN2_bm
#define LED_TOGGLE	PORTC.OUTTGL = PIN2_bm

InterruptSwitch button(&PORTC, PIN3_bm, &(PORTC.PIN3CTRL));	

Display display;
Metter metter;

bool displayPowerMode;

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

	if (displayPowerMode) {
		uint32_t power = ((uint32_t) metter.voltageValue) * metter.currentValue / 1000;
		display.setRightNumber(power % 1000);
	} else {
		display.setLeftNumber(metter.voltageValue % 1000);
		display.setRightNumber(metter.currentValue % 1000);
	}
}

/* *****************
 * Port C: Switch 0 int
 ***************** */
ISR (PORTC_INT_vect) {
	button.enableInterrupt();
	
	displayPowerMode = !displayPowerMode;

	if (displayPowerMode) {
		display.setLeftPO();
		display.setLeftDotPosition(DOT_POSITION_OFF);
		display.setRightDotPosition(DOT_POSITION_OFF);
	} else {
		display.setLeftDotPosition(1);
		display.setRightDotPosition(0);
	}
}

int main(void)
{
    LED_INIT;

	Timer displayTimer(&TCC5, 2);
	Timer adcTimer(&TCD5, 100);

	displayTimer.Init();
	adcTimer.Init();

	display.init(1, 0);

	button.init();

	// enable interrupts
	PMIC.CTRL = PMIC_HILVLEN_bm | PMIC_MEDLVLEN_bm | PMIC_LOLVLEN_bm;
	sei();

	displayTimer.Enable();

	for (uint16_t testValue = 0; testValue < 1000; testValue += 111) {
		display.setLeftNumber(testValue);
		display.setRightNumber(testValue);
		_delay_ms(75);
	}

	metter.init();

	adcTimer.Enable();

    while (1) {}
}


