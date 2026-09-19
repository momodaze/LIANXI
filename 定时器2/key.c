#include <REGX52.H>
#include "delay.h"

unsigned char Key(){
	unsigned char keyNum=0;
		if(P3_0 == 0){
			Delay100ms(1);
			if(P3_0 == 0){
				while(P3_0 == 0);
				Delay100ms(1);  
				keyNum = 1;
			}
		}
		if(P3_1 == 0){
			Delay100ms(1);
			if(P3_1==0){
				while(P3_1 == 0);
				Delay100ms(1);  
				keyNum = 2;
			}
		}
	return keyNum;
}
