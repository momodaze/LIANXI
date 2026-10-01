#include <REGX52.H>
#include "LCD1602.h"
#include "DS1302.h"
#include "transto.h"

void main(){
	LCD_Init();
	DS1302_Init();
	LCD_ShowString(1,1,"Time:");
	DS1302_SetTime();
	while(1){
		DS1302_ReadTime();
		LCD_ShowNum(1,9,Time[0],2);
		LCD_ShowString(1,11,"-");
		LCD_ShowNum(1,12,Time[1],2);
		LCD_ShowString(1,14,"-");
		LCD_ShowNum(1,15,Time[2],2);
		LCD_ShowNum(2,1,Time[3],2);
		LCD_ShowString(2,3,"-");
		LCD_ShowNum(2,4,Time[4],2);
		LCD_ShowString(2,6,"-");
		LCD_ShowNum(2,7,Time[5],2);
		LCD_ShowString(2,9,"-");
		LCD_ShowNum(2,10,Time[6],2);
   }
}