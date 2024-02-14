#include <at89c5131.h>

sbit pin1 = P1^6;

int freq  = 0;
int loop  = 0;

int freqTimerH[] = {0xEF, 0xF1, 0xF2, 0xF3, 0xF5, 0xF6, 0xF7, 0xF7};
int freqTimerL[] = {0xBA, 0x89, 0xFB, 0xCB, 0x27, 0x3C, 0x52, 0xDD};

int onTimer[]    =  {15, 15, 15, 22, 22, 30, 30, 30};
int onTimerH[]   = 	{0xBD, 0xBD, 0xBD, 0x1C, 0x1C, 0x7B, 0x7B, 0x7B};
int onTimerL[]   = 	{0xC0, 0xC0, 0xC0, 0xA0, 0xA0, 0x80, 0x80, 0x80};

void timer0I() interrupt 1	
{
	pin1 = ~pin1; 
	TH0 = freqTimerH[freq];		
	TL0 = freqTimerL[freq];  
}

void timer1I() interrupt 3
{
	
	if(loop < onTimer[freq] && freq  <= 7){
		loop++;
		return;
	}
	
	if(loop == onTimer[freq] && freq  <= 7){
	  TH1 = onTimerH[freq];
		TL1 = onTimerL[freq];
		loop++;
		return;
	}
	
		if(freq > 7) {
		freq = 0;
		} else {
			freq++;
		}
		loop = 0;
}


void main(){
	
	// Enable Interupts
	EA  = 1;
	
	// Enable Interupts for Timer
	ET0 = 1;
	ET1 = 1;
	
	// Timer Mode
	TMOD = 0x11;
	
	TH0 = freqTimerH[freq];		
	TL0 = freqTimerL[freq];  
	
	// Timer 1 Timer
	TH1 = 0x00;		
	TL1 = 0x00;	
	
	// Start timer 0
	TR0 = 1;
	
	// Start timer 1
	TR1 = 1;
	
	while(1);
	
}