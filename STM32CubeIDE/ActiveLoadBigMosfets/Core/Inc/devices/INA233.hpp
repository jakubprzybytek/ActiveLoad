/*
 * INA233.hpp
 *
 *  Created on: Apr 20, 2020
 *      Author: Chipotle
 */

#ifndef INC_DEVICES_INA233_HPP_
#define INC_DEVICES_INA233_HPP_

#define INA233_I2C_ADDRESS 0b10000000

#define INA233_COMMAND_READ_VIN 0x88
#define INA233_COMMAND_READ_IIN 0x89
#define INA233_COMMAND_MFR_ADC_CONFIG 0xd0
#define INA233_COMMAND_MFR_CALIBRATION 0xd4

class INA233 {

private:
	I2C_HandleTypeDef *hi2c;

public:
	INA233(I2C_HandleTypeDef* hi2c) : hi2c(hi2c) {}

	void init();
	double readVoltage();
	double readCurrent();
};

#endif /* INC_DEVICES_INA233_HPP_ */