#include <REGX52.H>
#include "delay.h"
unsigned char MatrixKey() {
  unsigned char KeyNum = 0;
	//采用列检查
	//并且通过覆盖的方式快速给电平
	//给所有口配1
	P1 = 0xFF;
	//给选中的列
	P1_3 = 0;
	//判断按下的按键
	//1.判断按键按下
	//2.延时消抖
	//3.继续检测是否按下
	//4.一直按着的话不显示
	//松手获取数值
    if(P1_7 == 0) { Delay10ms(1); if(P1_7==0){ while(P1_7==0); KeyNum=1; } }
    if(P1_6 == 0) { Delay10ms(1); if(P1_6==0){ while(P1_6==0); KeyNum=5; } }
    if(P1_5 == 0) { Delay10ms(1); if(P1_5==0){ while(P1_5==0); KeyNum=9; } }
    if(P1_4 == 0) { Delay10ms(1); if(P1_4==0){ while(P1_4==0); KeyNum=13; } }

    P1 = 0xFF; P1_2 = 0;
    if(P1_7 == 0) { Delay10ms(1); if(P1_7==0){ while(P1_7==0); KeyNum=2; } }
    if(P1_6 == 0) { Delay10ms(1); if(P1_6==0){ while(P1_6==0); KeyNum=6; } }
    if(P1_5 == 0) { Delay10ms(1); if(P1_5==0){ while(P1_5==0); KeyNum=10; } }
    if(P1_4 == 0) { Delay10ms(1); if(P1_4==0){ while(P1_4==0); KeyNum=14; } }

    P1 = 0xFF; P1_1 = 0;
    if(P1_7 == 0) { Delay10ms(1); if(P1_7==0){ while(P1_7==0); KeyNum=3; } }
    if(P1_6 == 0) { Delay10ms(1); if(P1_6==0){ while(P1_6==0); KeyNum=7; } }
    if(P1_5 == 0) { Delay10ms(1); if(P1_5==0){ while(P1_5==0); KeyNum=11; } }
    if(P1_4 == 0) { Delay10ms(1); if(P1_4==0){ while(P1_4==0); KeyNum=15; } }

    P1 = 0xFF; P1_0 = 0;
    if(P1_7 == 0) { Delay10ms(1); if(P1_7==0){ while(P1_7==0); KeyNum=4; } }
    if(P1_6 == 0) { Delay10ms(1); if(P1_6==0){ while(P1_6==0); KeyNum=8; } }
    if(P1_5 == 0) { Delay10ms(1); if(P1_5==0){ while(P1_5==0); KeyNum=12; } }
    if(P1_4 == 0) { Delay10ms(1); if(P1_4==0){ while(P1_4==0); KeyNum=16; } }
	return KeyNum;
}