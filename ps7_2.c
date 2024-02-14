#include <at89c5131.h>

sbit pin1= P1^6;
sbit pin2 = P2^7;

void timer0I() interrupt 1	
{
	pin1 = ~pin1; 
	TH0 = 0xF8;		
	TL0 = 0x30;  
} 


void timer1I() interrupt 3
{
	pin2 = ~pin2;  		
	TH1 = 0xF4;		
	TL1 = 0x48;	  
}


int main(void)
{

	// Enable Interupts
	EA  = 1;
	
	// Enable Interupts for Timer
	ET0 = 1;
	ET1 = 1;
	
	// Timer Mode
	TMOD = 0x11;
	
	// Timer 0 time
	TH0 = 0xF8;		
	TL0 = 0x30;
	
	// Timer 1 Timer
	TH1 = 0xF4;		
	TL1 = 0x48;	
	
	// Start timer 0
	TR0 = 1;
	
	// Start timer 1
	TR1 = 1;
	
	while(1);
	
}