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
//#include "simAVRHeader.h"
#endif
#include "keypad.h"
  /*x = GetKeypadKey();
	switch(x)
	{
	case '\0' : PORTB = 0x1F;break;
	case '1' : PORTB = 0x01;break;
	case '2' : PORTB = 0x02;break;
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
case '0' : PORTB = 0x00; break;
case '#' : PORTB = 0x0F;break;
default: PORTB = 0x1B;break;
    }*/
//unsigned char s = GetKeypadKey();
enum States { Start, Press} ;
int Keypad(int state)
{
//PORTB = 0x03
//unsigned char in =  ~PINC & 0xF0;
unsigned char s = GetKeypadKey();
	switch(state)
	{case Start:
	state = Press;
	break;
	case Press:
	break;
	default:PORTB = 0x1F; break;
	}
	switch(state)
	{
 	case Start:
	break;
	case Press:
//unsigned char x = GetKeyPadKey();
	//PORTB = values[s];
	switch(s)
	{
	case '\0' : PORTB = 0x1F;break;
	case '1' : PORTB = 0x01;break;
	case '2' : PORTB = 0x02;break;
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
	case '0' : PORTB = 0x00; break;
	case '#' : PORTB = 0x0F;break;
	default: PORTB = 0x1B;break;
	}
	break;
	}
}
