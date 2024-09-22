#include <REGX52.H>

void Delay1ms(unsigned int num)		//@12.000MHz
{
	unsigned char i, j;
	while(num--){
	i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);
	}
}

unsigned int shumaguan[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};

void fun(unsigned int num1,unsigned int num2){
	switch(num1){
		case 1:P2_4=0;P2_3=0;P2_2=0;break;
		case 2:P2_4=0;P2_3=0;P2_2=1;break;
		case 3:P2_4=0;P2_3=1;P2_2=0;break;
		case 4:P2_4=0;P2_3=1;P2_2=1;break;
		case 5:P2_4=1;P2_3=0;P2_2=0;break;
		case 6:P2_4=1;P2_3=0;P2_2=1;break;
		case 7:P2_4=1;P2_3=1;P2_2=0;break;
		case 8:P2_4=1;P2_3=1;P2_2=1;break;
	}
	P0=shumaguan[num2];
	Delay1ms(1);
	P0=0x00;
}
void main(){
	
	while(1){
		fun(1,1);
		fun(2,2);
		fun(3,3);
		fun(4,4);
		fun(5,5);
		fun(6,6);
		fun(7,7);
		fun(8,8);
	}
}