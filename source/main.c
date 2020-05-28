/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
//#include "keypad.h"
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
#include "keypad.h"
int main(void) {
    /* Insert DDR and PORT initializations */
unsigned char x;
DDRB = 0xFF; PORTB = 0x00;
DDRC = 0xF0; PORTC = 0x0F;
    /* Insert your solution below */
    while (1) {
     x = GetKeypadKey();
	switch(x)
	{
	case '\0' : PORTB = 0x1F;break;
	case '1' : PORTB = 0x1F;break;
	case '2' : PORTB = 0x1F;break;
	case 'D' : PORTB = 0x1F;break;
	case '*' : PORTB = 0x1F;break;
case '0' : PORTB = 0x1F;break;
case '#' : PORTB = 0x1F;break;
default: PORTB = 0x1B;break;
    }
    return 1;
}
}
