#include <REGX52.H>
#include "Delay.h"

#define MATRIX_LED_PORT P0

sbit RCK = P3^5;   //RCLK
sbit SCK = P3^6;   //SRCLK
sbit SER = P3^4;   //SER

/**
  * @brief 点阵屏初始化
  * @param 无
  * @retval 无
  */
void Matrix_Init(){
	SCK=0;
	RCK=0;
}

/**
  * @brief 74HC595写入一个字节
  * @param 要写入的字节
  * @retval 无
  */
void _74HC595_WriteByte(unsigned char Byte)
{
	unsigned char i;
	for(i=0;i<8;i++){
		SER=Byte&(0x80>>i);  
		SCK=1;
		SCK=0;
	}
	RCK=1;
	RCK=0;
//	SER=Byte&0x80;  //最高位是0SER就是0，最高位是1SER就是1，屏蔽掉低7位，SER是1位数据
//	SCK=1;
//	SCK=0;
//	SER=Byte&0x40;  
//	SCK=1;
//	SCK=0;
//	...
}

/**
  * @brief LED点阵屏显示一列数据
  * @param Column 要选择的列，范围：0~7
  * @param Data 选择列要显示的数据，高位在上，1为亮，0为灭 
	* @retval 无
  */
void MatrixLED_ShowColumn(unsigned char column,Data){
	_74HC595_WriteByte(Data);
	MATRIX_LED_PORT=~(0x80>>column);
	Delay(1);
	MATRIX_LED_PORT=0xFF;
}