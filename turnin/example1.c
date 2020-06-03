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

#include <bit.h>

// Keypad Setup Values
#define KEYPADPORT PORTA
#define KEYPADPIN  PINA
#define ROW1 0
#define ROW2 1
#define ROW3 2
#define ROW4 3
#define COL1 4
#define COL2 5
#define COL3 6
#define COL4 7


#endif

#include "unistd.h"
int main(void) {
    /* Insert DDR and PORT initializations */
unsigned char x = 1;
DDRB = 0xFF; PORTB = 0x00;
DDRA = 0xF0; PORTA = 0x0F;
DDRD = 0xFF; PORTD = 0x00;
    /* Insert your solution below */
    while (1) {
//	PORTD = 0x80;

	PORTB = 0x02;
//break;
//     x = GetKeypadKey();
// Permission to copy is granted provided that this header remains intact. 
// This software is provided with no warranties.

////////////////////////////////////////////////////////////////////////////////

// Returns '\0' if no key pressed, else returns char '1', '2', ... '9', 'A', ...
// If multiple keys pressed, returns leftmost-topmost one
// Keypad must be connected to port C
// Keypad arrangement
//        Px4 Px5 Px6 Px7
//	  col 1   2   3   4
//  row  ______________
//Px0 1	| 1 | 2 | 3 | A
//Px1 2	| 4 | 5 | 6 | B
//Px2 3	| 7 | 8 | 9 | C
//Px3 4	| * | 0 | # | D

//Functionality - Gets input from a keypad via time-multiplexing
//Parameter: None
//Returns: A keypad button press else '\0'
while(1){
	// Check keys in col 1
	KEYPADPORT = SetBit(0xFF,COL1,0); // Set Px4 to 0; others 1
	asm("nop"); // add a delay to allow PORTx to stabilize before checking
	PORTB = 0x01;
	if ( ~PINA & 0x02  ) { PORTD = 0x80;break; } 
	if ( GetBit(~KEYPADPIN,ROW3) ) { PORTD = 0x00; }
	if ( GetBit(~KEYPADPIN,ROW4) ) { PORTD = 0x00; }
//break;


}
break;
	switch(x)
	{
	case '\0' : PORTB = 0x1F;break;
	case '1' : PORTB = 0x01;break;
/*	case '2' : PORTB = 0x02;break;
	case '3' : PORTB = 0x03;break;
	case '4' : PORTB = 0x04;break;
	case '5' : PORTB = 0x05;break;
	case '6' : PORTB = 0x06;break;
case '7' : PORTB = 0x07;break;
case '8' : PORTB = 0x08;break;
case '9' : PORTB = 0x09;break;
case 'A' : PORTB = 0x0A;break;

case 'B' : PORTB = 0x0B;break;
case 'C' : PORTB = 0x0C;break;


	case 'D' : PORTB = 0x0D;break;
case '*' : PORTB = 0x0E;break;
case '#' : PORTB = 0x0F;break;
*/
default: PORTB = 0x1B;break;
    }
    return 1;
}
}
