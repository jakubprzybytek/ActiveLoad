/*
 * INA233.cpp
 *
 *  Created on: Apr 20, 2020
 *      Author: Chipotle
 */

#include "stm32l1xx_hal.h"

#include "devices/INA233.hpp"

void INA233::init() {
	// set up averaging
	uint16_t mfrAdcCondigValue = 0b0100101100100111; // averaging across 256 samples
	HAL_I2C_Mem_Write(this->hi2c, INA233_I2C_ADDRESS, INA233_COMMAND_MFR_ADC_CONFIG, 1, (uint8_t*) &mfrAdcCondigValue, 2, HAL_MAX_DELAY);

	// calibrate
	uint16_t mfrCalibration = 512; // Current_LSB = 1mA/bit -> calibration = 512
	HAL_I2C_Mem_Write(this->hi2c, INA233_I2C_ADDRESS, INA233_COMMAND_MFR_CALIBRATION, 1, (uint8_t*) &mfrCalibration, 2, HAL_MAX_DELAY);
}

double INA233::readVoltage() {
	uint16_t voltageRaw;
	HAL_I2C_Mem_Read(this->hi2c, INA233_I2C_ADDRESS, INA233_COMMAND_READ_VIN, 1, (uint8_t*) &voltageRaw, 2, HAL_MAX_DELAY);
	return (double) voltageRaw * 0.00125;
}

double INA233::readCurrent() {
	uint16_t currentRaw;
	HAL_I2C_Mem_Read(this->hi2c, INA233_I2C_ADDRESS, INA233_COMMAND_READ_IIN, 1, (uint8_t*) &currentRaw, 2, HAL_MAX_DELAY);
	return (double) currentRaw * 0.001;
}
