#include "Serial.h"

void send_32bits_data(int32_t value)
{
    char buffer[40];
    sprintf(buffer, "%ld,", value);
    HAL_UART_Transmit(&huart1, (uint8_t *)buffer, strlen(buffer), HAL_MAX_DELAY);
}

void send_16bits_data(uint16_t value)
{
    char buffer[20];
    sprintf(buffer, "%d,", value);
    HAL_UART_Transmit(&huart1, (uint8_t *)buffer, strlen(buffer), HAL_MAX_DELAY);
}
