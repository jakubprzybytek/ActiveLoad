/*
 * TC74.hpp
 *
 *  Created on: May 10, 2020
 *      Author: Chipotle
 */

#ifndef INC_DEVICES_TC74_HPP_
#define INC_DEVICES_TC74_HPP_

#define TC74_I2C_ADDRESS 0b10010000

#define TC74_COMMAND_READ_TEMPERATURE  0x00
#define TC74_COMMAND_READ_WRITE_CONFIG 0x01

class TC74 {

private:
	I2C_HandleTypeDef *hi2c;

public:
	TC74(I2C_HandleTypeDef* hi2c) : hi2c(hi2c) {}

	void init();
	void deinit();

	int8_t readTemperature();
};

#endif /* INC_DEVICES_TC74_HPP_ */
