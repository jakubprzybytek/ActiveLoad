/*
 * Inputs.h
 *
 * Created: 2015-09-21 11:37:48
 *  Author: Rodos
 */ 

#ifndef EVENTS_H_
#define EVENTS_H_

class Events {

public:
	static const uint8_t NO_ACTION = 0x00;

	static const uint8_t ENCODER_LEFT = 0x03;
	static const uint8_t ENCODER_RIGHT = 0x04;
	static const uint8_t ENCODER_PRESSED = 0x05;

	static const uint8_t TIMER_DOWN = 0x10;

private:
	uint8_t inputsStatus;

public:
	Events() : inputsStatus(NO_ACTION) {}

	void setStatus(uint8_t newAction);
	uint8_t getStatus();

};

#endif /* EVENTS_H_ */
