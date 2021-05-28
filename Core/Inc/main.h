/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
extern uint8_t for_x1_val, for_x2_val, for_x3_val, for_x4_val;
extern uint8_t beh_x1_val, beh_x2_val, beh_x3_val, beh_x4_val;
extern uint8_t left_x1_val, left_x2_val, left_x3_val, left_x4_val;
extern uint8_t right_x1_val, right_x2_val, right_x3_val, right_x4_val;
/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define beh_x1_Pin GPIO_PIN_8
#define beh_x1_GPIO_Port GPIOD
#define beh_x1_EXTI_IRQn EXTI9_5_IRQn
#define right_x1_Pin GPIO_PIN_9
#define right_x1_GPIO_Port GPIOD
#define right_x1_EXTI_IRQn EXTI9_5_IRQn
#define beh_x2_Pin GPIO_PIN_10
#define beh_x2_GPIO_Port GPIOD
#define beh_x2_EXTI_IRQn EXTI15_10_IRQn
#define right_x2_Pin GPIO_PIN_11
#define right_x2_GPIO_Port GPIOD
#define right_x2_EXTI_IRQn EXTI15_10_IRQn
#define beh_x3_Pin GPIO_PIN_12
#define beh_x3_GPIO_Port GPIOD
#define beh_x3_EXTI_IRQn EXTI15_10_IRQn
#define right_x3_Pin GPIO_PIN_13
#define right_x3_GPIO_Port GPIOD
#define right_x3_EXTI_IRQn EXTI15_10_IRQn
#define beh_x4_Pin GPIO_PIN_14
#define beh_x4_GPIO_Port GPIOD
#define beh_x4_EXTI_IRQn EXTI15_10_IRQn
#define right_x4_Pin GPIO_PIN_15
#define right_x4_GPIO_Port GPIOD
#define right_x4_EXTI_IRQn EXTI15_10_IRQn
#define for_x1_Pin GPIO_PIN_0
#define for_x1_GPIO_Port GPIOD
#define for_x1_EXTI_IRQn EXTI0_IRQn
#define left_x1_Pin GPIO_PIN_1
#define left_x1_GPIO_Port GPIOD
#define left_x1_EXTI_IRQn EXTI1_IRQn
#define for_x2_Pin GPIO_PIN_2
#define for_x2_GPIO_Port GPIOD
#define for_x2_EXTI_IRQn EXTI2_IRQn
#define left_x2_Pin GPIO_PIN_3
#define left_x2_GPIO_Port GPIOD
#define left_x2_EXTI_IRQn EXTI3_IRQn
#define for_x3_Pin GPIO_PIN_4
#define for_x3_GPIO_Port GPIOD
#define for_x3_EXTI_IRQn EXTI4_IRQn
#define left_x3_Pin GPIO_PIN_5
#define left_x3_GPIO_Port GPIOD
#define left_x3_EXTI_IRQn EXTI9_5_IRQn
#define for_x4_Pin GPIO_PIN_6
#define for_x4_GPIO_Port GPIOD
#define for_x4_EXTI_IRQn EXTI9_5_IRQn
#define left_x4_Pin GPIO_PIN_7
#define left_x4_GPIO_Port GPIOD
#define left_x4_EXTI_IRQn EXTI9_5_IRQn
#define K1_Pin GPIO_PIN_8
#define K1_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

#define backwalkToRaw 1
#define leftwalkToRaw 2
#define leftwalkRawToRoughMachine 3
#define forwalkRawToRoughMachine 4
#define stopwalkToGetRawMass1 5
#define stopwalkToPutRough1 6
#define leftwalkRawToSemiProcess 7
#define forwalkRawToSemiProcess 8
#define stopwalkToPutSemi1 9
#define leftwalkSemiToRaw5 10
#define counterclkRota 11
#define leftwalkSemiToRaw2 12
#define stopwalkToGetRawMass2 13

#define keyTostop 98

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
