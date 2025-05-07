#include "Motor.h"

void Set_Motor_velocity(char motor_num, int16_t velocity)
{
    if (motor_num == 'a')
    {
        if (velocity > 0)
        {
            HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOC, GPIO_PIN_11, GPIO_PIN_RESET);
            __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_1, velocity);
        }
        if (velocity < 0)
        {
            HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOC, GPIO_PIN_11, GPIO_PIN_SET);
            __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_2, -velocity);
        }
        if (velocity == 0)
        {
            HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOC, GPIO_PIN_11, GPIO_PIN_SET);
            __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_1, 2);
        }
    }
}
