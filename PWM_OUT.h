#ifndef __PWM_OUT_H
#define	__PWM_OUT_H

#include "stm32f10x.h"

#define tim3_period 10
#define tim3_prescaler 71

void TIM3_GPIO_Config(void);
void TIM3_PWM_Init(void);


#endif /* __PWM_OUTPUT_H */
