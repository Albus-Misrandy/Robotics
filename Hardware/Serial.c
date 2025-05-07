#include "Serial.h"

void send_32bits_data(int32_t value)
{
    char buffer[50];
    sprintf(buffer, "%d,", value);
    HAL_UART_Transmit(&huart1, (uint8_t *)buffer, strlen(buffer), HAL_MAX_DELAY);
}
