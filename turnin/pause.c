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

unsigned char pause = 0;
unsigned char led0_output = 0x00;
unsigned char led1_output = 0x00;
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
#include "scheduler.h"
//#include "keypad.h"
#include "pause.h"
#include "toggleLED0.h"
#include "toggleLED1.h"
#include "display.h"
#include "timer.h"
//const char SMStart = -1;
int main(void) {
    /* Insert DDR and PORT initializations */
DDRA = 0x00; PORTA = 0xFF;
DDRB = 0xFF; PORTB = 0x00;
    /* Insert your solution below */
static task tasks1, tasks2, tasks3, tasks4;
task *tasks[] = { &tasks1, &tasks2, &tasks3, &tasks4}; 
const unsigned short numTasks = sizeof(tasks)/sizeof(task*);
const char SMStart = -1;
//PORTB = 0x01;
//unsigned char i=0;
  tasks1.state = SMStart;
  tasks1.period = 50;
  tasks1.elapsedTime = tasks1.period;
  tasks1.TickFct = &Pause;
  
  tasks2.state = SMStart;
  tasks2.period = 500;
  tasks2.elapsedTime = tasks2.period;
  tasks2.TickFct = &Toggle_LED0;
  
  tasks3.state = SMStart;
  tasks3.period = 1000;
  tasks3.elapsedTime = tasks3.period;
  tasks3.TickFct = &Toggle_LED1;
  
  tasks4.state = SMStart;
  tasks4.period = 10;
  tasks4.elapsedTime = tasks4.period;
  tasks4.TickFct = &display;
  TimerSet(10);
  TimerOn(); 
unsigned short i;

 while (1) {
for (i = 0; i < numTasks; i++) { // Heart of the scheduler code
     if ( tasks[i]->elapsedTime == tasks[i]->period ) { // Ready
        tasks[i]->state = tasks[i]->TickFct(tasks[i]->state);
        tasks[i]->elapsedTime = 0;
     }
     tasks[i]->elapsedTime += 10;
  }

while(!TimerFlag);
TimerFlag = 0;



}
return 0;
}
