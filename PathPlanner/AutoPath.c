#include "AutoPath.h"

void Go_Distance(float distance, float* encoder)
{
    Set_Servo_Angle(0.0f);
    float target_deg = (distance / 204.2035f) * 360.0f;
    Motor_Control('a', encoder[0], target_deg, 0.2f, 0.0f, 0.01f);
    Motor_Control('b', encoder[1], target_deg, 0.2f, 0.0f, 0.01f);
}

void Stop()
{
    Set_Servo_Angle(0.0f);
    Set_Motor_velocity('a', 0);
    Set_Motor_velocity('b', 0);
}

void Stop_2()
{
    Set_Servo_Angle(18.0f);
    Set_Motor_velocity('a', 0);
    Set_Motor_velocity('b', 0);
}

void Turn_Right_Left(float deg, float distance, float* encoder)
{
    Set_Servo_Angle(deg);
    float target_deg = (distance / 204.2035f) * 360.0f;
    Motor_Control('a', encoder[0], target_deg, 0.2f, 0.0f, 0.01f);
    Motor_Control('b', encoder[1], target_deg, 0.2f, 0.0f, 0.01f);
}
