/******************** ��ѧ�Ƽ� **************************
 * ʵ��ƽ̨��������STM32������
 * ��汾  ��ST3.5.0
 * ����    ����ѧ�Ƽ��Ŷ� 
 * �Ա�    ��http://shop102218275.taobao.com/
 * ������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
 *��Ȩ���У�����ؾ���
**********************************************************************************/

#include "exti.h"
#include "LED.h"
#include "delay.h"

 
/*
 * ��������NVIC_Configuration
 * ����  ������Ƕ�������жϿ�����NVIC
 * ����  ����
 * ���  ����
 * ����  ���ڲ�����
 */
static void NVIC_Configuration(void)
{
		NVIC_InitTypeDef NVIC_InitStructure;
//	 /*����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�*/
	  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	
//	  /*ʹ�ܰ������ڵ��ⲿ�ж�ͨ��*/
//  	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
//    /*������ռ���ȼ�����ռ���ȼ���Ϊ2*/	
//  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	
//	  /*���������ȼ��������ȼ���Ϊ1*/
//  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;		
//    /*ʹ���ⲿ�ж�ͨ*/
//  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;	
//     /*����NVIC_InitStruct��ָ���Ĳ�����ʼ������NVIC�Ĵ���*/		
//  	NVIC_Init(&NVIC_InitStructure); 
	
     /*ʹ�ܰ������ڵ��ⲿ�ж�ͨ��*/
  	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;			
	   /*������ռ���ȼ�����ռ���ȼ���Ϊ2*/	
  	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02;	
	  /*���������ȼ��������ȼ���Ϊ2*/
  	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x02;		
	   /*ʹ���ⲿ�ж�ͨ*/
  	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;	
     /*����NVIC_InitStruct��ָ���Ĳ�����ʼ������NVIC�Ĵ���*/	
  	NVIC_Init(&NVIC_InitStructure);  	 

}


/*
 * ��������EXTI_Config
 * ����  ������PA0,PA13,PA15Ϊ���жϿڣ��������ж����ȼ�
 * ����  ����
 * ���  ����
 * ����  ���ⲿ����
 */
void EXTI_Config(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
 	EXTI_InitTypeDef EXTI_InitStructure;
  
    /*��������ʱ��*/
  	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO,ENABLE);

//    /*��ʼ�� GPIOA.13,GPIOA.15  ����Ϊ��������*/
//  	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_13|GPIO_Pin_15;
//  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
//  	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	
    /* ��ʼ�� GPIOA.0	  ����Ϊ��������*/
  	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;
  	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
  	GPIO_Init(GPIOA, &GPIO_InitStructure);

//    /*GPIOA.13 �ж�������*/
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource13);
//    
//     /*GPIOA.13 �жϳ�ʼ������*/
//  	EXTI_InitStructure.EXTI_Line=EXTI_Line13;
//  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
//  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
//  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
//		/*����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ�*/
//  	EXTI_Init(&EXTI_InitStructure);	 

//   /*GPIOA.15	  �ж�������*/
//  	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource15);
//    
//	/*GPIOA.15	  �жϳ�ʼ������*/
//  	EXTI_InitStructure.EXTI_Line=EXTI_Line15;
//  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
//  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
//  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
//		/*����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���*/
//  	EXTI_Init(&EXTI_InitStructure);	  	

    /*GPIOA.0 �ж�������*/
 	  GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource0);
    
	/*GPIOA.0 �жϳ�ʼ������*/
 	  EXTI_InitStructure.EXTI_Line=EXTI_Line0;
  	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	
  	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
  	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
		/*����EXTI_InitStruct��ָ���Ĳ�����ʼ������EXTI�Ĵ���*/
  	EXTI_Init(&EXTI_InitStructure);		
    
		/*�����жϿ�����NVIC*/
    NVIC_Configuration();
	
}


