//
// Created by James on 2024/2/29.
//

#ifndef WS2812_APP_H
#define WS2812_APP_H

#include "main.h"
#include "tim.h"
#include "WS2812.h"

extern uint32_t FullMatrix[];
void FullMatrix_Colorful(uint32_t *fullmatrix);
void color_float();

#endif //WS2812_APP_H
