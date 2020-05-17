/**
 ******************************************************************************
 * File Name          : STM32TouchController.cpp
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under Ultimate Liberty license
 * SLA0044, the "License"; You may not use this file except in compliance with
 * the License. You may obtain a copy of the License at:
 *                             www.st.com/SLA0044
 *
 ******************************************************************************
 */

/* USER CODE BEGIN STM32TouchController */

#include "stm32l1xx.h"
#include <STM32TouchController.hpp>

#include "ApplicationState.hpp"

extern ApplicationState applicationState;

void STM32TouchController::init() {
}

bool STM32TouchController::sampleTouch(int32_t &x, int32_t &y) {

	if (applicationState.touched) {
		x = applicationState.touchX;
		y = applicationState.touchY;
		return true;
	}

	return false;
}

/* USER CODE END STM32TouchController */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
