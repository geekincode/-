#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Red.h"
#include "PWM.h"
#include "Key.h"
#include "Bluetooth.h"

void Car_Init(void)			//初始化小车各个模块
{
	Key_Init();
	PWM_TIM3_Init();	//时钟和定时器初始化
	PWM_TIM1_Init();	//并且只初始化一次
	Serial_Init();
	HC08_Init();
	OLED_Init();
	Red_Init();

}


