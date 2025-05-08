#ifndef __SERIAL_H__
#define __SERIAL_H__

#include "usart.h"
#include <stdio.h>  // 用于 sprintf 函数
#include <string.h> // 用于 strlen 函数

void send_32bits_data(int32_t value);
void send_16bits_data(uint16_t value);

#endif
