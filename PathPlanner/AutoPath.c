#include "AutoPath.h"

void Go_Ahead()
{
    Set_Servo_Angle(0.0f);
    Set_Motor_velocity('a', 20);
    Set_Motor_velocity('b', 20);
}

void Stop()
{
    Set_Servo_Angle(0.0f);
    Set_Motor_velocity('a', 0);
    Set_Motor_velocity('b', 0);
}
