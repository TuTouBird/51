#include <REGX52.H>
#include<INTRINS.H>

void Delay1000ms()		//@12.000MHz
{
	unsigned char i, j, k;

	_nop_();
	i = 8;
	j = 154;
	k = 122;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void main(){
	while(1){
		P2=0x00;
		Delay1000ms();
	  P2=0XFF;
		Delay1000ms();
	}
}
