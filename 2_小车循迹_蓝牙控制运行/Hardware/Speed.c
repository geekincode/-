#include "stm32f10x.h"                  // Device header
#include "PWM.h"
#include "OLED.h"


void Speed_Control(int32_t speed_left, int32_t speed_right)		//速度应该在100到-100内
{
	if (speed_left > 100)	speed_left = 100;			//防止传入的参数溢出
	if (speed_left < -100)	speed_left = -100;
	if (speed_right > 100)	speed_right = 100;
	if (speed_right < -100)	speed_right = -100;
	
	
	PWM_SetCompare_TIM3(speed_right);		//通过设置定时器CCR的值来改变占空比
	PWM_SetCompare_TIM1(speed_left);		//即小车左右轮速度

}

