#include <REGX52.H>

void Timer1_Init()		//100us@12.000MHz
{
	TMOD &= 0x0F;		
	TMOD |= 0x10;		//设置定时器模式为模式1
	TL1 = 0x9C;		
	TH1 = 0xFF;		//设置定时初值
	TF1 = 0;		//清除TF0标志，TF0为T0中断请求标志位
	TR1 = 1;		//定时器0开始计时，TR0为定时器0运行控制位，TR0=1允许T0计数，TR0=0不允许
	ET1=1;	//允许中断
	EA=1;   //EA=1，CPU允许中断；EA=0，CPU禁止中断
	PT1=0;  //中断优先级设置
}

/*定时器中断函数模板*/
/*
void Timer1_Routine() interrupt 3{
	static unsigned int T1count;
	TL1 = 0x9C;		
	TH1 = 0xFF;	
	T1count++;
	if(T1count>=1000){
		T1count=0;
	}
}

*/