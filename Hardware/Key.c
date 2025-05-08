#include "Key.h"

uint8_t Get_KeyNum(uint8_t key_num)
{
    if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_8) == GPIO_PIN_RESET)
    {
        HAL_Delay(15);
        while (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_8) == GPIO_PIN_RESET);
        HAL_Delay(15);
        key_num = 1;
    }
    return key_num;
}
