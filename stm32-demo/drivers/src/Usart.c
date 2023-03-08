#include "Usart.h"

/*
*�������򿪴���
*����һ��USART1\USART2\USART3(����3�Ѿ�������ӳ�䣬�ɰ��������и���)
*��������������
*����������ռ���ȼ�
*�����ģ���Ӧ���ȼ�
*�����壺�Ƿ����жϣ�0����������1������
*/

void USART_Config(USART_TypeDef * USARTx,u32 BaudRate,u8 PreemptionPriority, u8 SubPriority,u8 IT_Flag )
{
	GPIO_InitTypeDef  GPIO_InitStruct;
	USART_InitTypeDef  USART_InitStruct;
	NVIC_InitTypeDef  NVIC_InitStruct;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);//�ж����ȼ�����
	if(USARTx == USART1)
	{	
		//��ʱ�ӣ���Ҫ�õ����ڣ�GPIOA,����
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);

		//����USART1��Tx,�����������ģʽ
		GPIO_InitStruct.GPIO_Mode	= GPIO_Mode_AF_PP;		//�����������
		GPIO_InitStruct.GPIO_Pin	= Usart1_Out;			//Tx-->PA9
		GPIO_InitStruct.GPIO_Speed	= GPIO_Speed_50MHz;		//���Ƶ��50MHz
		GPIO_Init(GPIO_Usart1, & GPIO_InitStruct);	//��ʼ��Tx����

		//����USART1��Rx,��������ģʽ
		GPIO_InitStruct.GPIO_Mode	= GPIO_Mode_IN_FLOATING;	//��������ģʽ
		GPIO_InitStruct.GPIO_Pin	= Usart1_In;				//RX->PA10
		GPIO_Init(GPIO_Usart1, & GPIO_InitStruct);	//��ʼ��Rx����

		//��ʼ������USART1
		USART_InitStruct.USART_BaudRate		= BaudRate;  //������
		USART_InitStruct.USART_HardwareFlowControl	= USART_HardwareFlowControl_None; //������Ӳ������
		USART_InitStruct.USART_Mode			= USART_Mode_Tx | USART_Mode_Rx;  //�������ͺͽ���
		USART_InitStruct.USART_Parity		= USART_Parity_No;    //����żЧ��
		USART_InitStruct.USART_StopBits		= USART_StopBits_1;		//һλֹͣλ
		USART_InitStruct.USART_WordLength	= USART_WordLength_8b;  //���ݳ���Ϊ8λ
		USART_Init( USART1, &USART_InitStruct);		//��ʼ������USART1

		if(IT_Flag)
		{
			//�����жϵĲ���
			NVIC_InitStruct.NVIC_IRQChannel		= USART1_IRQn;	//�ж�ͨ���ţ���stm32f10x.h���ͷ�ļ���߲��ң�ѡ��궨��ΪSTM32F10X_HD
			NVIC_InitStruct.NVIC_IRQChannelCmd	= ENABLE;		//ʹ���ж�
			NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority	= PreemptionPriority;//��ռ���ȼ�
			NVIC_InitStruct.NVIC_IRQChannelSubPriority	= SubPriority;		//��Ӧ���ȼ�
			NVIC_Init(& NVIC_InitStruct);
		}

	}else if(USARTx == USART2)
	{
		//��ʱ�ӣ���Ҫ�õ����ڣ�GPIOA,����
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);

		//����USART2��Tx,�����������ģʽ
		GPIO_InitStruct.GPIO_Mode	= GPIO_Mode_AF_PP;				//�����������
		GPIO_InitStruct.GPIO_Pin	= Usart2_Out;							//Tx-->PA2
		GPIO_InitStruct.GPIO_Speed	= GPIO_Speed_50MHz;			//���Ƶ��50MHz
		GPIO_Init(GPIO_Usart2, & GPIO_InitStruct);					//��ʼ��Tx����

		//����USART2��Rx,��������ģʽ
		GPIO_InitStruct.GPIO_Mode	= GPIO_Mode_IN_FLOATING;	//��������ģʽ
		GPIO_InitStruct.GPIO_Pin	= Usart2_In;				//RX->PA3
		GPIO_Init(GPIO_Usart2, & GPIO_InitStruct);	//��ʼ��Rx����

		//��ʼ������USART2
		USART_InitStruct.USART_BaudRate		= BaudRate;  //������
		USART_InitStruct.USART_HardwareFlowControl	= USART_HardwareFlowControl_None; //������Ӳ������
		USART_InitStruct.USART_Mode			= USART_Mode_Tx | USART_Mode_Rx;  //�������ͺͽ���
		USART_InitStruct.USART_Parity		= USART_Parity_No;    //����żЧ��
		USART_InitStruct.USART_StopBits		= USART_StopBits_1;		//һλֹͣλ
		USART_InitStruct.USART_WordLength	= USART_WordLength_8b;  //���ݳ���Ϊ8λ
		USART_Init( USART2, &USART_InitStruct);		//��ʼ������USART2
		if(IT_Flag)
		{
		//�����жϵĲ���
			NVIC_InitStruct.NVIC_IRQChannel		= USART2_IRQn;	//�ж�ͨ���ţ���stm32f10x.h���ͷ�ļ���߲��ң�ѡ��궨��ΪSTM32F10X_HD
			NVIC_InitStruct.NVIC_IRQChannelCmd	= ENABLE;		//ʹ���ж�
			NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority	= PreemptionPriority;//��ռ���ȼ�
			NVIC_InitStruct.NVIC_IRQChannelSubPriority	= SubPriority;		//��Ӧ���ȼ�
			NVIC_Init(& NVIC_InitStruct);
		}
	
	}else if(USARTx == USART3)
	{
		//��ʱ�ӣ���Ҫ�õ����ڣ�GPIOB,����
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC | RCC_APB2Periph_AFIO, ENABLE);
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);

		//����USART3��Tx,�����������ģʽ
		GPIO_InitStruct.GPIO_Mode	= GPIO_Mode_AF_PP;		//�����������
		GPIO_InitStruct.GPIO_Pin	= Usart3_Out;			//Tx-->PC10
		GPIO_InitStruct.GPIO_Speed	= GPIO_Speed_50MHz;		//���Ƶ��50MHz
		GPIO_Init(GPIO_Usart3, & GPIO_InitStruct);	//��ʼ��Tx����

		//����USART2��Rx,��������ģʽ
		GPIO_InitStruct.GPIO_Mode	= GPIO_Mode_IN_FLOATING;	//��������ģʽ
		GPIO_InitStruct.GPIO_Pin	= Usart3_In;				//RX->PC11
		GPIO_Init(GPIO_Usart3, & GPIO_InitStruct);	//��ʼ��Rx����

		GPIO_PinRemapConfig( GPIO_PartialRemap_USART3, ENABLE);		//����ӳ��

		//��ʼ������USART3
		USART_InitStruct.USART_BaudRate		= BaudRate;  //������
		USART_InitStruct.USART_HardwareFlowControl	= USART_HardwareFlowControl_None; //������Ӳ������
		USART_InitStruct.USART_Mode			= USART_Mode_Tx | USART_Mode_Rx;  //�������ͺͽ���
		USART_InitStruct.USART_Parity		= USART_Parity_No;    //����żЧ��
		USART_InitStruct.USART_StopBits		= USART_StopBits_1;		//һλֹͣλ
		USART_InitStruct.USART_WordLength	= USART_WordLength_8b;  //���ݳ���Ϊ8λ
		USART_Init( USART3, &USART_InitStruct);		//��ʼ������USART1
		if(IT_Flag)
		{
		//�����жϵĲ���
			NVIC_InitStruct.NVIC_IRQChannel		= USART3_IRQn;	//�ж�ͨ���ţ���stm32f10x.h���ͷ�ļ���߲��ң�ѡ��궨��ΪSTM32F10X_HD
			NVIC_InitStruct.NVIC_IRQChannelCmd	= ENABLE;		//ʹ���ж�
			NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority	= PreemptionPriority;//��ռ���ȼ�
			NVIC_InitStruct.NVIC_IRQChannelSubPriority	= SubPriority;		//��Ӧ���ȼ�
			NVIC_Init(& NVIC_InitStruct);
		}
		
	}
		if(IT_Flag)
		{
			USART_ITConfig(USARTx,USART_IT_RXNE , ENABLE);  //�����жϵĽ��ձ�־λ
			USART_ITConfig(USARTx,USART_IT_IDLE , ENABLE);
		}
	
	USART_ClearFlag( USARTx,  USART_FLAG_RXNE | USART_FLAG_TC);	//�����־λ

	USART_Cmd( USARTx, ENABLE);	//��������
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
