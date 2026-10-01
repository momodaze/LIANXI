#ifndef _DS1302_H_
#define _DS1302_H_


void DS1302_init();
extern unsigned char Time[];
unsigned char DS1302_readByte(unsigned char command);
void DS1302_writeByte(unsigned char Command,unsigned char dat);
void DS1302_SetTime();
void DS1302_ReadTime();
#endif