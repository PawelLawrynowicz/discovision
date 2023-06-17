/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

void drawVLine(uint32_t *buffer, uint32_t x, uint32_t y_start, uint32_t y_end){
	for(uint32_t i = y_start; i<y_end; i++){
			buffer[(x+i*LTDC_WIDTH)/2] = COLOR;
	}
}
void drawHLine(uint32_t *buffer, uint32_t x_start, uint32_t x_end, uint32_t y){
	x_end=x_end+x_end%2;
	for(uint32_t i = x_start/2; i<x_end/2; i++){
		buffer[i+LTDC_WIDTH*y/2] = COLOR;
		buffer[i+(LTDC_WIDTH+LTDC_WIDTH*y)/2] = COLOR;
	}
}
void drawRectangle(uint32_t *buffer, uint32_t x_start, uint32_t x_end, uint32_t y_start, uint32_t y_end){
	drawVLine(buffer, x_start, y_start, y_end);
	drawVLine(buffer, x_end, y_start, y_end);
	drawHLine(buffer, x_start, x_end, y_start);
	drawHLine(buffer, x_start, x_end, y_end);
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
