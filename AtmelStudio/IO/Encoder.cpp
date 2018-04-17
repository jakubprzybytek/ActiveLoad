/*
 * Encoder.cpp
 *
 * Created: 2017-06-01 20:10:56
 *  Author: Rodos
 */ 
#include <avr/io.h>

#include "Encoder.hpp"

void Encoder::Init() {
	// set up port pins
	PORTC.DIRCLR = PIN4_bm | PIN5_bm;
	PORTC.PIN4CTRL = PORT_ISC_LEVEL_gc | PORT_OPC_PULLUP_gc;
	PORTC.PIN5CTRL = PORT_ISC_LEVEL_gc | PORT_OPC_PULLUP_gc;
	
	// set up event channel
	EVSYS.CH0MUX = EVSYS_CHMUX_PORTC_PIN4_gc;
	EVSYS.CH0CTRL = EVSYS_QDEN_bm |	EVSYS_DIGFILT_8SAMPLES_gc;

	tc->CTRLA = TC_CLKSEL_EVCH0_gc;
	tc->CTRLD = TC_EVACT_QDEC_gc | TC_EVSEL_CH0_gc;
	InitTimer();
}

void Encoder::InitTimer() {
	// set up counter
	tc->INTCTRLB = TC_CCAINTLVL_LO_gc | TC_CCBINTLVL_LO_gc;
	tc->CCA = 7;
	tc->CNT = 8;
	tc->CCB = 9;
}
