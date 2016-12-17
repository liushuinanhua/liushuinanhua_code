#include "Encoder.h"

short Encoder_Right;
/**************************************************************************
�������ܣ��ұ�������ʼ��
**************************************************************************/

void Encoder_Init_R(void)
{
 TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
 TIM_ICInitTypeDef TIM_ICInitStructure;
 GPIO_InitTypeDef GPIO_InitStructure;

 RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);//TIM2ʱ��ʹ��
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//ʹ��PORTAʱ��
 
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 |GPIO_Pin_1;//PA0,PA1
 GPIO_InitStructure.GPIO_Mode =GPIO_Mode_IN_FLOATING;//��������
 GPIO_Init(GPIOA, &GPIO_InitStructure);
 
 
 TIM_DeInit(TIM2);//���½�Timer�Ĵ�������Ϊȱʡֵ 
 TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);//��TIM_TimeBaseInitStruct �е�ÿһ��������ȱʡֵ����
 
 TIM_TimeBaseStructure.TIM_Prescaler = 0x0;    // ����Ƶ
 TIM_TimeBaseStructure.TIM_Period =0xFFFF; 
 TIM_TimeBaseStructure.TIM_ClockDivision =TIM_CKD_DIV1;//ѡ��ʱ�ӷ�Ƶ������Ƶ
 TIM_TimeBaseStructure.TIM_CounterMode =TIM_CounterMode_Up; //���ϼ���ģʽ 
                                                            //(������Ϊ�������ģʽ���߱�����ģʽʱ����λֻ��)
  TIM_TimeBaseInit(TIM2,&TIM_TimeBaseStructure);
 
 TIM_EncoderInterfaceConfig(TIM2,TIM_EncoderMode_TI12,TIM_ICPolarity_BothEdge, TIM_ICPolarity_BothEdge);//TI1��TI2��������������غ��½�����Ч
											//ѡ��ģʽ ������������ٶȺͷ���
 TIM_ICStructInit(&TIM_ICInitStructure); // ��TIM_ICInitStruct �е�ÿһ��������ȱʡֵ����
 TIM_ICInitStructure.TIM_Channel = TIM_Channel_1;//ѡ��ͨ��1
 TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;////ӳ�䵽 TI1 ��
 TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;//����Ƶ
 TIM_ICInitStructure.TIM_ICFilter = 0x03;//0011 ��Ӧ8���¼����һ������
 
 TIM_ICInitStructure.TIM_Channel = TIM_Channel_2;//ѡ��ͨ��2
 TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;//ӳ�䵽 TI2 ��
 TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;//����Ƶ
 TIM_ICInitStructure.TIM_ICFilter = 0x03;//0011 ��Ӧ8���¼����һ������
 
 TIM_ICInit(TIM2,&TIM_ICInitStructure);
 
 TIM_SetCounter(TIM2,0);  
 
 TIM_Cmd(TIM2, ENABLE); 
 
 }


//uint16_t Encoder_L,Encoder_R; 
uint16_t Encoder_R; 
/**************************************************************************
�������ܣ���ȡ�����������ݲ�������������ת��
**************************************************************************/
void readEncoder(void)
{    
	
	      //�ұ��������������
		Encoder_R = TIM_GetCounter(TIM2);       //===��ȡ��������1����	
	  TIM_SetCounter(TIM2,0);                 //===����������  
	  Encoder_Right=(short)Encoder_R;
}
