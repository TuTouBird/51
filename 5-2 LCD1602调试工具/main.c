#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"

int a=0;
void main(){
		LCD_Init();
		LCD_ShowString(2,1,"Hello World!");
		while(1){
			LCD_ShowNum(1,1,a,3);
			Delay(1000);
			a++;
		}
}