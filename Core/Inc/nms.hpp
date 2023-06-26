#ifndef __NMS_HPP__
#define __NMS_HPP__

#ifdef __cplusplus
//extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <main.hpp>
#include <vector>
#include <array>
#include <algorithm>

#define PRED_TENSOR_LENGTH 38300 //40
#define CONFIDENCE_THRESHOLD 0.8
#define IOU_THRESHOLD 0.3
#define T_PRED std::array<float, 5>

float calculate_iou(std::array<float, 5> box1, std::array<float, 5> box2);

bool compareByFirstElement(const std::array<float, 5> &a, const std::array<float, 5> &b);

std::vector<T_PRED> nms(float *predictions);

#ifdef __cplusplus
//}
#endif
#endif /*__NMS_HPP__ */
