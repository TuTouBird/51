#include <REGX52.H>
#include "Delay.h"
#include "Key.h"
#include "Timer0.h"
#include "shumaguan.h"

sbit Motor=P1^0;

unsigned char Counter,Compare;
unsigned char KeyNum,Speed;

void main(){
	Timer0Init();
	Compare=0;
	while(1){
		KeyNum=Key();
		if(KeyNum==1)
		{
			Speed++;
			Speed%=4;
			if(Speed==0) Compare=0;
			if(Speed==1) Compare=50;
			if(Speed==2) Compare=75;
			if(Speed==3) Compare=100;
			
		}
		shumaguan(8,Speed);
	}
}


void Timer0_Routine() interrupt 1{
	TL0 = 0x9C;		
	TH0 = 0xFF;	
	Counter++;
	Counter%=100;
	if(Counter<Compare) Motor=1;
	else Motor=0;
}