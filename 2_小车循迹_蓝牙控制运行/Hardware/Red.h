#ifndef __RED_H
#define __RED_H

void Red_Init(void);
void Red_Catch(void);

#define SW1 Red_1		//将读取的光电变量名重定义为红外模块的端口名
#define SW2 Red_2		//便于调试时观察
#define SW3 Red_3
#define SW4 Red_4


#endif
