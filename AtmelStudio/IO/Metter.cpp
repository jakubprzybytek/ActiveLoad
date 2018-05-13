/*
 * Metter.cpp
 *
 * Created: 2018-04-21 19:51:25
 *  Author: Rodos
 */ 

#include "Metter.h"

#define VOLTAGE_FACTOR 6.6

void Metter::init() {
	adc.init();	
}

void Metter::start() {
	adc.start();
}

void Metter::readVoltage() {
	voltageValue = adc.readCH0() / VOLTAGE_FACTOR;
}
