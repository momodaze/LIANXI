#include <REGX52.H>
#include "key.h"
#include "timer0.h"
#include "move.h"

unsigned char key_state = 0;
void main(){
		Timer0_Init();
	  P2 = 0xFE;
		while(1){
				key_state = Key();
		if(key_state)
			  dir_trigger(key_state);
		}
}

void Timer0_Routine() interrupt 1{
	static unsigned int T0count;
	TL0 = 0x66;
	TH0 = 0xFC;
	T0count++;
	if(T0count>1000){
		T0count = 0;
		move();
	}
}