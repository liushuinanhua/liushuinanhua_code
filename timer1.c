#include "timer1.h"
#include "usart.h"


//���ö�ʱ�����жϣ����Բ��ٵ�

u16 n=0;

void TIM1_Int_Init(u16 arr,u16 psc)
{
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE); //ʱ��ʹ��

	TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	 ������5000Ϊ500ms
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ  10Khz�ļ���Ƶ��  
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseStructure.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
 

	NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_IRQn;  //TIM1�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =0;  //��ռ���ȼ�2��
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;  //�����ȼ�2��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQͨ����ʹ��
	NVIC_Init(&NVIC_InitStructure);  //����NVIC_InitStruct��ָ���Ĳ�����ʼ������NVIC�Ĵ���
	
	TIM_ITConfig(TIM1,TIM_IT_Update,ENABLE ); //ʹ��ָ����TIM1�ж�,��������ж�
//	TIM_Cmd(TIM1, ENABLE);  //ʹ��TIMx����
  TIM_Cmd(TIM1, DISABLE);   //�Ȳ�ʹ�ܶ�ʱ�����жϣ�
}




void TIM1_UP_IRQHandler(void)
{
 if ( TIM_GetITStatus(TIM1 ,TIM_IT_Update) != RESET ) //�Ƿ����ж�
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
   TIM_ClearITPendingBit(TIM1, TIM_FLAG_Update);    //����жϴ�����λ 
   TIM_Cmd(TIM3, ENABLE);
 }    
}