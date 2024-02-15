//
// Created by pc on 2024/2/15.
//

#ifndef WS2812_WS2812_H
#define WS2812_WS2812_H

#include "main.h"

void WS2812_Code(uint8_t Red, uint8_t Green, uint8_t Blue, uint16_t *color_byte);
extern uint16_t LED_Color_Byte[];
extern uint16_t LED_Zero_Byte[];

#endif //WS2812_WS2812_H
