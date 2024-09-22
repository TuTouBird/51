#include <REGX52.H>
#include "Timer0.h"
#include "Key.h"
#include "shumaguan.h"
#include "Delay.h"
#include "AT24C02.h"


unsigned char KeyNum;
unsigned char Min,Sec,MiniSec;
unsigned char RunFlag;


void main(){
	Timer0_Init();
	while(1){
		KeyNum=Key();
		if(KeyNum==1) 
		{
			RunFlag=!RunFlag;
		}
		if(KeyNum==2) 
		{
			Min=0;
			Sec=0;
			MiniSec=0;
			RunFlag=0;
		}
		if(KeyNum==3) 
		{
			AT24C02_WriteByte(0,Min);
			Delay(5);
			AT24C02_WriteByte(1,Sec);
			Delay(5);
			AT24C02_WriteByte(2,MiniSec);
			Delay(5);
		}
		if(KeyNum==4) 
		{
			Min=AT24C02_ReadByte(0);
			Sec=AT24C02_ReadByte(1);
			MiniSec=AT24C02_ReadByte(2);
		}
		Nixie_SetBuff(1,Min/10);
		Nixie_SetBuff(2,Min%10);
		Nixie_SetBuff(3,11);
		Nixie_SetBuff(4,Sec/10);
		Nixie_SetBuff(5,Sec%10);
		Nixie_SetBuff(6,11);
		Nixie_SetBuff(7,MiniSec/10);
		Nixie_SetBuff(8,MiniSec%10);
	}
}


void Sec_Loop(){
	if(RunFlag){
		MiniSec++;
		if(MiniSec>=100)
		{
			MiniSec=0;
			Sec++;
			if(Sec>=60){
				Sec=0;
				Min++;
				if(Min>=60){
				Min=0;
				}
			}
		}
	}
}

void Timer0_Routine() interrupt 1{
	static unsigned int T0count1,T0count2,T0count3;
	TL0 = 0x18;		
	TH0 = 0xFC;	
	T0count1++;
	if(T0count1>=20){
		T0count1=0;
		Key_Loop();
	}
	T0count2++;
	if(T0count2>=2){
		T0count2=0;
		Nixie_Loop();
	}
	T0count3++;
	if(T0count3>=10){
		T0count3=0;
		Sec_Loop();
	}
}