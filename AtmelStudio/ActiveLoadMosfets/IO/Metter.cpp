/*
 * Metter.cpp
 *
 * Created: 2018-04-21 19:51:25
 *  Author: Rodos
 */ 

#include "Metter.h"

#define VOLTAGE_A_FACTOR 0.10388
#define VOLTAGE_B_FACTOR -18.028
#define CURRENT_A_FACTOR 0.237886
#define CURRENT_B_FACTOR -36.769

void Metter::init() {
	adc.init();
	adc.setInput(ADC11);
}

void Metter::toggleInput() {
	voltageInput = !voltageInput;
	adc.setInput(voltageInput ? ADC11 : ADC12);
}

void Metter::start() {
	adc.start();
}

void Metter::storeReadout() {
	if (voltageInput) {
		voltageValue = adc.readCH0() * VOLTAGE_A_FACTOR + VOLTAGE_B_FACTOR;
	} else {
		currentValue = adc.readCH0() * CURRENT_A_FACTOR + CURRENT_B_FACTOR;
	}	
}
