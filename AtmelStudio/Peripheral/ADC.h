/*
 * ADC.h
 *
 * Created: 2018-04-21 19:45:22
 *  Author: Rodos
 */ 

#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>

class ADC {
	
public:
	void init();
	void start();

	uint16_t readCH0();
};

#endif /* ADC_H_ */