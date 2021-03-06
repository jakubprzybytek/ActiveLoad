/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LoadLevel_Pin GPIO_PIN_4
#define LoadLevel_GPIO_Port GPIOA
#define Fan_PWM_Pin GPIO_PIN_5
#define Fan_PWM_GPIO_Port GPIOA
#define Encoder_A_Pin GPIO_PIN_6
#define Encoder_A_GPIO_Port GPIOA
#define Encoder_B_Pin GPIO_PIN_7
#define Encoder_B_GPIO_Port GPIOA
#define LED_Pin GPIO_PIN_12
#define LED_GPIO_Port GPIOB
#define Load_Op_Amps_Ctrl_Pin GPIO_PIN_13
#define Load_Op_Amps_Ctrl_GPIO_Port GPIOB
#define Fan_Power_Ctrl_Pin GPIO_PIN_14
#define Fan_Power_Ctrl_GPIO_Port GPIOB
#define Encoder_Switch_Pin GPIO_PIN_8
#define Encoder_Switch_GPIO_Port GPIOA
#define Encoder_Switch_EXTI_IRQn EXTI9_5_IRQn
#define TouchPad_Reset_Pin GPIO_PIN_10
#define TouchPad_Reset_GPIO_Port GPIOA
#define TouchPad_Interrupt_Pin GPIO_PIN_11
#define TouchPad_Interrupt_GPIO_Port GPIOA
#define TouchPad_Interrupt_EXTI_IRQn EXTI15_10_IRQn
#define Display_LED_Ctrl_Pin GPIO_PIN_12
#define Display_LED_Ctrl_GPIO_Port GPIOA
#define Display_Reset_Pin GPIO_PIN_15
#define Display_Reset_GPIO_Port GPIOA
#define Display_Read_Pin GPIO_PIN_5
#define Display_Read_GPIO_Port GPIOB
#define Display_Write_Pin GPIO_PIN_6
#define Display_Write_GPIO_Port GPIOB
#define Display_Data_Command_Pin GPIO_PIN_7
#define Display_Data_Command_GPIO_Port GPIOB
#define Display_Select_Pin GPIO_PIN_8
#define Display_Select_GPIO_Port GPIOB
#define Fan_Sensor_Pin GPIO_PIN_9
#define Fan_Sensor_GPIO_Port GPIOB
#define Fan_Sensor_EXTI_IRQn EXTI9_5_IRQn
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
