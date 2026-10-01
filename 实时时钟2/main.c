#include <REGX52.H>
#include "LCD1602.h"
#include "DS1302.h"
#include "transto.h"
#include "timer0.h"
#include "key.h"
#include "delay.h"

unsigned char KeyNumber,MODE,POS,ACTION,TimeSet_Flash;
 
void TimeShow(void){
	  DS1302_ReadTime();
		LCD_ShowNum(1,9,Time[0],2);
		LCD_ShowString(1,11,"-");
		LCD_ShowNum(1,12,Time[1],2);
		LCD_ShowString(1,14,"-");
		LCD_ShowNum(1,15,Time[2],2);
		LCD_ShowNum(2,1,Time[3],2);
	  LCD_ShowString(2,3,":");
		LCD_ShowNum(2,4,Time[4],2);
	  LCD_ShowString(2,6,":");
		LCD_ShowNum(2,7,Time[5],2);
		LCD_ShowString(2,9,"-");
		LCD_ShowNum(2,10,Time[6],1);
}
void TimeSet(void){
  if(KeyNumber == 2){
		POS++;
		if(POS>6)POS = 0;
	}
	if(KeyNumber==3){
		Time[POS]++;
		if(Time[0]>99)Time[0]=0;
		if(Time[1]>12)Time[1]=1;
		if((Time[1]==1||Time[1]==3||Time[1]==5||Time[1]==7||Time[1]==8||Time[1]==10||Time[1]==12)){
			if(Time[2]>31)Time[2] = 1;
		}
		if((Time[1]==4||Time[1]==6||Time[1]==9||Time[1]==11)){
			if(Time[2]>30)Time[2]=1;
		}
		if(Time[1]==2){
			if((Time[0]%4==0&&Time[0]%100!=0)||Time[0]%400==0){
				if(Time[2]>29) Time[2]=1;
			}
			else{
			  if(Time[2]>28)Time[2]=1;
			}
		}
		
		if(Time[3]>23)Time[3]=0;
		if(Time[4]>59)Time[4] = 0;
		if(Time[5]>59)Time[5]=0;
		if(Time[6]>7)Time[6]=1;
	}
	if(KeyNumber==4){
		Time[POS]--;
		if(Time[0]<0)Time[0]=99;
		if(Time[1]<1)Time[1]=12;
		if((Time[1]==1||Time[1]==3||Time[1]==5||Time[1]==7||Time[1]==8||Time[1]==10||Time[1]==12)){
			if(Time[2]<1)Time[2] = 31;
		  if(Time[2]>31)Time[2] = 1;
			
		}
		if((Time[1]==4||Time[1]==6||Time[1]==9||Time[1]==11)){
			if(Time[2]<1)Time[2]=30;
			if(Time[2]>30)Time[2]=1;
		}
		if(Time[1]==2){
			if((Time[0]%4==0&&Time[0]%100!=0)||Time[0]%400==0){
				if(Time[2]<1) Time[2]=29;
				if(Time[2]>29) Time[2]=1;
			}
			else{
			  if(Time[2]<1)Time[2]=28;
				if(Time[2]>28)Time[2]=1;
			}
		}
		
		if(Time[3]<0)Time[3]=23;
		if(Time[4]<0)Time[4] = 59;
		if(Time[5]<0)Time[5]=59;
		if(Time[6]<0)Time[6]=7;
	}
}
void main(){
	LCD_Init();
	DS1302_Init();
	Timer0_Init();
	LCD_ShowString(1,1,"Time:");
	DS1302_SetTime();
	while(1){
		KeyNumber = Key();
		if(KeyNumber==1){
			if(MODE==0)MODE=1;
			else if(MODE==1){MODE=0;DS1302_SetTime();}
		}
		if(MODE==0){
			 TimeShow();
		}
		else{
			TimeSet();
			if(POS==0&&TimeSet_Flash == 1) LCD_ShowString(1,9,"  ");
			else LCD_ShowNum(1,9,Time[0],2);
			LCD_ShowString(1,11,"-");
			if(POS==1&&TimeSet_Flash == 1) LCD_ShowString(1,12,"  ");
			else LCD_ShowNum(1,12,Time[1],2);
			LCD_ShowString(1,14,"-");
			if(POS==2&&TimeSet_Flash == 1) LCD_ShowString(1,15,"  ");
			else LCD_ShowNum(1,15,Time[2],2);
			if(POS==3&&TimeSet_Flash == 1) LCD_ShowString(2,1,"  ");
			else LCD_ShowNum(2,1,Time[3],2);
			LCD_ShowString(2,3,":");
			if(POS==4&&TimeSet_Flash == 1) LCD_ShowString(2,4,"  ");
			else LCD_ShowNum(2,4,Time[4],2);
			LCD_ShowString(2,6,":");
			if(POS==5&&TimeSet_Flash == 1) LCD_ShowString(2,7,"  ");
			else LCD_ShowNum(2,7,Time[5],2);
			LCD_ShowString(2,9,"-");
			if(POS==6&&TimeSet_Flash == 1) LCD_ShowString(2,10," ");
			else LCD_ShowNum(2,10,Time[6],1);
		}
		delay(50); 
   }
}
void flash ()interrupt 1
{
	static unsigned int count = 0;
	TL0 = 0x18;
	TH0 = 0xFC;
	count++;
	  if(count>300){
			count = 0;
			TimeSet_Flash =!TimeSet_Flash;
		}
		
}