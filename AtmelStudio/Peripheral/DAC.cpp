/*
 * DAC.cpp
 *
 * Created: 2018-05-30 23:18:46
 *  Author: Rodos
 */ 
#include <avr/pgmspace.h>

#include "DAC.h"

void DAC::init() {
	PORTA.DIRSET = PIN2_bm | PIN3_bm;

	DACA.CTRLB = DAC_CHSEL_DUAL_gc;
	DACA.CTRLC = DAC_REFSEL_INT1V_gc;
	DACA.CTRLA = DAC_CH0EN_bm | DAC_CH1EN_bm | DAC_ENABLE_bm;

	calibrate(&DACA);
}

uint8_t DAC::SP_ReadCalibrationByte(uint8_t index) {
	uint8_t result;

	/* Load the NVM Command register to read the calibration row. */
	NVM_CMD = NVM_CMD_READ_CALIB_ROW_gc;
	result = pgm_read_byte(index);

	/* Clean up NVM Command register. */
	NVM_CMD = NVM_CMD_NO_OPERATION_gc;

	return result;
}

void DAC::calibrate(DAC_t * dac) {
	dac->CH0OFFSETCAL = SP_ReadCalibrationByte(PRODSIGNATURES_DACA0OFFCAL);
	dac->CH1OFFSETCAL = SP_ReadCalibrationByte(PRODSIGNATURES_DACA1OFFCAL);
	dac->CH0GAINCAL = SP_ReadCalibrationByte(PRODSIGNATURES_DACA0GAINCAL);
	dac->CH1GAINCAL = SP_ReadCalibrationByte(PRODSIGNATURES_DACA1GAINCAL);
}

void DAC::sendToChannel0(uint16_t newValue) {
	while ((DACA.STATUS & DAC_CH0DRE_bm) == false);
	DACA.CH0DATA = newValue;
}

void DAC::sendToChannel1(uint16_t newValue) {
	while ((DACA.STATUS & DAC_CH1DRE_bm) == false);
	DACA.CH1DATA = newValue;
}
