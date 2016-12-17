#ifndef __LED_H
#define	__LED_H

#include "stm32f10x.h"

#define SIGN_P GPIO_SetBits(GPIOA,GPIO_Pin_2);    
#define SIGN_N GPIO_ResetBits(GPIOA,GPIO_Pin_2);   

#define SRV_ON GPIO_SetBits(GPIOA,GPIO_Pin_2);    
#define SRV_OFF GPIO_ResetBits(GPIOA,GPIO_Pin_2); 

#define POT_OFF GPIO_SetBits(GPIOA,GPIO_Pin_2);    
#define POT_ON GPIO_ResetBits(GPIOA,GPIO_Pin_2); 

#define NOT_OFF GPIO_SetBits(GPIOA,GPIO_Pin_2);    
#define NOT_ON GPIO_ResetBits(GPIOA,GPIO_Pin_2); 

void LED_GPIO_Config(void);   

#endif /* __LED_H */
