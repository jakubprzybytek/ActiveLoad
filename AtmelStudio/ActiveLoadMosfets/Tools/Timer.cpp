/*
 * Switch.cpp
 *
 * Created: 2017-06-28 22:00:45
 *  Author: Rodos
 */ 
#include <avr/io.h>

#include "Timer.hpp"

void Timer::Init() {
	timer->PER = per;
	timer->INTCTRLA = TC_OVFINTLVL_MED_gc;
}

void Timer::Enable() {
	timer->CTRLA = TC_CLKSEL_DIV1024_gc;
	timer->INTFLAGS = TC5_OVFIF_bm;
}

void Timer::Disable() {
	timer->CTRLA = TC_CLKSEL_OFF_gc;
	timer->INTFLAGS = TC5_OVFIF_bm;
}
