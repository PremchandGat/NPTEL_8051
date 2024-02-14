#include <at89c5131.h>
#include "lcd.h"


sbit r0 = P3^4;
sbit r1 = P3^5;
sbit r2 = P3^6;
sbit r3 = P3^7;

sbit c0 = P3^3;
sbit c1 = P3^2;
sbit c2 = P3^1;
sbit c3 = P3^0;

int inx = 0;
int j=0;
int c = 0;
unsigned char ask[]   =   "ENTER PASSWORD";
unsigned char pass[]  =  "XXXXXXXX";
unsigned char cPass[] = "15A8*D6#";

int canIRead(){
	r0 = r1 = r2 = r3 = 1;
	c0 = c1 = c2 = c3 = 0;
 	if(r0 == 1 && r1 == 1 && r2 == 1 && r3 == 1) {
		return 0;
 	}
	return 1;
}


int readRowNumber(){
r0 = r1 = r2 = r3 = 1;
c0 = c1 = c2 = c3 = 0;
	
	if(r0 == 0) {
	return 0;
	}
	
	if(r1 == 0) {
	return 1;
	}
	
	if(r2 == 0) {
	return 2;
	}
	
	if(r3 == 0) {
	return 3;
	}
}


int readColumnNumber(){
    c0 = c1 = c2 = c3 = 1;
	r0 = r1 = r2 = r3 = 0;
	
	if(c0 == 0) {
	return 0;
	}
	
	if(c1 == 0) {
	return 1;
	}
	
	if(c2 == 0) {
	return 2;
	}
	
	if(c3 == 0) {
	return 3;
	}
	
}


unsigned char readInput() {

	int rr = readRowNumber();
	int rc = readColumnNumber();
	
	if(rr == 0 ){
		if(rc == 0){
			return '1';
		}
		if(rc == 1){
			return '2';
		}
		if(rc == 2){
			return '3';
		}
		if(rc == 3){
			return 'A';
		}
	}
	
	if(rr == 1 ){
		if(rc == 0){
			return '4';
		}
		if(rc == 1){
			return '5';
		}
		if(rc == 2){
			return '6';
		}
		if(rc == 3){
			return 'B';
		}
	}
	
	if(rr == 2 ){
		if(rc == 0){
			return '7';
		}
		if(rc == 1){
			return '8';
		}
		if(rc == 2){
			return '9';
		}
		if(rc == 3){
			return 'C';
		}
	}
		
	if(rr == 3 ){
		if(rc == 0){
			return '*';
		}
		if(rc == 1){
			return '0';
		}
		if(rc == 2){
			return '#';
		}
		if(rc == 3){
			return 'D';
		}
	}
}


void main()
{
	lcd_init();
	lcd_cmd(0x80);													//Move cursor to first line
	lcd_write_string("   Welcome   ");
	//lcd_cmd(0xc0);													//Move cursor to 2nd line of LCD
	//lcd_write_string("Hello, Premchand");
	msdelay(5000);
	while(1){
	lcd_cmd(0x80);													//Move cursor to first line
	lcd_write_string(ask);
	lcd_cmd(0xc0);													//Move cursor to 2nd line of LCD
	lcd_write_string(pass);
	if( canIRead() == 1 && inx <= 7){
		pass[inx] =  readInput();
		inx++;
		msdelay(200);
		}
	lcd_cmd(0xc0);													//Move cursor to 2nd line of LCD
	lcd_write_string(pass);
	if(inx > 7){
		lcd_cmd(0x80);													//Move cursor to first line
		lcd_write_string("AUTHENTICATING..");
		lcd_cmd(0xc0);													//Move cursor to 2nd line of LCD
		lcd_write_string(pass);

		if(pass[0] == cPass[0] && pass[1] == cPass[1] && pass[2] == cPass[2] && pass[3] == cPass[3] && pass[4] == cPass[4] && pass[5] == cPass[5] && pass[6] == cPass[6] && pass[7] == cPass[7] ) {
			lcd_cmd(0x80);													//Move cursor to first line
			lcd_write_string("CORRECT PASSWORD");
			lcd_cmd(0xc0);													//Move cursor to 2nd line of LCD
			lcd_write_string("    UNLOCKED    ");
			while(1);
		}else{
			j = 0;
			lcd_cmd(0x80);													//Move cursor to first line
			lcd_write_string("INCORRECT PASS..");
			lcd_cmd(0xc0);													//Move cursor to 2nd line of LCD
			lcd_write_string("  TRY IN 5 SEC  ");
			msdelay(5000);
			lcd_cmd(0xc0);
			lcd_write_string("                ");
			inx = 0;
			j = 0;
			while(j <= 7 ){
				pass[j] = 'X';
				j++;
			}
		}
	}
}
}