#ifndef __PROCESS_H__
#define __PROCESS_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "draw.h"

void postProcess(uint32_t* buffer, uint32_t original_width, uint32_t original_height, uint32_t scaled_width, uint32_t scaled_height, uint32_t grid_size, float probabilities[GRID_SIZE][GRID_SIZE]);


#ifdef __cplusplus
}
#endif
#endif /*__ PROCESS_H__ */
