
#include "stm32f10x.h"
#include "pwm_out.h"
#include "led.h"
#include "delay.h"
#include "timer1.h"
#include "key.h"


#define tim11 2000
#define tim12 72                                                                                                                                  


int main()
{
	unsigned char key_value;
	u8 flag = 0;
	TIM1_Int_Init(tim11,tim12);
	TIM3_PWM_Init();
	LED_GPIO_Config();
	Key_GPIO_Config();
	
	while(1)
	{
		key_value = KEY_Scan();
		if(key_value == 2)
		{
			SRV_ON;
			TIM_Cmd(TIM1, ENABLE);
//			GPIO_WriteBit(GPIOA, GPIO_Pin_8, (BitAction)(1-(GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_8))));
		}		
		if(key_value == 3)
		{
			flag ^= 1;
			if(flag==1)
			{
			TIM_Cmd(TIM3, ENABLE);
			GPIO_ResetBits(GPIOA, GPIO_Pin_8);
			}
			else
			{
				TIM_Cmd(TIM3, DISABLE);
				GPIO_WriteBit(GPIOA, GPIO_Pin_8, Bit_SET);
      }
		}	
  }
	return 0;
}
