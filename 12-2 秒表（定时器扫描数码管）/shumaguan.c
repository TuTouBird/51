#include <REGX52.H>
#include "Delay.h"

unsigned char Nixie_Buff[9]={0,10,10,10,10,10,10,10,10};

unsigned int NUM[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x00,0x40};

void Nixie_SetBuff(unsigned char Location,Number)
{
	Nixie_Buff[Location]=Number;
}


void Nixie_Scan(unsigned char num1,num2)
{
	P0=0x00;
	switch(num1){
		case 8:P2_4=0;P2_3=0;P2_2=0;break;
		case 7:P2_4=0;P2_3=0;P2_2=1;break;
		case 6:P2_4=0;P2_3=1;P2_2=0;break;
		case 5:P2_4=0;P2_3=1;P2_2=1;break;
		case 4:P2_4=1;P2_3=0;P2_2=0;break;
		case 3:P2_4=1;P2_3=0;P2_2=1;break;
		case 2:P2_4=1;P2_3=1;P2_2=0;break;
		case 1:P2_4=1;P2_3=1;P2_2=1;break;
	}
	P0=NUM[num2];
}

void Nixie_Loop()
{
	static unsigned char i=1;
	Nixie_Scan(i,Nixie_Buff[i]);
	i++;
	if(i>8) {i=1;}
}