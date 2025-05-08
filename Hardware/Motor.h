#ifndef __MOTOR_H__
#define __MOTOR_H__

#include "gpio.h"
#include "tim.h"

typedef struct {
    float Kp;
    float Ki;
    float Kd;    // PID参数
    float target;         // 目标位置（编码器计数值）
    float integral;       // 积分项
    float prev_error;     // 上一次误差
  } PID_Controller;

void Set_Motor_velocity(char motor_num, int16_t velocity);
float Angle_measurement(float current_pos);
float PID_Update(PID_Controller *pid, float current_pos, float target_pos, float Kp, float Ki, float Kd);
void Motor_Control(char Motor_num, float current_pos, float target_pos, float Kp, float Ki, float Kd);

#endif
