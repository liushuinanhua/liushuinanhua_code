#include "Encoder.h"

short Encoder_Right;
/**************************************************************************
函数功能：右编码器初始化
**************************************************************************/

void Encoder_Init_R(void)
{
 TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
 TIM_ICInitTypeDef TIM_ICInitStructure;
 GPIO_InitTypeDef GPIO_InitStructure;

 RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);//TIM2时钟使能
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//使能PORTA时钟
 
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 |GPIO_Pin_1;//PA0,PA1
 GPIO_InitStructure.GPIO_Mode =GPIO_Mode_IN_FLOATING;//浮空输入
 GPIO_Init(GPIOA, &GPIO_InitStructure);
 
 
 TIM_DeInit(TIM2);//重新将Timer寄存器设置为缺省值 
 TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);//把TIM_TimeBaseInitStruct 中的每一个参数按缺省值填入
 
 TIM_TimeBaseStructure.TIM_Prescaler = 0x0;    // 不分频
 TIM_TimeBaseStructure.TIM_Period =0xFFFF; 
 TIM_TimeBaseStructure.TIM_ClockDivision =TIM_CKD_DIV1;//选择时钟分频：不分频
 TIM_TimeBaseStructure.TIM_CounterMode =TIM_CounterMode_Up; //向上计数模式 
                                                            //(当配置为中央对齐模式或者编码器模式时，此位只读)
  TIM_TimeBaseInit(TIM2,&TIM_TimeBaseStructure);
 
 TIM_EncoderInterfaceConfig(TIM2,TIM_EncoderMode_TI12,TIM_ICPolarity_BothEdge, TIM_ICPolarity_BothEdge);//TI1和TI2的输入均在上升沿和下降沿有效
											//选择模式 ：两相计数（速度和方向）
 TIM_ICStructInit(&TIM_ICInitStructure); // 把TIM_ICInitStruct 中的每一个参数按缺省值填入
 TIM_ICInitStructure.TIM_Channel = TIM_Channel_1;//选择通道1
 TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;////映射到 TI1 上
 TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;//不分频
 TIM_ICInitStructure.TIM_ICFilter = 0x03;//0011 对应8个事件输出一个跳变
 
 TIM_ICInitStructure.TIM_Channel = TIM_Channel_2;//选择通道2
 TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;//映射到 TI2 上
 TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;//不分频
 TIM_ICInitStructure.TIM_ICFilter = 0x03;//0011 对应8个事件输出一个跳变
 
 TIM_ICInit(TIM2,&TIM_ICInitStructure);
 
 TIM_SetCounter(TIM2,0);  
 
 TIM_Cmd(TIM2, ENABLE); 
 
 }


//uint16_t Encoder_L,Encoder_R; 
uint16_t Encoder_R; 
/**************************************************************************
函数功能：读取编码器的数据并进行数据类型转换
**************************************************************************/
void readEncoder(void)
{    
	
	      //右编码器的脉冲计数
		Encoder_R = TIM_GetCounter(TIM2);       //===获取正交解码1数据	
	  TIM_SetCounter(TIM2,0);                 //===计数器清零  
	  Encoder_Right=(short)Encoder_R;
}
