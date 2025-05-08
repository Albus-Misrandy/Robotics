#include "Motor.h"

PID_Controller pid;

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
            __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_1, -velocity);
        }
        if (velocity == 0)
        {
            HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOC, GPIO_PIN_11, GPIO_PIN_SET);
            __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_1, 2);
        }
    }
    if (motor_num == 'b')
    {
        if (velocity > 0)
        {
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);
            __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_2, velocity);
        }
        if (velocity < 0)
        {
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET);
            __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_2, -velocity);
        }
        if (velocity == 0)
        {
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET);
            __HAL_TIM_SET_COMPARE(&htim8, TIM_CHANNEL_2, 2);
        }
    }
}

float Angle_measurement(float current_pos)
{
    float deg = (current_pos / 728.0f) * 360.0f;
    return deg;
}

float PID_Update(PID_Controller *pid, float current_pos, float target_pos, float Kp, float Ki, float Kd) 
{
	pid->Kp = Kp;
	pid->Ki = Ki;
	pid->Kd = Kd;
	pid->target = target_pos;
	float error = pid->target - (current_pos / 728.0f) * 360.0f;
    pid->integral += error; // 积分项
    float derivative = (error - pid->prev_error); // 微分项
    float output = pid->Kp * error + pid->Ki * pid->integral + pid->Kd * derivative;
    pid->prev_error = error;
	if (error < 3 && error > -3)
	{
		output = 0;
	}
	return output;
  }

void Motor_Control(char Motor_num, float current_pos, float target_pos, float Kp, float Ki, float Kd) 
{
	// PID计算
	float output = PID_Update(&pid, current_pos, target_pos, Kp, Ki, Kd);
  
	// 输出限幅（例如±100%占空比）
	output = (output > 20) ? 20 : (output < -20) ? -20 : output;
	//send_16bitsfloat_data(output);
	int16_t pwm_output = (int16_t)output;
    if (pwm_output < 2)
    {
        pwm_output = 0;
    }
    
	Set_Motor_velocity(Motor_num, pwm_output);
}
