#include "io.h"
unsigned char s = 32;
//const unsigned char * string = "CS120B is legendary";
enum {start};
int LCD(int state)
{ // LCD_init();
//PORTB =0x00;
//LCD_ClearScreen();
//LCD_DisplayString(s, "ddfdsfsdf");

	switch(state)
	{case start:
	state = start;
	break;
	default: state = start; break;
	}

	switch(state)
	{case start:
 LCD_WriteCommand(0x38);
 LCD_WriteCommand(0x06);
LCD_WriteCommand(0x0f);
LCD_WriteCommand(0x01);

if(s>1)
{
LCD_DisplayString(s, "Legend... wait for it DARY!");
s--;
}
else{
LCD_ClearScreen();
s = 32;	
}



	break;
	default: break;
	}
return state;

}










  


