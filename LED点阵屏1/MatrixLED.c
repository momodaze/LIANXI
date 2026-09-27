#include <REGX52.H>
#include "delay.h"
#include "74HC595.h"

/**
  *@brief 选取点阵屏列位置和对应列led分布
  *@param column： 第几列（0-7） data: 小灯的分布
  *@retravl 无
*/
#define LED_COLOMN_POSE P0
sbit RCK = P3^5;
sbit SER = P3^4;
sbit SCK = P3^6;
void MatrixLED_ShowColor(unsigned char Column,Data){
	_74HC595_writeByte(0x00);
	LED_COLOMN_POSE = ~(0x80>>Column);
	_74HC595_writeByte(Data);
	Delay1ms();
	LED_COLOMN_POSE = 0xFF;
	_74HC595_writeByte(0x00);
}
void Init_LED(){
	RCK = 0;
	SCK = 0;
}