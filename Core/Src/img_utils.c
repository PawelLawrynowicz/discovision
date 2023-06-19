/*
 * img_utils.c
 *
 *  Created on: Jun 19, 2023
 *      Author: pwl
 */

#include "img_utils.h"
void rescaleImage(uint16_t *srcImg,uint16_t *dstImg, uint32_t srcWidth, uint32_t srcHeight, uint32_t dstWidth, uint32_t dstHeight)
{
    float scaleX = (float)srcWidth / dstWidth;
    float scaleY = (float)srcHeight / dstHeight;

    for (int y = 0; y < dstHeight; y++)
    {
        for (int x = 0; x < dstWidth; x++)
        {
            uint16_t srcX = (uint16_t)(x * scaleX);
            uint16_t srcY = (uint16_t)(y * scaleY);

            dstImg[y * dstWidth + x] = srcImg[srcY * srcWidth + srcX];
        }
    }
}

//void rescaleImage(uint32_t *srcImg,uint32_t *dstImg, uint32_t srcWidth, uint32_t srcHeight, uint32_t dstWidth, uint32_t dstHeight)
//{
//    float scaleX = (float)srcWidth / dstWidth;
//    float scaleY = (float)srcHeight / dstHeight;
//
//    for (int y = 0; y < dstHeight; y++)
//    {
//        for (int x = 0; x < dstWidth; x++)
//        {
//            float srcX = x * scaleX;
//            float srcY = y * scaleY;
//
//            int x1 = (int)srcX;
//            int y1 = (int)srcY;
//            int x2 = x1 + 1;
//            int y2 = y1 + 1;
//
//            // Calculate the fractional parts
//            float dx = srcX - x1;
//            float dy = srcY - y1;
//
//            // Get the pixel values at the four corners
//            uint8_t q11 = srcImg[y1 * srcWidth + x1];
//            uint8_t q12 = srcImg[y2 * srcWidth + x1];
//            uint8_t q21 = srcImg[y1 * srcWidth + x2];
//            uint8_t q22 = srcImg[y2 * srcWidth + x2];
//
//            // Perform bilinear interpolation
//            float topInterpolation = q11 + dx * (q21 - q11);
//            float bottomInterpolation = q12 + dx * (q22 - q12);
//            uint8_t interpolatedValue = topInterpolation + dy * (bottomInterpolation - topInterpolation);
//
//            dstImg[y * dstWidth + x] = interpolatedValue;
//        }
//    }
//}
