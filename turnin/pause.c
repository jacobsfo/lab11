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
#include "keypad.h"
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
//static _task task1, task2, task3, task4;
//_task *tasks[] = { &task1, &task2, &task3, &task4}; 
//const unsigned short numTasks = sizeof(tasks/sizeof(task*);
const char SMStart = -1;

unsigned char i=0;
  tasks[i].state = SMStart;
  tasks[i].period = 50;
  tasks[i].elapsedTime = tasks[i].period;
  tasks[i].TickFct = &Pause;
  ++i;
  tasks[i].state = SMStart;
  tasks[i].period = 500;
  tasks[i].elapsedTime = tasks[i].period;
  tasks[i].TickFct = &Toggle_LED0;
  ++i;
  tasks[i].state = SMStart;
  tasks[i].period = 1000;
  tasks[i].elapsedTime = tasks[i].period;
  tasks[i].TickFct = &Toggle_LED1;
  ++i;
  tasks[i].state = SMStart;
  tasks[i].period = 10;
  tasks[i].elapsedTime = tasks[i].period;
  tasks[i].TickFct = &display;
  TimerSet(10);
  TimerOn(); 

 while (1) {
for (i = 0; i < tasksNum; ++i) { // Heart of the scheduler code
     if ( tasks[i].elapsedTime >= tasks[i].period ) { // Ready
        tasks[i].state = tasks[i].TickFct(tasks[i].state);
        tasks[i].elapsedTime = 0;
     }
     tasks[i].elapsedTime += 10;
  }
while(!TimerFlag)
{TimerFlag = 0;
}
}
return 0;
}
