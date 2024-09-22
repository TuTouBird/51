#include <REGX52.H>
#include "Timer0.h"
#include "key.h"
#include "INTRINS.h"

unsigned char KeyNum,LEDMode;

void main(){
	P2=0XFE;
	Timer0Init();
	while(1){
		KeyNum=Key();
		if(KeyNum){
			if(KeyNum==1) LEDMode++;
			if(LEDMode==2) LEDMode=0;
		}
	}
}

void Timer0_Routine() interrupt 1{
	static unsigned int T0count;
	TL0 = 0x18;		
	TH0 = 0xFC;	
	T0count++;
	if(T0count>=500){
		T0count=0;
		if(LEDMode==0) P2=_crol_(P2,1);
		if(LEDMode==1) P2=_cror_(P2,1);
	}
}
