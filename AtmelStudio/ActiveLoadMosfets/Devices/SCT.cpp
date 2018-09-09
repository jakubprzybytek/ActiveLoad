/*
 * SCT.cpp
 *
 * Created: 2018-09-09 01:05:21
 *  Author: Rodos
 */ 

#include <avr/io.h>

#include "SCT.h"

void SCT::init() {
	PORTC.DIRSET = SCT_OUTPUT_ENABLE_PIN | SCT_LATCH_PIN | PIN4_bm | PIN5_bm | PIN7_bm;
	SPIC.INTCTRL = SPI_INTLVL_OFF_gc;
	SPIC.CTRL = SPI_ENABLE_bm | SPI_MASTER_bm | SPI_MODE_0_gc | SPI_PRESCALER_DIV128_gc;

	SCT_ENABLE_OUTPUT;
	SCT_LATCH_OFF;
}

void SCT::send(uint8_t first, uint8_t second) {
	SPIC.DATA = first;
	while (!(SPIC.STATUS & SPI_IF_bm));

	SPIC.DATA = second;
	while (!(SPIC.STATUS & SPI_IF_bm));
}

void SCT::latch() {
	SCT_LATCH_ON;
	SCT_LATCH_OFF;
}
