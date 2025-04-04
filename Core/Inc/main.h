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
#include "stm32f7xx_hal.h"

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

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);
void MX_I2C4_Init(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define TEST_LED_Pin GPIO_PIN_13
#define TEST_LED_GPIO_Port GPIOJ
#define DSI_RESET_Pin GPIO_PIN_15
#define DSI_RESET_GPIO_Port GPIOJ
#define RENDER_TIME_Pin GPIO_PIN_7
#define RENDER_TIME_GPIO_Port GPIOC
#define VSYNC_FREQ_Pin GPIO_PIN_6
#define VSYNC_FREQ_GPIO_Port GPIOC
#define MCU_ACTIVE_Pin GPIO_PIN_6
#define MCU_ACTIVE_GPIO_Port GPIOF
#define FRAME_SYNC_Pin GPIO_PIN_10
#define FRAME_SYNC_GPIO_Port GPIOF
#define FRAME_SYNC_EXTI_IRQn EXTI15_10_IRQn
#define SYNC_Pin GPIO_PIN_9
#define SYNC_GPIO_Port GPIOF
#define PIXEL_SYNC_Pin GPIO_PIN_8
#define PIXEL_SYNC_GPIO_Port GPIOF
#define PIXEL_SYNC_EXTI_IRQn EXTI9_5_IRQn
#define TEST_LED_2_Pin GPIO_PIN_5
#define TEST_LED_2_GPIO_Port GPIOJ
#define USER_GPIO_Pin GPIO_PIN_0
#define USER_GPIO_GPIO_Port GPIOA
#define FRAME_RATE_Pin GPIO_PIN_1
#define FRAME_RATE_GPIO_Port GPIOJ

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
