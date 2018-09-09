/*
 * SCT.h
 *
 * Created: 2018-09-09 01:05:12
 *  Author: Rodos
 */ 


#ifndef SCT_H_
#define SCT_H_

#include <avr/io.h>

#define SCT_OUTPUT_ENABLE_PIN PIN0_bm
#define SCT_LATCH_PIN PIN1_bm

#define SCT_ENABLE_OUTPUT	PORTC.OUTCLR = SCT_OUTPUT_ENABLE_PIN
#define SCT_LATCH_OFF		PORTC.OUTCLR = SCT_LATCH_PIN
#define SCT_LATCH_ON		PORTC.OUTSET = SCT_LATCH_PIN

class SCT {

public:
	void init();
	void send(uint8_t first, uint8_t second);
	void latch();
};

#endif /* SCT_H_ */