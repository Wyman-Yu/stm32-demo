#ifndef _USART_H_
#define _USART_H_

#include "stm32f10x.h"
#include "stdio.h"

//------------------ ∫Í∂®“Â-----------------------
#define		GPIO_Usart1		GPIOA
#define		Usart1_Out		GPIO_Pin_9
#define		Usart1_In			GPIO_Pin_10

#define		GPIO_Usart2		GPIOA
#define		Usart2_Out		GPIO_Pin_2
#define		Usart2_In			GPIO_Pin_3

#define		GPIO_Usart3		GPIOC
#define		Usart3_Out		GPIO_Pin_10
#define		Usart3_In			GPIO_Pin_11
//-------------------------------------------------

void USART_PutStr(USART_TypeDef * USARTx,u8 *buf);
void USART_Config(USART_TypeDef * USARTx,u32 BaudRate,u8 PreemptionPriority, u8 SubPriority,u8 IT_Flag );
#endif

