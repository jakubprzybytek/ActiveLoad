#include "stm32l1xx_hal.h"

#include "devices/TC74.hpp"

void TC74::deinit() {
	uint8_t configValue = 1 << 7;
	HAL_I2C_Mem_Write(this->hi2c, TC74_I2C_ADDRESS, TC74_COMMAND_READ_WRITE_CONFIG, 1, (uint8_t*) &configValue, 1, HAL_MAX_DELAY);
}

int8_t TC74::readTemperature() {
	int8_t temperature;
	if (HAL_I2C_Mem_Read(this->hi2c, TC74_I2C_ADDRESS, TC74_COMMAND_READ_TEMPERATURE, 1, (uint8_t*) &temperature, 1, HAL_MAX_DELAY) != HAL_OK) {
		return -5;
	}
	return temperature;
}
