// Author: Premchand


#include <at89c5131.h>
#include "lcd.h"

sbit switchI = P1^0;

int isOn = 0;

int count = 0;
int seconds = 0;
int minutes = 0;

int prevState = 0;

char timer[] = {'T' , 'I', 'M', 'E' , ':' , '0','0', ':', '0', '0' , '\0'};

char getChar(int number){
	
	if(number == 0){
	return '0';
	}
	
	if(number == 1){
	return '1';
	}
	
	if(number == 2){
	return '2';
	}
	
	if(number == 3){
	return '3';
	}
	
	if(number == 4){
	return '4';
	}
	
	if(number == 5){
	return '5';
	}
	if(number == 6){
	return '6';
	}
	
	if(number == 7){
	return '7';
	}
	
	if(number == 8){
	return '8';
	}
	return '9';
	
}


void updateLCD(){
	lcd_cmd(0x80);
	if(seconds > 59){
		minutes++;
		seconds = 0;
	}
  timer[8] = getChar(seconds/10);
	timer[9] = getChar(seconds%10);
	
	timer[5] = getChar(minutes/10);
	timer[6] = getChar(minutes%10);
	lcd_write_string(timer);
}

void timer0I() interrupt 1	
{
	if(count < 30 && isOn == 1){
		count++;
		return;
	}
	if(count == 30 && isOn == 1 ){
	TH0 = 0x6B;
	TL0 = 0x90;
	count++;
	return;
	}
	if(count == 31 && isOn == 1){
		seconds++;
		count = 0;
		updateLCD();
		return ;
	}
	if(count > 31){
	count = 0 ;
	}
}


void main(){
	lcd_init();
	updateLCD();
	// Enable Interupts
	EA  = 1;
	
	// Enable Interupts for Timer
	ET0 = 1;
	
	// Timer Mode
	TMOD = 0x01;
	
	TH0 = 0;		
	TL0 = 0;  

	// Start timer 0
	TR0 = 1;
	
	
	while(1){
	switchI = 1;
	if(switchI == 1 ){
	isOn = 1;
	}else{
	isOn = 0;
	}	
}
}