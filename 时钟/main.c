#include <REGX52.H>
#include "delay.h"
#include "timer0.h"
#include "LCD1602.h"

unsigned char sec = 0;
unsigned char min = 0;
unsigned char hour = 0;
unsigned char flag = 0;
void main(){
	LCD_Init();
	LCD_ShowString(1,1,"clock");
	Timer0_Init();
	while(1){
		if(flag){
			flag = 0;
			sec++;
		if(sec==60){sec = 0;min++;}
		if(min == 60){min = 0;hour++;}
		if(hour == 24) hour = 0;
	}
		
		LCD_ShowNum(2,1,hour,2);
		LCD_ShowString(2,3,":");
		LCD_ShowNum(2,4,min,2);
		LCD_ShowString(2,6,":");
		LCD_ShowNum(2,7,sec,2);
 }
}
void Timer0_Routine() interrupt 1{
	  static unsigned int T0count = 0;
		TL0 = 0x66;			
	  TH0 = 0xFC;	
	  T0count++;
		if(T0count>1000){
			T0count = 0;
			flag = 1;
		}
}