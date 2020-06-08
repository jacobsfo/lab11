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
:
unsigned char values[]={ 0x0F,0x0F, 0x0F,0x0F,0x0F,0x0F,0x0F,0x0E};
enum States { Start, Press} ;
int Keypad(int state)
{
//PORTD = 0xFF;
//return;
//unsigned char in =  ~PINC & 0xF0;
unsigned char s = GetKeypadKey();
//s = 0xc;
	switch(state)
	{case Start:
//	PORTB = 0x03;
//return;
if( ~PINC & 0x01)
{//PORTB = 0x01;
//return;
s = 0x01;
state = Start;}
else if( ~PINC & 0x02)
{
s = 0x03;
state = Start;}
else{// PORTB = 0x03;
 state = Press;}
	break;
	case Press:
	if( s == '\0')
	state = Start;
	else{state = Press;}
	
	break;
	default: state = Start;
break;	}

	switch(state)
	{
	case Start:
	//PORTB = 0x1F;
	break;
	case Press:
//unsigned char x = GetKeyPadKey();
	//PORTB = values[s-35];
PORTB = s ? s : 0x1F ;
	break;
	}
}

