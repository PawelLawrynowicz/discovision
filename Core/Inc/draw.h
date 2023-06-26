#ifndef __DRAW_H__
#define __DRAW_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <main.hpp>

void drawVLine(uint32_t *buffer, int32_t x, int32_t y_start, int32_t y_end);
void drawHLine(uint32_t *buffer, int32_t x_start, int32_t x_end, int32_t y);
void drawRectangle(uint32_t *buffer, int32_t x_start, int32_t x_end, int32_t y_start, int32_t y_end);
void drawCrosshair(uint32_t *buffer, int32_t x, int32_t y);

#ifdef __cplusplus
}
#endif
#endif /*__ DRAW_H__ */
