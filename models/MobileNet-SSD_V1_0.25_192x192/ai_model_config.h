/**
  ******************************************************************************
  * @file    ai_model_config.h
  * @author  Artificial Intelligence Solutions group (AIS)
  * @brief   User header file for Preprocessing configuration
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2018 STMicroelectronics.
  * All rights reserved.
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

/* ---------------    Generated code    ----------------- */
#ifndef __AI_MODEL_CONFIG_H__
#define __AI_MODEL_CONFIG_H__


#ifdef __cplusplus
  extern "C" {
#endif

/* I/O configuration */
#define NB_CLASSES        (1)
#define INPUT_HEIGHT        (192)
#define INPUT_WIDTH       (192)
#define INPUT_CHANNELS        (3)

const char classes[NB_CLASSES] = {"face"};

/* Preprocessing configuration */
#define PP_RESIZING_FLAG       (1)
#define PP_RESIZING_INTERPOLATION_BILINEAR       (1)
#define PP_RESIZING_INTERPOLATION_NEAREST       (0)
#define PP_RESIZING_INTERPOLATION_BICUBIC       (0)
#define PP_RESIZING_INTERPOLATION_AREA       (0)
#define PP_RESIZING_INTERPOLATION_GAUSSIAN       (0)

/* Post processing configuration */
#define PP_NMS_THRESH       (0.5)
#define PP_SCORE_THRESH       (0.01)

#define PP_KEEP_ASPECT_RATIO       (0)

#define PP_COLOR_MODE_RGB    (1)
#define PP_COLOR_MODE_BGR    (0)

/* Quantization configuration */
#define QUANT_INPUT_UINT8    (1)
#define QUANT_INPUT_INT8    (0)
#define QUANT_INPUT_FLOAT32    (0)
#define QUANT_INPUT_ZERO_POINT    (127.0)
#define QUANT_INPUT_SCALE    (0.007843137718737125)

#define QUANT_OUTPUT_UINT8    (0)
#define QUANT_OUTPUT_INT8    (0)
#define QUANT_OUTPUT_FLOAT32    (1)
#define QUANT_OUTPUT_ZERO_POINT    (0.0)
#define QUANT_OUTPUT_SCALE    (0.0)

#endif      /* __AI_MODEL_CONFIG_H__  */
}
