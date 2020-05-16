#include "main.h"

#include "devices/FT6206.hpp"

void FT6206::init() {
	HAL_GPIO_WritePin(TouchPad_Reset_GPIO_Port, TouchPad_Reset_Pin, GPIO_PIN_SET);
	HAL_Delay(10);

	uint8_t mfrCalibration = 0;
	HAL_I2C_Mem_Write(this->hi2c, 0x38 * 2, 0x86, 1, &mfrCalibration, 1, HAL_MAX_DELAY);
	mfrCalibration = 1;
	HAL_I2C_Mem_Write(this->hi2c, 0x38 * 2, 0xa4, 1, &mfrCalibration, 1, HAL_MAX_DELAY);
}

bool FT6206::checkIfTouched() {
	uint8_t buffor;
	HAL_I2C_Mem_Read(this->hi2c, FT6206_I2C_ADDRESS, FT6206_COMMAND_TD_STATUS, 1, &buffor, 1, HAL_MAX_DELAY);
	return buffor > 0 && buffor < 2;
}

uint16_t FT6206::getTouch() {
	uint8_t buffer[2];
	HAL_I2C_Mem_Read(this->hi2c, FT6206_I2C_ADDRESS, FT6206_COMMAND_P1_XH, 1, buffer, 2, HAL_MAX_DELAY);
	return (buffer[0] & 0b00111111) << 8 | buffer[1];
}
