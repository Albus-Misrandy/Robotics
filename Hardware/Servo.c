#include "Servo.h"

void Set_Servo_Angle(float angle)
{
    if (angle >= 0)
    {
        float pre = angle / 90.0;
        uint16_t cnt = (uint16_t)(1500 + 1000 * pre);
        __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, cnt);
    }
    if (angle < 0)
    {
        float pre = angle / -90.0;
        uint16_t cnt = (uint16_t)(1500 - 1000 * pre);
        __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, cnt);
    }
}
