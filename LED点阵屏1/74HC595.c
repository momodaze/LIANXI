#include <REGX52.H>

sbit RCK = P3^5;
sbit SER = P3^4;
sbit SCK = P3^6;
/**
  *@brief 给74HC595输入数据选位单个字节并整体输出给寄存器
  *@param Byte：对应的数据
  *@retravl 无
*/
void _74HC595_writeByte(unsigned char Byte){
	unsigned char i = 0;
	for(i = 0;i<8;i++){
		SER = Byte&(0x80>>i);
		SCK = 1;
		SCK = 0;
	}
	RCK = 1;
	RCK = 0;
}