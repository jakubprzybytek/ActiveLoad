/*
 * INA233.cpp
 *
 *  Created on: Apr 20, 2020
 *      Author: Chipotle
 */

#include <cmath>

#include "stm32l1xx_hal.h"

#include "devices/INA233.hpp"

using namespace std;

void INA233::init() {
	// averaging across 64 samples, sampling 2ms
	// total conversion time = 128ms
	uint16_t mfrAdcConfigValue = 0b0100000100100111 | (0b011 << 9) | (0b101 << 6) | (0b101 << 3);
	HAL_I2C_Mem_Write(this->hi2c, INA233_I2C_ADDRESS, INA233_COMMAND_MFR_ADC_CONFIG, 1, (uint8_t*) &mfrAdcConfigValue, 2, HAL_MAX_DELAY);

	// calibrate
	// Current_LSB = 0.25mA/bit -> calibration = 2048 (512 for 1mA/bit)
	// max readout = 32768 * 0.25mA = 8.192A
	uint16_t mfrCalibration = 2048;
	HAL_I2C_Mem_Write(this->hi2c, INA233_I2C_ADDRESS, INA233_COMMAND_MFR_CALIBRATION, 1, (uint8_t*) &mfrCalibration, 2, HAL_MAX_DELAY);
}

void INA233::deinit() {
	// power down
	uint16_t mfrAdcConfigValue = 0b0000000000000000;
	HAL_I2C_Mem_Write(this->hi2c, INA233_I2C_ADDRESS, INA233_COMMAND_MFR_ADC_CONFIG, 1, (uint8_t*) &mfrAdcConfigValue, 2, HAL_MAX_DELAY);
}

uint16_t INA233::readVoltage() {
	uint16_t voltageRaw;
	HAL_I2C_Mem_Read(this->hi2c, INA233_I2C_ADDRESS, INA233_COMMAND_READ_VIN, 1, (uint8_t*) &voltageRaw, 2, HAL_MAX_DELAY);
	return lround(voltageRaw * 1.25f); // Voltage_LSB = 1.25mV
}

uint16_t INA233::readCurrent() {
	uint16_t currentRaw;
	HAL_I2C_Mem_Read(this->hi2c, INA233_I2C_ADDRESS, INA233_COMMAND_READ_IIN, 1, (uint8_t*) &currentRaw, 2, HAL_MAX_DELAY);
	return lround(currentRaw * 0.25f); // Current_LSB = 0.25mA
}

uint32_t INA233::readPower() {
	uint16_t powerRaw;
	HAL_I2C_Mem_Read(this->hi2c, INA233_I2C_ADDRESS, INA233_COMMAND_READ_PIN, 1, (uint8_t*) &powerRaw, 2, HAL_MAX_DELAY);
	return lround(powerRaw * 6.25f); // Power_LSB = Current_LSB * 25
}
