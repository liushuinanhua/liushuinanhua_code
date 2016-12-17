#ifndef _TIMER1_H_
#define _TIMER1_H_

#include "stm32f10x.h"
#include "encoder.h"
#include "usart.h"

void TIM1_Int_Init(u16 arr,u16 psc);

#endif