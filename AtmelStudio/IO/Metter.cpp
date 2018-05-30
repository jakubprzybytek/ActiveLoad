/*
 * Metter.cpp
 *
 * Created: 2018-04-21 19:51:25
 *  Author: Rodos
 */ 

#include "Metter.h"

#define VOLTAGE_FACTOR 6.49
#define CURRENT_FACTOR 1.6

void Metter::init() {
	adc.init();
	adc.setInput(ADC6);
}

void Metter::toggleInput() {
	voltageInput = !voltageInput;
	adc.setInput(voltageInput ? ADC6 : ADC7);
}

void Metter::start() {
	adc.start();
}

void Metter::storeReadout() {
	if (voltageInput) {
		voltageValue = adc.readCH0() / VOLTAGE_FACTOR;
	} else {
		currentValue = adc.readCH0() / CURRENT_FACTOR;
	}	
}
