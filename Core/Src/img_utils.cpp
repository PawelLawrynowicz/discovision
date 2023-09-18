/*
 * img_utils.c
 *
 *  Created on: Jun 19, 2023
 *      Author: pwl
 */

#include <img_utils.hpp>
void rescale_Image(uint32_t *srcImg,uint32_t *dstImg, uint32_t srcWidth, uint32_t srcHeight, uint32_t dstWidth, uint32_t dstHeight)
{
    // Interlinear scaling of an image
    float scaleX = (float)srcWidth / dstWidth;
    float scaleY = (float)srcHeight / dstHeight;

    for (uint32_t y = 0; y < dstHeight; y++)
    {
        for (uint32_t x = 0; x < dstWidth; x++)
        {
            uint32_t srcX = (uint32_t)(x * scaleX);
            uint32_t srcY = (uint32_t)(y * scaleY);

            dstImg[y * dstWidth + x] = srcImg[srcY * srcWidth + srcX];
        }
    }
}
