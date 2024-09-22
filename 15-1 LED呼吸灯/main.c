#include <REGX52.H>

sbit LED=P2^0;

void Delay(unsigned int t)
{
	while(t--);
}

void main(){
	unsigned int Time,n;
	while(1){
		for(Time=0;Time<100;Time++)
		{
			for(n=0;n<20;n++)
			{
				LED=0;
				Delay(Time);
				LED=1;
				Delay(100-Time);
			}
		}
		
		for(Time=100;Time>0;Time--)
		{
			for(n=0;n<20;n++)
			{
				LED=0;
				Delay(Time);
				LED=1;
				Delay(100-Time);
			}
		}
	}
}