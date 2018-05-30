/*
 * AnalogDrivers.cpp
 *
 * Created: 2018-05-30 23:47:21
 *  Author: Rodos
 */ 

#include "AnalogDrivers.h"

void AnalogDrivers::init() {
	dac.init();
}

void AnalogDrivers::setFan(uint16_t newValue) {
	dac.sendToChannel0(newValue);
}

void AnalogDrivers::setDrain(uint16_t newValue) {
	dac.sendToChannel1(newValue);
}
