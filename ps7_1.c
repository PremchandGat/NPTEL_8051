#include <at89c5131.h>

sbit l = P1^6;

void setMode(){
	TMOD = 1; 		// 16 Bit timer0 mode
}

void startOnTimer(){
	TH0 = 0xE0;
	TL0 = 0xBF;
	TR0 = 1;
	while(TF0 == 0);
	TR0 = 0;
	TF0 = 0;
}

void startOffTimer(){
	TH0 = 0xA2;
	TL0 = 0x3F;
	TR0 = 1; 			// Start Timer
	while(TF0 == 0);
	TR0 = 0;
	TF0 = 0;
}

void tooglePin(){
	l = ~l;
}

void main(){
	setMode();
	while(1){
	startOnTimer();
	tooglePin();
	startOffTimer();
	tooglePin();
	}
}