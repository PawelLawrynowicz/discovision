#include "process.h"

void postProcess(
		uint32_t* buffer,
		uint32_t original_width,
		uint32_t original_height,
		uint32_t scaled_width,
		uint32_t scaled_height,
		uint32_t grid_size,
		float probabilities[GRID_SIZE][GRID_SIZE]
){
	if(scaled_width != scaled_height){
		return;
	}

	uint8_t pixels_per_grid = scaled_width/GRID_SIZE;

	for(uint8_t i=0; i<GRID_SIZE; i++){
		for(uint8_t j=0; j<GRID_SIZE; j++){
			if(probabilities[j][i]>THRESHOLD){
				drawCrosshair(buffer, ((i*pixels_per_grid+pixels_per_grid/2)*original_width)/scaled_width, ((j*pixels_per_grid+pixels_per_grid/2)*original_height)/scaled_height);
			}
		}
	}
}
