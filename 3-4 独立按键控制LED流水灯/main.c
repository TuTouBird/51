#include <REGX52.H>

void Delay(unsigned int num)
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

void main(){
	unsigned int num=0;
	P2=~0x01;
	while(1){
		if(P3_1==0){
			Delay(20);
			while(P3_1==0);
			Delay(20);
			
			num++;
			if(num==8)
				num=0;
			P2=~(0x01<<num);
		}
		if(P3_0==0){
			Delay(20);
			while(P3_0==0);
			Delay(20);
			
			if(num==0)
				num=7;
			else num--;
			P2=~(0x01<<num);
		}
	}
}


