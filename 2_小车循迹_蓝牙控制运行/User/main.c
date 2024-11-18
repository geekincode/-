#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Line_Walk.h"
#include "Init.h"
#include "Speed.h"
#include "Bluetooth.h"
#include "stdlib.h"

uint8_t Red_1, Red_2, Red_3, Red_4 = 0;		//定义全局变量
uint8_t i;			//定义for循环的变量
int state = 0;
int speed = 55;;
uint8_t RxSTA = 1;
char RxData[100] = "";

int main(void)
{
	/*模块初始化*/
	Car_Init();
	
	
	while (1)
	{
		HC08_GetData(RxData);
		if (RxSTA == 0)
		{
			speed = atoi(RxData);
			RxSTA = 1;
			OLED_ShowSignedNum(3, 1, speed, 3);
			break;
		}
	}
	while (1)
	{
		HC08_GetData(RxData);
		if (*RxData == '1')
		{
			Line_Walk(speed, speed);
		//Delay_ms(500);
		}
		if (*RxData == '2')
		{
			Line_Walk(0, 0);
		}
	}

	
	/*
	OLED_ShowString(1, 1, "RxData:");				//蓝牙调试
	OLED_ShowString(2, 1, RxData);

	while (1)
	{
		HC08_GetData(RxData);
		if (RxSTA == 0)
		{
			OLED_Clear();
			OLED_ShowString(1, 1, "RxData:");
			OLED_ShowString(3, 1, RxData);
			RxSTA = 1;
		}
	}
	*/
}
