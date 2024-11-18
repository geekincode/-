#include "stm32f10x.h"                  // Device header
#include "Speed.h"
#include "Red.h"
#include "Key.h"
#include "OLED.h"

extern uint8_t Red_1, Red_2, Red_3, Red_4 ;
extern int state;
int flag = 0;

void Line_Walk(int32_t speed_left, int32_t speed_right)	//基本巡线程序
{
	int32_t left = speed_left;
	int32_t right = speed_right;
	
	double Kd = 1.5;

		left = speed_left;
		right = speed_right;

		Red_Catch();								//读取红外光电值
		
		if (SW1 == 0|SW3 == 0)						//0为黑，1为白
		{
			if (SW1 == 0 & SW3 == 0)					//无偏移
			{
				//Speed_Control(left, right);
				state = 0;
				flag = 0;
			}
			else if (SW1 == 0 & SW3 == 1)				//向右偏移
			{
				right = right * Kd;
			}
			else if (SW1 == 1 & SW3 == 0)				//向左偏移
			{
				left = left * Kd;
			}
			if (SW2 == 0)
			{
				right = right * Kd;
				left = speed_left;
			}
			else if (SW4 == 0)
			{
				left = left * Kd;
				right = speed_right;
			}
		}
		else if (SW2 == 0|state == 1)
		{
				right = right * Kd*Kd;
				left = -30;
				state = 1;
				flag = 1;
		}
		else if (SW4 == 0|state == 2)
		{
				left = left *Kd*Kd;
				right = -30;
				state = 2;
				flag = 1;
		}
		if (SW1 == 0 & SW3 == 0&SW2 ==1&SW4==1)		state=0;
/*
		OLED_ShowNum(1, 1, state, 2);
		OLED_ShowSignedNum(2, 1, left, 3);
		OLED_ShowSignedNum(3, 1, right, 3);
*/


		Speed_Control(left, right);

}

