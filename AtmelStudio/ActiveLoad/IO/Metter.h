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
	bool voltageInput;

	uint16_t voltageValue;
	uint16_t currentValue;

public:
	void init();

	void toggleInput();
	void start();

	void storeReadout();

};

#endif /* METTER_H_ */