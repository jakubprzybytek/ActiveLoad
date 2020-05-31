/*
 * FanController.cpp
 *
 *  Created on: May 15, 2020
 *      Author: Chipotle
 */

#include "FanController.hpp"

void FanController::startFan() {
	HAL_TIM_PWM_Start(htim, TIM_CHANNEL_1);
	HAL_GPIO_WritePin(Fan_Power_Ctrl_GPIO_Port, Fan_Power_Ctrl_Pin, GPIO_PIN_SET);

	this->running = true;
}

void FanController::stopFan() {
	HAL_GPIO_WritePin(Fan_Power_Ctrl_GPIO_Port, Fan_Power_Ctrl_Pin, GPIO_PIN_RESET);
	HAL_TIM_PWM_Stop(htim, TIM_CHANNEL_1);

	this->running = false;
}

void FanController::setSpeed(uint8_t dutyCycle) {

	if (dutyCycle > 70) {
		dutyCycle = 70;
	}

	if (dutyCycle == 0 && running == true) {
		stopFan();
	}

	TIM2->CCR1 = 31 * (dutyCycle <= 100 ? dutyCycle : 100) / 100;

	if (dutyCycle > 0 && running == false) {
		startFan();
	}
}
