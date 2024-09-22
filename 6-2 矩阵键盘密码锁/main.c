#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned int KeyNum;
unsigned int Password,cnt,flag;

void main(){
	LCD_Init();
	
	while(1){
		KeyNum=MatrixKey();
		
		if(KeyNum==16&&flag==0) {LCD_ShowString(1,1,"Password:");flag=1;}
		
		else if(KeyNum&&flag==1){
			
			if(KeyNum==11){
				if(cnt){
						LCD_ShowString(1,cnt+9," ");
						cnt--;
						Password/=10;
				}
			}
			
			else if(KeyNum<=10&&cnt<4){
				Password*=10;
				Password+=KeyNum%10;
				cnt++;
				LCD_ShowChar(1,9+cnt,'*');
			}
			
			else if(KeyNum==12){
				if(Password==8888){
					LCD_ShowString(2,1,"OK!   ");
					Password=0;
					cnt=0;
					Delay(1000);
					LCD_ShowString(1,1," Genshin impact ");
					LCD_ShowString(2,1,"     start!     ");
				}
				else{
					LCD_ShowString(2,1,"ERROR!");
					Password=0;
					cnt=0;
					Delay(1000);
					LCD_ShowString(2,1,"      ");
					LCD_ShowString(1,10,"    ");
				}
			}
			
			else if(KeyNum==13){
				LCD_ShowString(1,1,"      BYE!      ");
				LCD_ShowString(2,1,"    jia na!     ");
				Delay(1500);
				flag=0;
				break;
			}
			
		}
	}
	
}
