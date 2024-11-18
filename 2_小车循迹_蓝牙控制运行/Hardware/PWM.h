#ifndef __PWM_H
#define __PWM_H

void PWM_TIM3_Init(void);
void PWM_TIM1_Init(void);

void PWM_SetCompare_TIM3(int32_t Compare);
void PWM_SetCompare_TIM1(int32_t Compare);

#endif
