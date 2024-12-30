#include "stm32f10x.h"                  // Device header
#include "Beep.h"
#include "Delay.h"

void EXTI0_Init(void)
{
	//时钟配置
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	//EXTI和NVIC的时钟一直开启，不需要配置时钟
	
	//端口配置
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	//AFIO配置
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource0);
	
	//EXTI配置
	EXTI_InitTypeDef EXTI_InitSturcture;
	EXTI_InitSturcture.EXTI_Line = EXTI_Line0;
	EXTI_InitSturcture.EXTI_LineCmd = ENABLE;
	EXTI_InitSturcture.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitSturcture.EXTI_Trigger = EXTI_Trigger_Rising;
	
	EXTI_Init(&EXTI_InitSturcture);
	
	//NVIC配置
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitTypeDef NVIC_InitSturcture;
	NVIC_InitSturcture.NVIC_IRQChannel = EXTI0_IRQn;
	NVIC_InitSturcture.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitSturcture.NVIC_IRQChannelPreemptionPriority =1 ;
	NVIC_InitSturcture.NVIC_IRQChannelSubPriority = 1;
	
	NVIC_Init(&NVIC_InitSturcture);
}

void EXTI0_IRQHandler(void)
{
	if(EXTI_GetFlagStatus(EXTI_Line0)==1)
	{
		EXTI_ClearFlag(EXTI_Line0);
	}
}





