/**
  ******************************************************************************
  * @file    face_detection_data_params.h
  * @author  AST Embedded Analytics Research Platform
  * @date    Tue Jun 20 00:17:28 2023
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */

#ifndef FACE_DETECTION_DATA_PARAMS_H
#define FACE_DETECTION_DATA_PARAMS_H
#pragma once

#include "ai_platform.h"

/*
#define AI_FACE_DETECTION_DATA_WEIGHTS_PARAMS \
  (AI_HANDLE_PTR(&ai_face_detection_data_weights_params[1]))
*/

#define AI_FACE_DETECTION_DATA_CONFIG               (NULL)


#define AI_FACE_DETECTION_DATA_ACTIVATIONS_SIZES \
  { 119216, }
#define AI_FACE_DETECTION_DATA_ACTIVATIONS_SIZE     (119216)
#define AI_FACE_DETECTION_DATA_ACTIVATIONS_COUNT    (1)
#define AI_FACE_DETECTION_DATA_ACTIVATION_1_SIZE    (119216)



#define AI_FACE_DETECTION_DATA_WEIGHTS_SIZES \
  { 20856, }
#define AI_FACE_DETECTION_DATA_WEIGHTS_SIZE         (20856)
#define AI_FACE_DETECTION_DATA_WEIGHTS_COUNT        (1)
#define AI_FACE_DETECTION_DATA_WEIGHT_1_SIZE        (20856)



#define AI_FACE_DETECTION_DATA_ACTIVATIONS_TABLE_GET() \
  (&g_face_detection_activations_table[1])

extern ai_handle g_face_detection_activations_table[1 + 2];



#define AI_FACE_DETECTION_DATA_WEIGHTS_TABLE_GET() \
  (&g_face_detection_weights_table[1])

extern ai_handle g_face_detection_weights_table[1 + 2];


#endif    /* FACE_DETECTION_DATA_PARAMS_H */
