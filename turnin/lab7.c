/*	Author: jalam004
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab 5  Exercise 2
 *	Exercise Description: [optional - include for your own benefit]
 * Link: https://www.youtube.com/watch?v=Cbypw7ZwiZw
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#include "io.h"
#include "timer.h"
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum States{Start, init, inc, dec, wait, reset} state; 
unsigned char cnt1 = 0; 
unsigned char cnt2 = 0;   
unsigned char tmpB; 
void Tick(){    
    switch(state)
    {   
        case Start:
        state = init;
        break;

        case init:
            if((~PINA & 0x01) == 0x01)
            {   //cnt++;
                state = inc;
		//cnt = 0;
            }
            else if((~PINA & 0x02) == 0x02)
            {	//cnt++;
                state = dec;
		//cnt = 0;
            }
            
           else if((~PINA & 0x03) == 0x03)
            {	
                state = reset;
            }

           else {state = init;}
            break;

        case inc:
	//cnt++;
	{state = wait;}
            break;
            
        case dec:
          {state = wait;}
       		 break;
        
        case wait:
        
        if((~PINA & 0x03) == 0x03)
        { state = reset;}
        else if(( ~PINA & 0x03) == 0x00)
        { state = init;}

        
        if((~PINA & 0x01) == 0x01)
	{cnt1++;}
	if((~PINA & 0x02) == 0x02) 
	{cnt2++;}
        else{state = wait;}
         break;
        
        case reset:
        {state = init;}
         break;

        default:
         break;
    }
        
    switch(state)
    {
        case Start:
       // PORTB = 0x07;
        break;

        case init:
        tmpB = 0x00;
	break;

        case dec:
        if(tmpB <= 0x00){tmpB = 0x00;}
        else{tmpB = tmpB - 1;}
	
        break;
        case wait:
	if(cnt1 == 10 )
       	tmpB = tmpB + 1;
	if(cnt2 == 10)
	tmpB = tmpB - 1;
//	else{return 1;}
	break;

        case inc:
        if(PORTB >= 0x09){PORTB = 0x09;}
       //	else if((cnt % 10 == 0) && (PORTB < 0x09)){PORTB = PORTB + 1;}	
	 else{tmpB = tmpB + 1;}
        break;

        case reset:
        tmpB = 0x00;
        break;
        default: break;
//	PORTB = tmpB;
    }
//	PORTB = tmpB;

}


int main(void) {
DDRB = 0xFF; PORTB = 0x00;
DDRD = 0xFF; PORTD = 0x00;
// state = Start;
//const unsigned char * tmpA = "hello";
unsigned char s = 40;
//unsigned char c = 1; 
LCD_init();
//LCD_ClearScreen();
while(s)
{

LCD_DisplayString(s, "CS120B is Legend... wait for it DARY!");
s--;
delay_ms(500);
//LCD_init();
}

//TimerSet(100);
//TimerOn();
 //state = Start;
	while(1){
//	tmpB = PORTB;
	//LCD_ClearScreen();
//	Tick();
continue;	
//	while(!TimerFlag) {}
//	TimerFlag = 0;
	//tmpB = PORTB;
//	Tick();
//	LCD_Cursor(1);
//	LCD_WriteData(tmpB + '0');
	}
//return 1;
}	




