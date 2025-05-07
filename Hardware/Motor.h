#ifndef __MOTOR_H__
#define __MOTOR_H__

#include "gpio.h"
#include "tim.h"

void Set_Motor_velocity(char motor_num, int16_t velocity);

#endif
