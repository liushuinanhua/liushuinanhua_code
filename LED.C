/*
    ���ÿ������ţ����У���ת���򡪡�PA2��
		                    �ŷ���������PA3��
												����������ֹ���롪��PA9��
												����������ֹ���롪��PA10;
*/
#include "LED.h"

void LED_GPIO_Config(void)
{		
	   GPIO_InitTypeDef GPIO_InitStructure;
	
		 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	
	
     GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;	
  	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;      //  ��Ҫ���ŵĹ���������������ϵ�  
  	 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
     GPIO_Init(GPIOA, &GPIO_InitStructure);
     GPIO_SetBits(GPIOA,GPIO_Pin_2);   
	
	
	   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);   

	   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;	    		 
	   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		
	   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	   GPIO_Init(GPIOA, &GPIO_InitStructure);	
	   GPIO_SetBits(GPIOA,GPIO_Pin_3); 						 

	   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);   

	   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;	    		 
	   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
	   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	   GPIO_Init(GPIOA, &GPIO_InitStructure);	
	   GPIO_SetBits(GPIOA,GPIO_Pin_9); 	
		 
		 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);   

	   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;	    		 
	   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
	   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	   GPIO_Init(GPIOA, &GPIO_InitStructure);	
	   GPIO_SetBits(GPIOA,GPIO_Pin_10);
		 
		 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);   

	   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;	    		 
	   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 
	   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	   GPIO_Init(GPIOA, &GPIO_InitStructure);	
	   GPIO_SetBits(GPIOA,GPIO_Pin_8);
	
		 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);	
	
     GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;	
  	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;      //  ��Ҫ���ŵĹ���������������ϵ�  
  	 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
     GPIO_Init(GPIOD, &GPIO_InitStructure);
     GPIO_SetBits(GPIOD,GPIO_Pin_2);
		 
}


