#include "ctront.h"
#include "stdio.h"

void Gpio_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStruct;
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE);

	GPIO_InitStruct.GPIO_Pin	= GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
	GPIO_InitStruct.GPIO_Mode	= GPIO_Mode_Out_PP;		//复用推挽输出
	GPIO_InitStruct.GPIO_Speed	= GPIO_Speed_50MHz;		//输出频率50MHz
	GPIO_Init(GPIOA, & GPIO_InitStruct);	

	GPIO_ResetBits(GPIOA,GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7);
}

extern uint8_t rx_end;
extern uint8_t rx_data;


void Ctront_Prg(void)
{
	
	if(rx_end)
	{
		rx_end = 0;
		if(rx_data == 'Q')  
		{
			GPIO_SetBits(GPIOA,GPIO_Pin_4);
		}
		if(rx_data == 'H')    
		{
			GPIO_ResetBits(GPIOA,GPIO_Pin_4);
		}
		if(rx_data == 'L') 
		{
			GPIO_SetBits(GPIOA,GPIO_Pin_5);
		}
		if(rx_data == 'R')   
		{
			GPIO_ResetBits(GPIOA,GPIO_Pin_5);
		}
		if(rx_data == 'S')    
		{
			GPIO_SetBits(GPIOA,GPIO_Pin_6);
		}
		if(rx_data == 'C')    
		{
			GPIO_ResetBits(GPIOA,GPIO_Pin_6);
		}
		if(rx_data == 'A')    
		{
			GPIO_SetBits(GPIOA,GPIO_Pin_7);
		}
		if(rx_data == 'B')    
		{
			GPIO_ResetBits(GPIOA,GPIO_Pin_7);
		}
	}
}

