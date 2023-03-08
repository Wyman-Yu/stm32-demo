#include "stm32f10x.h"
#include "Usart.h"
#include "delay.h"
#include "ctront.h"

uint8_t recvBuf[50];	//����������յ�������
uint8_t count = 0;		//ʵ�����ݵĳ���
uint8_t recvFlag = 0; //�������һ�����ݵı�־λ
u8 flag;

int main (void)
{
	
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	

	delay_init();
	USART_Config(USART1,9600,4,0,1);		//���ô���1
	USART_Config(USART2,9600,2,0,1);		//���ô���2
	Gpio_Init();
	
	while(1)
	{
		Ctront_Prg();
	}
}

