#include <REGX52.H>

void Timer0Init()		//1毫秒@12.000MHz
{
	TMOD &= 0xF0;		
	TMOD |= 0x01;		//设置定时器模式为模式1
	TL0 = 0x18;		
	TH0 = 0xFC;		//设置定时初值
	TF0 = 0;		//清除TF0标志，TF0为T0中断请求标志位
	TR0 = 1;		//定时器0开始计时，TR0为定时器0运行控制位，TR0=1允许T0计数，TR0=0不允许
	ET0=1;	//允许中断
	EA=1;   //EA=1，CPU允许中断；EA=0，CPU禁止中断
	PT0=0;  //中断优先级设置
}

/*定时器中断函数模板*/
/*
void Timer0_Routine() interrupt 1{
	static unsigned int T0count;
	TL0 = 0x18;		
	TH0 = 0xFC;	
	T0count++;
	if(T0count>=1000){
		T0count=0;
	}
}

*/