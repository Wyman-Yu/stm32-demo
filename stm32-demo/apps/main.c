#include "stm32f10x.h"
#include "Usart.h"
#include "delay.h"
#include "ctront.h"

uint8_t recvBuf[50];	//存放蓝牙接收到的数据
uint8_t count = 0;		//实际数据的长度
uint8_t recvFlag = 0; //接收完成一次数据的标志位
u8 flag;

int main (void)
{
	
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	

	delay_init();
	USART_Config(USART1,9600,4,0,1);		//配置串口1
	USART_Config(USART2,9600,2,0,1);		//配置串口2
	Gpio_Init();
	
	while(1)
	{
		Ctront_Prg();
	}
}

