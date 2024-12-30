#include "stm32f10x.h"

#define DATA GPIO_Pin_3 
#define LCLK GPIO_Pin_4 
#define SCLK GPIO_Pin_5 

unsigned char Num[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};


void Tube_Init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	
	GPIO_InitTypeDef GPIO_Initstructure_C;
	GPIO_Initstructure_C.GPIO_Mode=GPIO_Mode_Out_PP ;
	GPIO_Initstructure_C.GPIO_Pin=GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12 ;
	GPIO_Initstructure_C.GPIO_Speed= GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&GPIO_Initstructure_C);

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_Initstructure_B;
	GPIO_Initstructure_B.GPIO_Mode=GPIO_Mode_Out_PP ;
	GPIO_Initstructure_B.GPIO_Pin=GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5 ;
	GPIO_Initstructure_B.GPIO_Speed= GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_Initstructure_B);
}

void Tube_Duan(uint8_t Duan)
{
    switch (Duan)
    {
        case 0:
            GPIO_WriteBit(GPIOC,GPIO_Pin_12,Bit_RESET);//0
            GPIO_WriteBit(GPIOC,GPIO_Pin_11,Bit_RESET);//0
            GPIO_WriteBit(GPIOC,GPIO_Pin_10,Bit_RESET);//0
            break;
        case 1:
            GPIO_WriteBit(GPIOC,GPIO_Pin_12,Bit_RESET);//0
            GPIO_WriteBit(GPIOC,GPIO_Pin_11,Bit_RESET);//0
            GPIO_WriteBit(GPIOC,GPIO_Pin_10,Bit_SET);  //1
            break;
        case 2:
            GPIO_WriteBit(GPIOC,GPIO_Pin_12,Bit_RESET);//0
            GPIO_WriteBit(GPIOC,GPIO_Pin_11,Bit_SET);  //1
            GPIO_WriteBit(GPIOC,GPIO_Pin_10,Bit_RESET);//0
            break;
        case 3:
            GPIO_WriteBit(GPIOC,GPIO_Pin_12,Bit_RESET);//0
            GPIO_WriteBit(GPIOC,GPIO_Pin_11,Bit_SET);  //1
            GPIO_WriteBit(GPIOC,GPIO_Pin_10,Bit_SET);  //1
            break;
        case 4:
            GPIO_WriteBit(GPIOC,GPIO_Pin_12,Bit_SET);  //1
            GPIO_WriteBit(GPIOC,GPIO_Pin_11,Bit_RESET);//0
            GPIO_WriteBit(GPIOC,GPIO_Pin_10,Bit_RESET);//0
            break;
        case 5:
            GPIO_WriteBit(GPIOC,GPIO_Pin_12,Bit_SET);  //1
            GPIO_WriteBit(GPIOC,GPIO_Pin_11,Bit_RESET);//0
            GPIO_WriteBit(GPIOC,GPIO_Pin_10,Bit_SET);  //1
            break;
        case 6:
            GPIO_WriteBit(GPIOC,GPIO_Pin_12,Bit_SET);  //1
            GPIO_WriteBit(GPIOC,GPIO_Pin_11,Bit_SET);  //1
            GPIO_WriteBit(GPIOC,GPIO_Pin_10,Bit_RESET);//0
            break;
        case 7:
            GPIO_WriteBit(GPIOC,GPIO_Pin_12,Bit_SET);  //1
            GPIO_WriteBit(GPIOC,GPIO_Pin_11,Bit_SET);  //1
            GPIO_WriteBit(GPIOC,GPIO_Pin_10,Bit_SET);  //1
            break;
        default:break;
    }
}

void Tube_Wei(uint8_t Wei)
{

    GPIO_WriteBit(GPIOB,LCLK,Bit_RESET);
    GPIO_WriteBit(GPIOB,SCLK,Bit_RESET);
    uint8_t i;
    for(i=0;i<8;i++)
    {
        if(Num[Wei]&(0x80>>i)==1)
        {
            GPIO_WriteBit(GPIOB,DATA,Bit_SET);
        }
        else GPIO_WriteBit(GPIOB,DATA,Bit_RESET);
        GPIO_WriteBit(GPIOB,SCLK,Bit_SET);
        GPIO_WriteBit(GPIOB,SCLK,Bit_RESET);
    }
    GPIO_WriteBit(GPIOB,LCLK,Bit_SET);
    
}



