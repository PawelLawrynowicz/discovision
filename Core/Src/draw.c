/* Includes ------------------------------------------------------------------*/
#include "draw.h"

static void drawVLine(uint32_t *buffer, int32_t x, int32_t y_start, int32_t y_end){
	// Draw a vertical line on the buffer
	if(y_start<0){
		y_start=0;
	}
	if(y_end>LTDC_HEIGHT){
		y_end=LTDC_HEIGHT;
	}
	for(uint32_t i = y_start; i<y_end; i++){
			buffer[x+i*LTDC_WIDTH] = COLOR;
	}
}
static void drawHLine(uint32_t *buffer, int32_t x_start, int32_t x_end, int32_t y){
	// Draw a horizontal line on the buffer
	if(x_start<0){
		x_start=0;
	}
	if(x_end>LTDC_WIDTH){
		x_end=LTDC_WIDTH;
	}
	x_end=x_end+x_end%2;
	for(uint32_t i = x_start; i<x_end; i++){
		buffer[i+LTDC_WIDTH*y] = COLOR;
		buffer[i+(LTDC_WIDTH+LTDC_WIDTH*y)] = COLOR;
	}
}
void drawRectangle(uint32_t *buffer, int32_t x_start, int32_t x_end, int32_t y_start, int32_t y_end){
	// draw rectangle at given coordinates
	drawVLine(buffer, x_start, y_start, y_end);
	drawVLine(buffer, x_end, y_start, y_end);
	drawHLine(buffer, x_start, x_end, y_start);
	drawHLine(buffer, x_start, x_end, y_end);
}

void drawCrosshair(uint32_t *buffer, int32_t x, int32_t y){
	// DEPRECATED, stays in case the model changes to keypoint based
	drawHLine(buffer, x-CROSSHAIR_SIZE, x+CROSSHAIR_SIZE, y);
	drawVLine(buffer, x, y-CROSSHAIR_SIZE, y+CROSSHAIR_SIZE);
}

