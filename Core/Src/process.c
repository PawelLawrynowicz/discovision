#include "process.h"

void postProcess(
		uint32_t* buffer,
		uint32_t original_width,
		uint32_t original_height,
		uint32_t scaled_width,
		uint32_t scaled_height,
		uint32_t grid_size,
		float probabilities[GRID_SIZE*GRID_SIZE*2]
){
	if(scaled_width != scaled_height){
		return;
	}

	uint8_t pixels_per_grid = scaled_width/GRID_SIZE;

	// for 2d table
//	for(uint8_t i=0; i<GRID_SIZE; i++){
//		for(uint8_t j=0; j<GRID_SIZE; j++){
//			if(probabilities[j][i]>THRESHOLD){
//				drawCrosshair(buffer, ((i*pixels_per_grid+pixels_per_grid/2)*original_width)/scaled_width, ((j*pixels_per_grid+pixels_per_grid/2)*original_height)/scaled_height);
//			}
//		}
//	}
	for(uint32_t i = 1; i<GRID_SIZE*GRID_SIZE*2; i+=2){
		if(probabilities[i]>THRESHOLD){
			drawCrosshair(buffer, ((((i%24+1)/2-1)*pixels_per_grid+pixels_per_grid/2)*original_width)/scaled_width, (((i/24))*pixels_per_grid+pixels_per_grid/2)*original_height/scaled_height);
		}
	}
	/*
	 *
	 *
	 *
	 *
	 *
	 */
}
