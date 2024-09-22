#include <REGX52.H>

void Delay1ms(unsigned int n)		//@12.000MHz
{
	unsigned char i, j;
	
	while(n){
		i = 2;
		j = 239;
	do
	{
		while (--j);
	} while (--i);
	n--;
	}
}


void main(){
	while(1){
		P2=0xFF;
		Delay1ms(1000);
		while(P2 != 0x00){
			P2=P2<<1;
			Delay1ms(100);
		}
	}
}