#include <at89c5131.h>
#include "lcd.h"

code unsigned char display_msg1[]="      Pt-51      ";						//Display msg on 1st line of lcd
code unsigned char display_msg2[]="   IIT Bombay    ";						//Display msg on 1st line of lcd

void main()
{
	lcd_init();
	lcd_cmd(0x80);													//Move cursor to first line
	lcd_cmd(0x05);
	lcd_cmd(0x05);
	lcd_cmd(0x05);
	lcd_cmd(0x06);
	lcd_cmd(0x06);
	lcd_cmd(0x06);
	msdelay(500);
	lcd_write_string(display_msg1);
	lcd_cmd(0xc0);													//Move cursor to 2nd line of LCD
	lcd_cmd(0x06);
	lcd_cmd(0x06);
	lcd_cmd(0x06);
	//lcd_cmd(0x12);
	msdelay(500);
	lcd_write_string(display_msg2);
	while(1);
}