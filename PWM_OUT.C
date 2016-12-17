

#include "PWM_OUT.h"

void TIM3_GPIO_Config(void) 
{
  GPIO_InitTypeDef GPIO_InitStructure;

  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); 
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); 

  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;		  
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_0 | GPIO_Pin_1;

  GPIO_Init(GPIOB, &GPIO_InitStructure);
}


void TIM3_PWM_Init(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;

	/* PWM信号电平跳变值 */
	u16 CCR3_Val = 500;
	u16 CCR4_Val = 700;
	
	TIM3_GPIO_Config();

/* -----------------------------------------------------------------------
    TIM3 Configuration: generate 4 PWM signals with 4 different duty cycles:
    TIM3CLK = 72 MHz, Prescaler = 0x0, TIM3 counter clock = 72 MHz
    TIM3 ARR Register = 999 => TIM3 Frequency = TIM3 counter clock/(ARR + 1)
    TIM3 Frequency = 72 KHz.
    TIM3 Channel1 duty cycle = (TIM3_CCR1/ TIM3_ARR)* 100 = 50%
    TIM3 Channel2 duty cycle = (TIM3_CCR2/ TIM3_ARR)* 100 = 37.5%
    TIM3 Channel3 duty cycle = (TIM3_CCR3/ TIM3_ARR)* 100 = 25%
    TIM3 Channel4 duty cycle = (TIM3_CCR4/ TIM3_ARR)* 100 = 12.5%
  ----------------------------------------------------------------------- */

  /*定时器配置 */	
  /*当定时器从0计数到999，即为1000次，为一个定时周期*/	
  TIM_TimeBaseStructure.TIM_Period = tim3_period; 
  TIM_TimeBaseStructure.TIM_Prescaler = tim3_prescaler;
  TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1 ;	
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  

  TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

  /* PWM1 Mode configuration: Channel1 */
	/*配置为PWM模式1*/
  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	    
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;	
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  
  TIM_OCInitStructure.TIM_Pulse = tim3_period/2;	
	
  TIM_OC3Init(TIM3, &TIM_OCInitStructure);	 
  TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);

  /* PWM1 Mode configuration: Channel4 */
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	
	/*设置通道4跳变值，当计数器计数到这个值时，电平发生跳变，输出另外一个占空比的PWM*/
  TIM_OCInitStructure.TIM_Pulse = tim3_period/2;	
  /*使能通道4*/
  TIM_OC4Init(TIM3, &TIM_OCInitStructure);	

  TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);
  /*使能TIM3重载寄存器ARR*/
  TIM_ARRPreloadConfig(TIM3, ENABLE);			 
  /*使能定时器3*/
  TIM_Cmd(TIM3, DISABLE);              
}

