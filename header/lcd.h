#include "io.h"
unsigned char s = 32;
//const unsigned char * string = "CS120B is legendary";
enum {start,sub,adj,pred};
int LCD(int state)
{ LCD_init();
//PORTB =0x00;
//LCD_ClearScreen();
//LCD_DisplayString(s, "ddfdsfsdf");

	switch(state)
	{case start:
	state = sub;
	break;
	case sub:
	state = adj;
	break;
	case adj:
	state = pred;
	break;
	case pred:
	break;
	default: state = start; break;
	}

	switch(state)
	{case start:
	 break;
	case sub:
LCD_DisplayString(s,"Legend ...wait it for DARY!");
s--; 

 	break;
	case adj:
        break;
	case pred:
	break;
	}

}


}








  


