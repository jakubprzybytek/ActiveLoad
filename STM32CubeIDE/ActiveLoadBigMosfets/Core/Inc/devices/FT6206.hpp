/*
 * FT6206.hpp
 *
 *  Created on: May 16, 2020
 *      Author: Chipotle
 */

#ifndef INC_DEVICES_FT6206_HPP_
#define INC_DEVICES_FT6206_HPP_

#define FT6206_I2C_ADDRESS 0b01110000

#define FT6206_COMMAND_TD_STATUS 0x02
#define FT6206_COMMAND_P1_XH 0x03

class FT6206 {

private:
	I2C_HandleTypeDef *hi2c;

public:
	FT6206(I2C_HandleTypeDef* hi2c) : hi2c(hi2c) {}

	void init();

	bool checkIfTouched();
	void getTouch(int32_t &x, int32_t &y);

};

#endif /* INC_DEVICES_FT6206_HPP_ */
