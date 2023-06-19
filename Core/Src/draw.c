/* Includes ------------------------------------------------------------------*/
#include "draw.h"

void drawVLine(uint32_t *buffer, int32_t x, int32_t y_start, int32_t y_end){
	if(y_start<0){
		y_start=0;
	}
	if(y_end>LTDC_HEIGHT){
		y_end=LTDC_HEIGHT;
	}
	for(uint32_t i = y_start; i<y_end; i++){
			buffer[(x+i*LTDC_WIDTH)/2] = COLOR;
	}
}
void drawHLine(uint32_t *buffer, int32_t x_start, int32_t x_end, int32_t y){
	if(x_start<0){
		x_start=0;
	}
	if(x_end>LTDC_WIDTH){
		x_end=LTDC_WIDTH;
	}
	x_end=x_end+x_end%2;
	for(uint32_t i = x_start/2; i<x_end/2; i++){
		buffer[i+LTDC_WIDTH*y/2] = COLOR;
		buffer[i+(LTDC_WIDTH+LTDC_WIDTH*y)/2] = COLOR;
	}
}
void drawRectangle(uint32_t *buffer, int32_t x_start, int32_t x_end, int32_t y_start, int32_t y_end){
	drawVLine(buffer, x_start, y_start, y_end);
	drawVLine(buffer, x_end, y_start, y_end);
	drawHLine(buffer, x_start, x_end, y_start);
	drawHLine(buffer, x_start, x_end, y_end);
}

void drawCrosshair(uint32_t *buffer, int32_t x, int32_t y){
	drawHLine(buffer, x-CROSSHAIR_SIZE, x+CROSSHAIR_SIZE, y);
	drawVLine(buffer, x, y-CROSSHAIR_SIZE, y+CROSSHAIR_SIZE);
}
//
//void drawVLine(void){
//	for(uint32_t i = 30; i<sizeof(buffer2d); i+=LTDC_HEIGHT){
//		buffer2d[i] = 0xFF00FF;
//	}
//}
//
//void drawHLine(void){
//	uint16_t x_start = 30;
//	uint16_t x_end = 100;
//	uint16_t y_start = 1;
//	for(uint32_t i = x_start; i<x_end; i++){
//			buffer2d[i+(LTDC_WIDTH/2)*y_start] = 0xFF00FF;
//	}
//}
//
//void drawHLine2(void){
//	uint16_t x_start = 30;
//	uint16_t x_end = 100;
//	uint16_t y_start = 3;
//	for(uint32_t i = x_start; i<x_end; i++){
//			buffer2d[i+(LTDC_WIDTH/2)*y_start] = 0xFF00FF;
//	}
//}
