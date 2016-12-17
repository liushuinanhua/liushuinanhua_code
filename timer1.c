#include "timer1.h"
#include "usart.h"


//设置定时器终中断，可以测速的

u16 n=0;

void TIM1_Int_Init(u16 arr,u16 psc)
{
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE); //时钟使能

	TIM_TimeBaseStructure.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	 计数到5000为500ms
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //设置用来作为TIMx时钟频率除数的预分频值  10Khz的计数频率  
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位
 

	NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_IRQn;  //TIM1中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =0;  //先占优先级2级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;  //从优先级2级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
	NVIC_Init(&NVIC_InitStructure);  //根据NVIC_InitStruct中指定的参数初始化外设NVIC寄存器
	
	TIM_ITConfig(TIM1,TIM_IT_Update,ENABLE ); //使能指定的TIM1中断,允许更新中断
//	TIM_Cmd(TIM1, ENABLE);  //使能TIMx外设
  TIM_Cmd(TIM1, DISABLE);   //先不使能定时器中中断，
}




void TIM1_UP_IRQHandler(void)
{
 if ( TIM_GetITStatus(TIM1 ,TIM_IT_Update) != RESET ) //是否发生中断
 { 
	 TIM_Cmd(TIM3, DISABLE);       
   n++;
	 if(n>=500)
	 {
		 n=0;
			GPIO_WriteBit(GPIOA, GPIO_Pin_2, (BitAction)(1-(GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_2))));
		 GPIO_WriteBit(GPIOD, GPIO_Pin_2, (BitAction)(1-(GPIO_ReadOutputDataBit(GPIOD, GPIO_Pin_2))));
   }
	// readEncoder();
	// printf("speed :%d\n",Encoder_R);
   TIM_ClearITPendingBit(TIM1, TIM_FLAG_Update);    //清除中断待处理位 
   TIM_Cmd(TIM3, ENABLE);
 }    
}