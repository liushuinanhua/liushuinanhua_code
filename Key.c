/******************** ��ѧ�Ƽ� **************************
 * ʵ��ƽ̨��������STM32������
 * ��汾  ��ST3.5.0
 * ����    ����ѧ�Ƽ��Ŷ� 
 * �Ա�    ��http://shop102218275.taobao.com/
 * ������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
 *��Ȩ���У�����ؾ���
**********************************************************************************/

#include "stm32f10x.h"
#include "Key.h"
#include "delay.h"


 /*
 * ��������Key_GPIO_Config
 * ����  �����ð����õ���I/O��
 * ����  ����
 * ���  ����
 */
void Key_GPIO_Config(void)
{ 
 	GPIO_InitTypeDef GPIO_InitStructure;

   /*���������˿ڣ�PA0/PA13/PA15����ʱ��*/
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	/*��ʼ��KEY0-->GPIOA.13,KEY1-->GPIOA.15  ��������*/
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_13|GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
 	GPIO_Init(GPIOA, &GPIO_InitStructure);

   	/*��ʼ�� WK_UP-->GPIOA.0	  ��������*/
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; 
	GPIO_Init(GPIOA, &GPIO_InitStructure);
		 

}

 /*
 * ��������Key_Scan
 * ����  ������Ƿ��а�������
 * ����  ����	
 * ���  �����ذ���ֵ
 */

unsigned char KEY_Scan(void)
{	 
	unsigned char key_code;
  if(KEY1_Scan()==1)key_code=1;
	else if(KEY0_Scan()==1)key_code=2;
	else if(KEY2_Scan()==1)key_code=3;
	else key_code=0;
	return key_code;
}

unsigned char KEY1_Scan(void)
{	 
	static char key_up1=0;//�������ɿ���־	
 	if(KEY1==0)
	{
		/*��ʱȥ���� */
	  Delay(10000);	
		if(KEY1==0)
		{
			key_up1=1;
    }		
	 }
	 if(KEY1==1&&key_up1==1)
	 {
		key_up1=0;
    return 1;
    }
		return 0;
}




unsigned char KEY0_Scan(void)
{	 
	static char key_up0=0;//�������ɿ���־	

 	if(KEY0==0)
	{
		/*��ʱȥ���� */
	Delay(10000);	
	
		if(KEY0==0)
		{
			key_up0=1;
    }
		
	 }
	 if(KEY0==1&&key_up0==1)
	 {
		key_up0=0;
    return 1;
    }
		return 0;
}



unsigned char KEY2_Scan(void)
{	 
	static char key_up2=0;//�������ɿ���־	

 	if(KEY2==1)
	{
		/*��ʱȥ���� */
	Delay(10000);	
	
		if(KEY2==1)
		{
			key_up2=1;
    }	
	 }
	 if(KEY2==0&&key_up2==1)
	 {
		key_up2=0;
    return 1;
    }
		return 0;
}
