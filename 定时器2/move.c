#include <REGX52.H>

static unsigned char count = 0;
unsigned char dir = 0;
void dir_trigger (unsigned char a) {
    
    if(a == 1) dir = 1;    
    if(a == 2) dir = 2;
}
void move() {
	if(dir == 0) return;
	if(dir==1){
			if(count>=7)count = 0;
			else count++;
			P2 = ~(1<<count);
	}
	if(dir==2){
			if(count==0)count = 7;
			else count--;
			P2 =~(1<<count);
		}
	}
