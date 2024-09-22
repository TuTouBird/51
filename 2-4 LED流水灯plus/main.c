#include <REGX52.H>
#include<stdio.h>

void Delay1ms(unsigned int time)		//@12.000MHz
{
	unsigned char i, j;
	while(time){
		i = 2;
		j = 239;
	do
	{
		while (--j);
	} while (--i);
	time--;
	}
}

void main(){
	while(1){
		P2=0xFE;
		Delay1ms(100);
		P2=0xFD;
		Delay1ms(100);
		P2=0xFB;
		Delay1ms(100);
		P2=0xF7;
		Delay1ms(100);
		P2=0xEF;
		Delay1ms(100);
		P2=0xDF;
		Delay1ms(100);
		P2=0xBF;
		Delay1ms(100);
		P2=0x7F;
		Delay1ms(100);
}
	}
