/*
 * Inputs.c
 *
 * Created: 2015-09-21 11:42:19
 *  Author: Rodos
 */ 

#include <avr/io.h>
#include <avr/sleep.h>

#include "Events.hpp"

void Events::setStatus(uint8_t newAction) {
	inputsStatus = newAction;
}

uint8_t Events::getStatus() {
	while (inputsStatus == Events::NO_ACTION) {
		SLEEP.CTRL = SLEEP_SMODE_IDLE_gc | SLEEP_SEN_bm;
		sleep_cpu();
		SLEEP.CTRL = SLEEP_SMODE_IDLE_gc;
	}

	uint8_t statusToReturn = inputsStatus;
	inputsStatus = Events::NO_ACTION;
	return statusToReturn;
}
