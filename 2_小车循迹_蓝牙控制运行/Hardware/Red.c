#include "stm32f10x.h"                  // Device header
#include "OLED.h"

extern uint8_t Red_1, Red_2, Red_3, Red_4 ;


void Red_Init(void)
{
	/*开启时钟*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);			//开启GPIOA的时钟
	
	/*GPIO初始化*/
	GPIO_InitTypeDef GPIOA_InitStructure;
	GPIOA_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIOA_InitStructure.GPIO_Pin = GPIO_Pin_15|GPIO_Pin_12;		
	GPIOA_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIOA_InitStructure);							//将PA1，PA2, PA3, PA4引脚初始化为复用推挽输出	
																	//受外设控制的引脚，均需要配置为复用模式
	
	/*开启时钟*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);			//开启GPIOA的时钟
	
	/*GPIO初始化*/
	GPIO_InitTypeDef GPIOB_InitStructure;
	GPIOB_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIOB_InitStructure.GPIO_Pin = GPIO_Pin_3|GPIO_Pin_4;		
	GPIOB_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIOB_InitStructure);							//将PA1，PA2, PA3, PA4引脚初始化为复用推挽输出	
																	//受外设控制的引脚，均需要配置为复用模式
	
	Red_1 = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_4);
	Red_2 = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_3);
	Red_3 = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_15);
	Red_4 = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_12);

	/*
	OLED_ShowNum(1, 1, Red_1, 10);
	OLED_ShowNum(2, 1, Red_2, 10);
	OLED_ShowNum(3, 1, Red_3, 10);
	OLED_ShowNum(4, 1, Red_4, 10);
	*/

}

void Red_Catch(void)
{
	Red_Init();
	Red_1 = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_4);		//读取P口的值，0或1
	Red_2 = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_3);
	Red_3 = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_15);
	Red_4 = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_12);
	/*
	OLED_ShowNum(1, 1, Red_1, 10);		//将P口的高低电平的值输出到OLED屏上
	OLED_ShowNum(2, 1, Red_2, 10);
	OLED_ShowNum(3, 1, Red_3, 10);
	OLED_ShowNum(4, 1, Red_4, 10);
	*/
}
