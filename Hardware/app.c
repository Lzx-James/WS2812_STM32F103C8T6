//
// Created by James on 2024/2/29.
//
#include "app.h"

uint8_t color_list[8][3] = {
        255, 0, 0,
        255, 128, 0,
        255, 255, 0,
        0, 255, 0,
        0, 127, 255,
        0, 0, 255,
        139, 0, 255,
        255, 255, 255
};

uint32_t FullMatrix[24 * 64];
void FullMatrix_Colorful(uint32_t *fullmatrix){
    for (int i = 0; i < 64; i++) {
        WS2812_Code(color_list[i % 8][0], color_list[i % 8][1], color_list[i % 8][2], fullmatrix + i * 24);
    }
}
void color_float(){
    uint8_t color_mid[3];

    color_mid[0] = color_list[7][0];
    color_mid[1] = color_list[7][1];
    color_mid[2] = color_list[7][2];

    for (int i = 7; i > 0; i--){
        color_list[i][0] = color_list[i-1][0];
        color_list[i][1] = color_list[i-1][1];
        color_list[i][2] = color_list[i-1][2];
    }
    color_list[0][0] = color_mid[0];
    color_list[0][1] = color_mid[1];
    color_list[0][2] = color_mid[2];

}

void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim) {
//    HAL_TIM_PWM_Start_DMA(&htim2, TIM_CHANNEL_2, LED_Color_Byte, 24);
//    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, 0);
//    HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_2);
}