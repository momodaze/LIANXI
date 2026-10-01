#include <REGX52.H>
#include "transto.h"

sbit DS1302_SCLK = P3^6;
sbit DS1302_CE = P3^5;
sbit DS1302_IO = P3^4;

#define DS_SECOND 0x80
#define DS_MINUTE 0x82
#define DS_HOUR   0x84
#define DS_DATE   0x86
#define DS_MONTH  0x88
#define DS_DAY    0x8A
#define DS_YEAR   0x8C
#define DS_WP     0x8E
 char Time[]={26,10,1,17,48,20,4};
void DS1302_Init(){
	DS1302_CE = 0;
	DS1302_SCLK = 0;
}
unsigned char DS1302_readByte(unsigned char command){
	unsigned char dat = 0;
	unsigned char i = 0;
	command|= 0x01;
  DS1302_CE = 1;
	for(i=0;i<8;i++){
	  DS1302_IO = command&(0x01<<i);
		DS1302_SCLK = 0;
		DS1302_SCLK = 1;
	}
	for(i = 0;i<8;i++){	
		DS1302_SCLK = 1;
		DS1302_SCLK = 0;
		if(DS1302_IO){
			dat|= (0x01<<i);
		}
	}
	DS1302_CE = 0;
	DS1302_IO = 0;
	return dat;
}


void DS1302_writeByte(unsigned char command, unsigned char dat){
    unsigned char i;
    DS1302_CE = 1;
    
    for(i = 0; i < 8; i++){
        DS1302_IO = command & (0x01 << i);
        DS1302_SCLK = 1;
        DS1302_SCLK = 0;
    }
    
    for(i = 0; i < 8; i++){
        DS1302_IO = dat & (0x01 << i);
        DS1302_SCLK = 1;
        DS1302_SCLK = 0;
    }
    
    DS1302_CE = 0;
}

void DS1302_SetTime(){
	DS1302_writeByte(DS_WP, 0x00); //关闭写保护
	DS1302_writeByte(DS_YEAR, Dec_To_BCD(Time[0])); 
	DS1302_writeByte(DS_MONTH, Dec_To_BCD(Time[1])); 
	DS1302_writeByte(DS_DATE, Dec_To_BCD(Time[2])); 
	DS1302_writeByte(DS_HOUR, Dec_To_BCD(Time[3])); 
	DS1302_writeByte(DS_MINUTE, Dec_To_BCD(Time[4])); 
	DS1302_writeByte(DS_SECOND, Dec_To_BCD(Time[5])); 
	DS1302_writeByte(DS_DAY, Dec_To_BCD(Time[6])); 
	DS1302_writeByte(DS_WP, 0x80); //打开写保护
}

void DS1302_ReadTime(){
	Time[0] = BCD_To_Dec(DS1302_readByte(DS_YEAR));
	Time[1] = BCD_To_Dec(DS1302_readByte(DS_MONTH));
	Time[2] = BCD_To_Dec(DS1302_readByte(DS_DATE));
	Time[3] = BCD_To_Dec(DS1302_readByte(DS_HOUR));
	Time[4] = BCD_To_Dec(DS1302_readByte(DS_MINUTE));
	Time[5] = BCD_To_Dec(DS1302_readByte(DS_SECOND));
	Time[6] = BCD_To_Dec(DS1302_readByte(DS_DAY));
}