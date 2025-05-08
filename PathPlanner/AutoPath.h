#ifndef __AUTOPATH_H__
#define __AUTOPATH_H__

#include "Servo.h"
#include "Motor.h"

void Go_Distance(float distance, float* encoder);
void Stop();
void Stop_2();
void Turn_Right_Left(float deg, float distance, float* encoder);

#endif
