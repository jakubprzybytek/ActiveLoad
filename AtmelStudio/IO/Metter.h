/*
 * Metter.h
 *
 * Created: 2018-04-21 19:50:27
 *  Author: Rodos
 */ 


#ifndef METTER_H_
#define METTER_H_

#include "../Peripheral/ADC.h"

class Metter {

private:
	ADC adc;

public:
	uint16_t voltageValue;

public:
	void init();
	void start();

	void readVoltage();

};

#endif /* METTER_H_ */