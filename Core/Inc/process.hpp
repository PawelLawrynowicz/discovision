#ifndef __PROCESS_H__
#define __PROCESS_H__

#ifdef __cplusplus
//extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <main.hPP>
#include "draw.h"
#include "nms.hpp"

void postProcess(uint32_t* buffer, float *predictions);

#ifdef __cplusplus
//}
#endif
#endif /*__ PROCESS_H__ */
