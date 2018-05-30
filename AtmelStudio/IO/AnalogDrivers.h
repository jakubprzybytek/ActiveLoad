/*
 * AnalogDrivers.h
 *
 * Created: 2018-05-30 23:47:33
 *  Author: Rodos
 */ 

#include "../Peripheral/DAC.h"

#ifndef ANALOGDRIVERS_H_
#define ANALOGDRIVERS_H_

class AnalogDrivers {

private:
	DAC dac;

public:
	void init();
	
	void setFan(uint16_t newValue);
	void setDrain(uint16_t newValue);
};

#endif /* ANALOGDRIVERS_H_ */