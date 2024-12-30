#include "stm32f10x.h"                  // Device header
#include "Delay.h"



void LED_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	
	GPIO_InitTypeDef GPIO_Initstructure_C;
	GPIO_Initstructure_C.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Initstructure_C.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
	GPIO_Initstructure_C.GPIO_Speed= GPIO_Speed_50MHz;

	GPIO_Init(GPIOC,&GPIO_Initstructure_C);

	//GPIO_WriteBit(GPIOC,GPIO_Pin_0,Bit_SET);
	GPIO_SetBits(GPIOC,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7);
}
void LED_ON(uint16_t GPIO_Pin_x)
{
	GPIO_WriteBit(GPIOC,GPIO_Pin_x,Bit_RESET);
}

void LED_OFF(uint16_t GPIO_Pin_x)
{
	GPIO_WriteBit(GPIOC,GPIO_Pin_x,Bit_SET);
}


void Breath_LED(uint16_t GPIO_Pin_x)
{
	
	LED_ON(GPIO_Pin_x);
	Delay_us(99);
	LED_OFF(GPIO_Pin_x);
	Delay_us(10);
	
}







