#include <REGX52.H>
#include "Delay.h"

#define MATRIX_LED_PORT P0

sbit RCK = P3^5;   //RCLK
sbit SCK = P3^6;   //SRCLK
sbit SER = P3^4;   //SER

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
	MATRIX_LED_PORT=~(0x80>>column);   //选择列，0有效
	Delay(1);
	MATRIX_LED_PORT=0xFF;
}

void main(){
	SCK=0;
	RCK=0;
	while(1){
		MatrixLED_ShowColumn(0,0x3C);
		MatrixLED_ShowColumn(1,0x42);
		MatrixLED_ShowColumn(2,0xA9);
		MatrixLED_ShowColumn(3,0x85);
		MatrixLED_ShowColumn(4,0x85);
		MatrixLED_ShowColumn(5,0xA9);
		MatrixLED_ShowColumn(6,0x42);
		MatrixLED_ShowColumn(7,0x3C);
	}
}