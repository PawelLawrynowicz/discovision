
/**
  ******************************************************************************
  * @file    app_x-cube-ai.c
  * @author  X-CUBE-AI C code generator
  * @brief   AI program body
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

 /*
  * Description
  *   v1.0 - Minimum template to show how to use the Embedded Client API
  *          model. Only one input and one output is supported. All
  *          memory resources are allocated statically (AI_NETWORK_XX, defines
  *          are used).
  *          Re-target of the printf function is out-of-scope.
  *   v2.0 - add multiple IO and/or multiple heap support
  *
  *   For more information, see the embeded documentation:
  *
  *       [1] %X_CUBE_AI_DIR%/Documentation/index.html
  *
  *   X_CUBE_AI_DIR indicates the location where the X-CUBE-AI pack is installed
  *   typical : C:\Users\<user_name>\STM32Cube\Repository\STMicroelectronics\X-CUBE-AI\7.1.0
  */

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

#if defined ( __ICCARM__ )
#elif defined ( __CC_ARM ) || ( __GNUC__ )
#endif

/* System headers */
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>

#include "app_x-cube-ai.h"
#include "main.h"
#include "ai_datatypes_defines.h"
#include "face_detection.h"
#include "face_detection_data.h"

/* USER CODE BEGIN includes */
/* USER CODE END includes */

/* IO buffers ----------------------------------------------------------------*/

#if !defined(AI_FACE_DETECTION_INPUTS_IN_ACTIVATIONS)
AI_ALIGNED(4) ai_i8 data_in_1[AI_FACE_DETECTION_IN_1_SIZE_BYTES];
ai_i8* data_ins[AI_FACE_DETECTION_IN_NUM] = {
data_in_1
};
#else
ai_i8* data_ins[AI_FACE_DETECTION_IN_NUM] = {
NULL
};
#endif

#if !defined(AI_FACE_DETECTION_OUTPUTS_IN_ACTIVATIONS)
AI_ALIGNED(4) ai_i8 data_out_1[AI_FACE_DETECTION_OUT_1_SIZE_BYTES];
ai_i8* data_outs[AI_FACE_DETECTION_OUT_NUM] = {
data_out_1
};
#else
ai_i8* data_outs[AI_FACE_DETECTION_OUT_NUM] = {
NULL
};
#endif

/* Activations buffers -------------------------------------------------------*/

AI_ALIGNED(32)
static uint8_t pool0[AI_FACE_DETECTION_DATA_ACTIVATION_1_SIZE];

ai_handle data_activations0[] = {pool0};

/* AI objects ----------------------------------------------------------------*/

static ai_handle face_detection = AI_HANDLE_NULL;

static ai_buffer* ai_input;
static ai_buffer* ai_output;

static void ai_log_err(const ai_error err, const char *fct)
{
  /* USER CODE BEGIN log */
  if (fct)
    printf("TEMPLATE - Error (%s) - type=0x%02x code=0x%02x\r\n", fct,
        err.type, err.code);
  else
    printf("TEMPLATE - Error - type=0x%02x code=0x%02x\r\n", err.type, err.code);

  do {} while (1);
  /* USER CODE END log */
}

static int ai_boostrap(ai_handle *act_addr)
{
  ai_error err;

  /* Create and initialize an instance of the model */
  err = ai_face_detection_create_and_init(&face_detection, act_addr, NULL);
  if (err.type != AI_ERROR_NONE) {
    ai_log_err(err, "ai_face_detection_create_and_init");
    return -1;
  }

  ai_input = ai_face_detection_inputs_get(face_detection, NULL);
  ai_output = ai_face_detection_outputs_get(face_detection, NULL);

#if defined(AI_FACE_DETECTION_INPUTS_IN_ACTIVATIONS)
  /*  In the case where "--allocate-inputs" option is used, memory buffer can be
   *  used from the activations buffer. This is not mandatory.
   */
  for (int idx=0; idx < AI_FACE_DETECTION_IN_NUM; idx++) {
	data_ins[idx] = ai_input[idx].data;
  }
#else
  for (int idx=0; idx < AI_FACE_DETECTION_IN_NUM; idx++) {
	  ai_input[idx].data = data_ins[idx];
  }
#endif

#if defined(AI_FACE_DETECTION_OUTPUTS_IN_ACTIVATIONS)
  /*  In the case where "--allocate-outputs" option is used, memory buffer can be
   *  used from the activations buffer. This is no mandatory.
   */
  for (int idx=0; idx < AI_FACE_DETECTION_OUT_NUM; idx++) {
	data_outs[idx] = ai_output[idx].data;
  }
#else
  for (int idx=0; idx < AI_FACE_DETECTION_OUT_NUM; idx++) {
	ai_output[idx].data = data_outs[idx];
  }
#endif

  return 0;
}

static int ai_run(void)
{
  ai_i32 batch;

  batch = ai_face_detection_run(face_detection, ai_input, ai_output);
  if (batch != 1) {
    ai_log_err(ai_face_detection_get_error(face_detection),
        "ai_face_detection_run");
    return -1;
  }

  return 0;
}

/* USER CODE BEGIN 2 */
int acquire_and_process_data(ai_i8* data[])
{
  /* fill the inputs of the c-model
  for (int idx=0; idx < AI_FACE_DETECTION_IN_NUM; idx++ )
  {
      data[idx] = ....
  }

  */
  return 0;
}

int post_process(ai_i8* data[])
{
  /* process the predictions
  for (int idx=0; idx < AI_FACE_DETECTION_OUT_NUM; idx++ )
  {
      data[idx] = ....
  }

  */
  return 0;
}
/* USER CODE END 2 */

/* Entry points --------------------------------------------------------------*/

void MX_X_CUBE_AI_Init(void)
{
    /* USER CODE BEGIN 5 */
  printf("\r\nTEMPLATE - initialization\r\n");

  ai_boostrap(data_activations0);
    /* USER CODE END 5 */
}

void MX_X_CUBE_AI_Process(void)
{
    /* USER CODE BEGIN 6 */
	ai_i32 batch;
	float nn_input[AI_FACE_DETECTION_IN_1_SIZE];
	float nn_output[AI_FACE_DETECTION_OUT_1_SIZE];
//	nn_input[0] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8) ? 127.0 : -127.0;
//	nn_input[1] = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9) ? 127.0 : -127.0;
	ai_input->data = nn_input;
	ai_output->data = nn_output;
	batch = ai_face_detection_run(face_detection, ai_input, ai_output);
//	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, nn_output[0]>=0 ? 1 : 0);
//	printf("%f\r\n", nn_output[0]);
	if (batch != 1) {
	ai_log_err(ai_face_detection_get_error(face_detection), "aiface_detection_face_detection");
	}
    /* USER CODE END 6 */
}
#ifdef __cplusplus
}
#endif
