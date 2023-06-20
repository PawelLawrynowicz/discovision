/*
 * img_utils.h
 *
 *  Created on: Jun 19, 2023
 *      Author: pwl
 */

#ifndef INC_IMG_UTILS_H_
#define INC_IMG_UTILS_H_

#include <stdint.h>
void rescaleImage(uint32_t *srcImg,uint32_t *dstImg, uint32_t srcWidth, uint32_t srcHeight, uint32_t dstWidth, uint32_t dstHeight);

#endif /* INC_IMG_UTILS_H_ */
