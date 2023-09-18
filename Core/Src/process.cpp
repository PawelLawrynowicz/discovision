#include "process.hpp"

void postProcess(uint32_t* buffer, float *predictions){
	// Post process a frame in the buffer, apply nms and draw boxes showing detections
	std::vector<T_PRED> boxes = nms(predictions);

	for(uint32_t i = 0; i<boxes.size(); i++){
		float x_start = boxes[i][1]*LTDC_WIDTH_FLOAT;
		float x_end = boxes[i][3]*LTDC_WIDTH_FLOAT;
		float y_start = boxes[i][2]*LTDC_HEIGHT_FLOAT;
		float y_end = boxes[i][4]*LTDC_HEIGHT_FLOAT;
		drawRectangle(buffer, (int32_t)x_start, (int32_t)x_end, (int32_t)y_start, (int32_t)y_end);
	}
}
