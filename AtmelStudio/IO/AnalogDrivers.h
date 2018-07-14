/*
 * AnalogDrivers.h
 *
 * Created: 2018-05-30 23:47:33
 *  Author: Rodos
 */ 

#include "../Peripheral/DAC.h"

#ifndef ANALOGDRIVERS_H_
#define ANALOGDRIVERS_H_

#define DRAIN_DAC_MIN 2100
#define DRAIN_DAC_MAX 4095
#define DRAIN_DAC_PERCENTILE_SIZE (uint16_t)((FAN_DAC_MAX - FAN_DAC_MIN) / 100)

#define FAN_DAC_MIN 1795
#define FAN_DAC_MAX 4095
#define FAN_DAC_PERCENTILE_SIZE (uint16_t)((FAN_DAC_MAX - FAN_DAC_MIN) / 100)

class AnalogDrivers {

private:
	DAC dac;

public:
	void init();
	
	void setFan(uint8_t fanPercentage);
	void setDrain(uint8_t drainPercentage);
};

#endif /* ANALOGDRIVERS_H_ */