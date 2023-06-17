/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dcmi.h"
#include "dma.h"
#include "dma2d.h"
#include "ltdc.h"
#include "rtc.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include "retarget.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
#define OV5640_address 0x78

__IO uint32_t camera_frame_ready = 0;
//image buffer
uint8_t buffer[480*272*3] = {0};
uint32_t buffer2d[480*272]={0};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_USART1_UART_Init();
  MX_DMA2D_Init();
  MX_LTDC_Init();
  MX_DCMI_Init();
  MX_RTC_Init();
  /* USER CODE BEGIN 2 */
  RetargetInit(&huart1);

  printf("BUFFER RANDOM VALUE BEFORE CAPTURE: %d\n", buffer[5640]);
  //camera init
  BSP_CAMERA_PwrDown(0);

  if(BSP_CAMERA_Init(0, CAMERA_R480x272, CAMERA_PF_RGB565) != BSP_ERROR_NONE){
	  Error_Handler();
  }

  HAL_Delay(1000);
//  buffer[5460] = 255;
  LTDC_Init_from_buffer(buffer2d);


//  o Call BSP_CAMERA_SetLightMode()/BSP_CAMERA_GetLightMode() to set/get the camera light mode
//         LightMode: - CAMERA_LIGHT_AUTO
//                    - CAMERA_LIGHT_SUNNY
//                    - CAMERA_LIGHT_OFFICE
//                    - CAMERA_LIGHT_HOME
//                    - CAMERA_LIGHT_CLOUDY
//
//       o Call BSP_CAMERA_SetColorEffect()/BSP_CAMERA_GetColorEffect() to set/get the camera color effects
//         Effect: - CAMERA_COLOR_EFFECT_NONE
//                 - CAMERA_COLOR_EFFECT_BLUE
//                 - CAMERA_COLOR_EFFECT_RED
//                 - CAMERA_COLOR_EFFECT_GREEN
//                 - CAMERA_COLOR_EFFECT_BW
//                 - CAMERA_COLOR_EFFECT_SEPIA
//                 - CAMERA_COLOR_EFFECT_NEGATIVE
//
//      o Call BSP_CAMERA_SetBrightness()/BSP_CAMERA_GetBrightness() to set/get the camera Brightness
//        Brightness is value between -4(Level 4 negative) and 4(Level 4 positive).
//
//      o Call BSP_CAMERA_SetSaturation()/BSP_CAMERA_GetSaturation() to set/get the camera Saturation
//        Saturation is value between -4(Level 4 negative) and 4(Level 4 positive).
//
//      o Call BSP_CAMERA_SetContrast()/BSP_CAMERA_GetContrast() to set/get the camera Contrast
//        Contrast is value between -4(Level 4 negative) and 4(Level 4 positive).
//
//      o Call BSP_CAMERA_SetHueDegree()/BSP_CAMERA_GetHueDegree() to set/get the camera Hue Degree
//        HueDegree is value between -4(180 degree negative) and 4(150 degree positive).
//	BSP_CAMERA_SetLightMode(0, CAMERA_LIGHT_HOME);
//	BSP_CAMERA_SetColorEffect(0, CAMERA_COLOR_EFFECT_NONE);


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  printf("Printing photo 1");
  HAL_GPIO_WritePin(USER_LED1_GPIO_Port, USER_LED1_Pin, GPIO_PIN_SET);
  BSP_CAMERA_Start(0, (uint8_t*)buffer, CAMERA_MODE_SNAPSHOT);
  BSP_CAMERA_Stop(0);
  HAL_GPIO_WritePin(USER_LED1_GPIO_Port, USER_LED1_Pin, GPIO_PIN_RESET);

  while (1)
  {
	HAL_GPIO_TogglePin(USER_LED1_GPIO_Port, USER_LED1_Pin);
	printf("siema");
	HAL_Delay(1000);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /*AXI clock gating */
  RCC->CKGAENR = 0xFFFFFFFF;

  /** Supply configuration update enable
  */
  HAL_PWREx_ConfigSupply(PWR_DIRECT_SMPS_SUPPLY);

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE0);

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}

  /** Configure LSE Drive Capability
  */
  HAL_PWR_EnableBkUpAccess();
  __HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_LOW);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE|RCC_OSCILLATORTYPE_LSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 2;
  RCC_OscInitStruct.PLL.PLLN = 40;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLQ = 3;
  RCC_OscInitStruct.PLL.PLLR = 4;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_3;
  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
  RCC_OscInitStruct.PLL.PLLFRACN = 5462;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                              |RCC_CLOCKTYPE_D3PCLK1|RCC_CLOCKTYPE_D1PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV2;
  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
  HAL_RCC_MCOConfig(RCC_MCO1, RCC_MCO1SOURCE_HSE, RCC_MCODIV_1);
}

/* USER CODE BEGIN 4 */

void BSP_CAMERA_FrameEventCallback(uint32_t Instance){
	camera_frame_ready = 1;
	DMA2D_Convert(buffer, buffer2d);
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
