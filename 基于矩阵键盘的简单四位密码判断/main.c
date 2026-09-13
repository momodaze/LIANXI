#include <REGX52.H>
#include "LCD1602.h"
#include "delay.h"
#include "MatrixKey.h"


void main(){
	unsigned char a;
	LCD_Init();
	LCD_ShowString(1,1,"password");
	while(1){
		a = MatrixKey();
		if(a){
		LCD_ShowNum(2,1,a,2);
		}
	}
		
}