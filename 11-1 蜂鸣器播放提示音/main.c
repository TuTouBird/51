#include <REGX52.H>
#include "Key.h"
#include "shumaguan.h"
#include "Buzzer.h"

unsigned char keynum;

void main(){
	shumaguan(8,0);
	while(1){
		keynum=Key();
		if(keynum)
		{
			shumaguan(8,keynum);
			Buzzer_Time(100);
	}
}
}