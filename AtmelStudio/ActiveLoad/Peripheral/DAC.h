/*
 * DAC.h
 *
 * Created: 2018-05-30 23:18:55
 *  Author: Rodos
 */ 
#include <avr/io.h>

#ifndef DAC_H_
#define DAC_H_

class DAC {
	
public:
	void init();

	void sendToChannel0(uint16_t);
	void sendToChannel1(uint16_t);

private:
	uint8_t SP_ReadCalibrationByte(uint8_t index);
	void calibrate(DAC_t * adc);
};

#endif /* DAC_H_ */