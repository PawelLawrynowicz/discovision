#ifndef __DRAW_H__
#define __DRAW_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

void drawVLine(uint32_t *buffer, uint32_t x_start, uint32_t x_end, uint32_t y_start, uint32_t y_end);
void drawHLine(uint32_t *buffer, uint32_t x_start, uint32_t x_end, uint32_t y_start, uint32_t y_end);
void drawRectangle(uint32_t *buffer, uint32_t x_start, uint32_t x_end, uint32_t y_start, uint32_t y_end);

#ifdef __cplusplus
}
#endif
#endif /*__ DRAW_H__ */
