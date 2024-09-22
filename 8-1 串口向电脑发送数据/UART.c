#include <REGX52.H>

/**
  * @brief 串口初始化，4800bps@12.000MHz
  * @param 无
  * @retval 无
  */
void UART_Init(){
	SCON=0x40;
	PCON |= 0x80;		//使能波特率倍速位SMOD
	
	TMOD &= 0x0F;		
	TMOD |= 0x20;		//设置定时器1模式为模式2
	TL1 = 0xF4;		//设定定时初值
	TH1 = 0xF4;		//设定定时器重装值
	ET1 = 0;		//禁止定时器1中断
	TR1 = 1;		//启动定时器1
}

/**
  * @brief 串口发送一个字节数据
	* @param Byte:要发送的一个字节的数据
  * @retval 无
  */
void UART_SendByte(unsigned char Byte){
	SBUF=Byte;
	while(TI==0);
	TI=0;
}