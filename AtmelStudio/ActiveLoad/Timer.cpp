/*
 * Switch.cpp
 *
 * Created: 2017-06-28 22:00:45
 *  Author: Rodos
 */ 
#include <avr/io.h>

#include "Timer.hpp"

void Timer::init() {
	timer->PER = per;
	timer->INTCTRLA = TC_OVFINTLVL_MED_gc;
}

void Timer::enable() {
	timer->CTRLA = TC_CLKSEL_DIV1024_gc;
}

void Timer::disable() {
	timer->CTRLA = TC_CLKSEL_OFF_gc;
}
