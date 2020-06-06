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
	uint16_t mfrAdcCondigValue = 0b0100000100100111 | (0b100 << 9); // averaging across 128 samples
	HAL_I2C_Mem_Write(this->hi2c, INA233_I2C_ADDRESS, INA233_COMMAND_MFR_ADC_CONFIG, 1, (uint8_t*) &mfrAdcCondigValue, 2, HAL_MAX_DELAY);

	// calibrate
	// Current_LSB = 0.25mA/bit -> calibration = 2048 (512 for 1mA/bit)
	// max readout = 32768 * 0.25mA = 8.192A
	uint16_t mfrCalibration = 2048;
	HAL_I2C_Mem_Write(this->hi2c, INA233_I2C_ADDRESS, INA233_COMMAND_MFR_CALIBRATION, 1, (uint8_t*) &mfrCalibration, 2, HAL_MAX_DELAY);
}

float INA233::readVoltage() {
	uint16_t voltageRaw;
	HAL_I2C_Mem_Read(this->hi2c, INA233_I2C_ADDRESS, INA233_COMMAND_READ_VIN, 1, (uint8_t*) &voltageRaw, 2, HAL_MAX_DELAY);
	return (float) voltageRaw * 0.00125f;
}

float INA233::readCurrent() {
	uint16_t currentRaw;
	HAL_I2C_Mem_Read(this->hi2c, INA233_I2C_ADDRESS, INA233_COMMAND_READ_IIN, 1, (uint8_t*) &currentRaw, 2, HAL_MAX_DELAY);
	return (float) currentRaw * 0.00025f; // Current_LSB
}

float INA233::readPower() {
	uint16_t powerRaw;
	HAL_I2C_Mem_Read(this->hi2c, INA233_I2C_ADDRESS, INA233_COMMAND_READ_PIN, 1, (uint8_t*) &powerRaw, 2, HAL_MAX_DELAY);
	return (float) powerRaw * 0.00625f; // Power_LSB = Current_LSB * 25
}
