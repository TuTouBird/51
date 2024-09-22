#include <REGX52.H>
#include "Delay.h"
#include "UART.h"

unsigned int num;

void main(){
	UART_Init();
	while(1){
		UART_SendByte(num);
		num++;
		Delay(1000);
	}
}