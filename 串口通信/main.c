#include <REGX52.H>
#include "delay.h"
#include "UART.h"

unsigned char sec=0;
void main(){
	Uart1_Init();

	while(1){
	}
}

void UART_Routine(void) interrupt 4 {
  if(RI ==1 ){
			P2 = ~SBUF;
		  UART_SendByte(SBUF);
		  RI = 0;
	}
}