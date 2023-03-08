#include "Usart.h"

/*
*描述：打开串口
*参数一：USART1\USART2\USART3(串口3已经部分重映射，可按需求自行更改)
*参数二：波特率
*参数三：抢占优先级
*参数四：响应优先级
*参数五：是否开启中断，0：不开启，1：开启
*/

void USART_Config(USART_TypeDef * USARTx,u32 BaudRate,u8 PreemptionPriority, u8 SubPriority,u8 IT_Flag )
{
	GPIO_InitTypeDef  GPIO_InitStruct;
	USART_InitTypeDef  USART_InitStruct;
	NVIC_InitTypeDef  NVIC_InitStruct;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);//中断优先级分组
	if(USARTx == USART1)
	{	
		//打开时钟，需要用到串口，GPIOA,复用
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);

		//配置USART1的Tx,复用推挽输出模式
		GPIO_InitStruct.GPIO_Mode	= GPIO_Mode_AF_PP;		//复用推挽输出
		GPIO_InitStruct.GPIO_Pin	= Usart1_Out;			//Tx-->PA9
		GPIO_InitStruct.GPIO_Speed	= GPIO_Speed_50MHz;		//输出频率50MHz
		GPIO_Init(GPIO_Usart1, & GPIO_InitStruct);	//初始化Tx引脚

		//配置USART1的Rx,浮空输入模式
		GPIO_InitStruct.GPIO_Mode	= GPIO_Mode_IN_FLOATING;	//浮空输入模式
		GPIO_InitStruct.GPIO_Pin	= Usart1_In;				//RX->PA10
		GPIO_Init(GPIO_Usart1, & GPIO_InitStruct);	//初始化Rx引脚

		//初始化串口USART1
		USART_InitStruct.USART_BaudRate		= BaudRate;  //波特率
		USART_InitStruct.USART_HardwareFlowControl	= USART_HardwareFlowControl_None; //不能能硬件流控
		USART_InitStruct.USART_Mode			= USART_Mode_Tx | USART_Mode_Rx;  //启动发送和接收
		USART_InitStruct.USART_Parity		= USART_Parity_No;    //无奇偶效验
		USART_InitStruct.USART_StopBits		= USART_StopBits_1;		//一位停止位
		USART_InitStruct.USART_WordLength	= USART_WordLength_8b;  //数据长度为8位
		USART_Init( USART1, &USART_InitStruct);		//初始化串口USART1

		if(IT_Flag)
		{
			//开启中断的部分
			NVIC_InitStruct.NVIC_IRQChannel		= USART1_IRQn;	//中断通道号，在stm32f10x.h这个头文件里边查找，选择宏定义为STM32F10X_HD
			NVIC_InitStruct.NVIC_IRQChannelCmd	= ENABLE;		//使能中断
			NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority	= PreemptionPriority;//抢占优先级
			NVIC_InitStruct.NVIC_IRQChannelSubPriority	= SubPriority;		//响应优先级
			NVIC_Init(& NVIC_InitStruct);
		}

	}else if(USARTx == USART2)
	{
		//打开时钟，需要用到串口，GPIOA,复用
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);

		//配置USART2的Tx,复用推挽输出模式
		GPIO_InitStruct.GPIO_Mode	= GPIO_Mode_AF_PP;				//复用推挽输出
		GPIO_InitStruct.GPIO_Pin	= Usart2_Out;							//Tx-->PA2
		GPIO_InitStruct.GPIO_Speed	= GPIO_Speed_50MHz;			//输出频率50MHz
		GPIO_Init(GPIO_Usart2, & GPIO_InitStruct);					//初始化Tx引脚

		//配置USART2的Rx,浮空输入模式
		GPIO_InitStruct.GPIO_Mode	= GPIO_Mode_IN_FLOATING;	//浮空输入模式
		GPIO_InitStruct.GPIO_Pin	= Usart2_In;				//RX->PA3
		GPIO_Init(GPIO_Usart2, & GPIO_InitStruct);	//初始化Rx引脚

		//初始化串口USART2
		USART_InitStruct.USART_BaudRate		= BaudRate;  //波特率
		USART_InitStruct.USART_HardwareFlowControl	= USART_HardwareFlowControl_None; //不能能硬件流控
		USART_InitStruct.USART_Mode			= USART_Mode_Tx | USART_Mode_Rx;  //启动发送和接收
		USART_InitStruct.USART_Parity		= USART_Parity_No;    //无奇偶效验
		USART_InitStruct.USART_StopBits		= USART_StopBits_1;		//一位停止位
		USART_InitStruct.USART_WordLength	= USART_WordLength_8b;  //数据长度为8位
		USART_Init( USART2, &USART_InitStruct);		//初始化串口USART2
		if(IT_Flag)
		{
		//开启中断的部分
			NVIC_InitStruct.NVIC_IRQChannel		= USART2_IRQn;	//中断通道号，在stm32f10x.h这个头文件里边查找，选择宏定义为STM32F10X_HD
			NVIC_InitStruct.NVIC_IRQChannelCmd	= ENABLE;		//使能中断
			NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority	= PreemptionPriority;//抢占优先级
			NVIC_InitStruct.NVIC_IRQChannelSubPriority	= SubPriority;		//响应优先级
			NVIC_Init(& NVIC_InitStruct);
		}
	
	}else if(USARTx == USART3)
	{
		//打开时钟，需要用到串口，GPIOB,复用
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC | RCC_APB2Periph_AFIO, ENABLE);
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);

		//配置USART3的Tx,复用推挽输出模式
		GPIO_InitStruct.GPIO_Mode	= GPIO_Mode_AF_PP;		//复用推挽输出
		GPIO_InitStruct.GPIO_Pin	= Usart3_Out;			//Tx-->PC10
		GPIO_InitStruct.GPIO_Speed	= GPIO_Speed_50MHz;		//输出频率50MHz
		GPIO_Init(GPIO_Usart3, & GPIO_InitStruct);	//初始化Tx引脚

		//配置USART2的Rx,浮空输入模式
		GPIO_InitStruct.GPIO_Mode	= GPIO_Mode_IN_FLOATING;	//浮空输入模式
		GPIO_InitStruct.GPIO_Pin	= Usart3_In;				//RX->PC11
		GPIO_Init(GPIO_Usart3, & GPIO_InitStruct);	//初始化Rx引脚

		GPIO_PinRemapConfig( GPIO_PartialRemap_USART3, ENABLE);		//部分映射

		//初始化串口USART3
		USART_InitStruct.USART_BaudRate		= BaudRate;  //波特率
		USART_InitStruct.USART_HardwareFlowControl	= USART_HardwareFlowControl_None; //不能能硬件流控
		USART_InitStruct.USART_Mode			= USART_Mode_Tx | USART_Mode_Rx;  //启动发送和接收
		USART_InitStruct.USART_Parity		= USART_Parity_No;    //无奇偶效验
		USART_InitStruct.USART_StopBits		= USART_StopBits_1;		//一位停止位
		USART_InitStruct.USART_WordLength	= USART_WordLength_8b;  //数据长度为8位
		USART_Init( USART3, &USART_InitStruct);		//初始化串口USART1
		if(IT_Flag)
		{
		//开启中断的部分
			NVIC_InitStruct.NVIC_IRQChannel		= USART3_IRQn;	//中断通道号，在stm32f10x.h这个头文件里边查找，选择宏定义为STM32F10X_HD
			NVIC_InitStruct.NVIC_IRQChannelCmd	= ENABLE;		//使能中断
			NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority	= PreemptionPriority;//抢占优先级
			NVIC_InitStruct.NVIC_IRQChannelSubPriority	= SubPriority;		//响应优先级
			NVIC_Init(& NVIC_InitStruct);
		}
		
	}
		if(IT_Flag)
		{
			USART_ITConfig(USARTx,USART_IT_RXNE , ENABLE);  //启动中断的接收标志位
			USART_ITConfig(USARTx,USART_IT_IDLE , ENABLE);
		}
	
	USART_ClearFlag( USARTx,  USART_FLAG_RXNE | USART_FLAG_TC);	//清除标志位

	USART_Cmd( USARTx, ENABLE);	//启动串口
}


int fputc(int ch,FILE * f)
{
	USART_SendData(USART1, ch);
	while(USART_GetFlagStatus(USART1,USART_FLAG_TC)  !=  SET);
	return ch;
}

void USART_PutStr(USART_TypeDef * USARTx,u8 *buf)
{
	while(USART_GetFlagStatus(USARTx,USART_FLAG_TC) == RESET);
    while(*buf){
        USART_SendData(USARTx,*buf++);
        while(USART_GetFlagStatus(USARTx,USART_FLAG_TXE) == RESET);

    }
   // while(USART_GetFlagStatus(USARTx,USART_FLAG_TC) == RESET);
}
