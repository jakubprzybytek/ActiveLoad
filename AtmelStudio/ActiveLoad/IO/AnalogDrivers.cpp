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

void AnalogDrivers::setFan(uint8_t fanPercentage) {
	dac.sendToChannel0(fanPercentage == 0 ? 0 : FAN_DAC_MIN + fanPercentage * FAN_DAC_PERCENTILE_SIZE);
}

void AnalogDrivers::setDrain(uint8_t drainPercentage) {
	dac.sendToChannel1(drainPercentage == 0 ? 0 : DRAIN_DAC_MIN + drainPercentage * DRAIN_DAC_PERCENTILE_SIZE);
}
