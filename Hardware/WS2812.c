//
// Created by pc on 2024/2/15.
//

#include "WS2812.h"
#include "tim.h"

//  ����PWM��������Ϊ1.25us��bit��1����ռ�ձ�Ϊ68%������֮������bit��0����ռ�ձ�Ϊ32%������֮һ��
#define PWM_PERIOD 90
#define _2812bit_high 60
#define _2812bit_low 30

uint32_t LED_Color_Byte[24];
uint32_t LED_Zero_Byte[24] = {_2812bit_low, _2812bit_low, _2812bit_low, _2812bit_low, _2812bit_low, _2812bit_low,
                              _2812bit_low, _2812bit_low,
                              _2812bit_low, _2812bit_low, _2812bit_low, _2812bit_low, _2812bit_low, _2812bit_low,
                              _2812bit_low, _2812bit_low,
                              _2812bit_low, _2812bit_low, _2812bit_low, _2812bit_low, _2812bit_low, _2812bit_low,
                              _2812bit_low, _2812bit_low};

// �Ӹ�λ����λ���ͣ��ֱ���G->R->B��˳���ͣ����ֽ���ǰ
void WS2812_Code(uint8_t Red, uint8_t Green, uint8_t Blue, uint32_t *color_byte) {
    int color_bit_pointer = 0;
    for (; color_bit_pointer < 8; color_bit_pointer++) {
        color_byte[color_bit_pointer] = (Green & 0x80) ? _2812bit_high : _2812bit_low;
        Green <<= 1;
    }
    for (; color_bit_pointer < 16; color_bit_pointer++) {
        color_byte[color_bit_pointer] = (Red & 0x80) ? _2812bit_high : _2812bit_low;
        Red <<= 1;
    }
    for (; color_bit_pointer < 24; color_bit_pointer++) {
        color_byte[color_bit_pointer] = (Blue & 0x80) ? _2812bit_high : _2812bit_low;
        Blue <<= 1;
    }

}

