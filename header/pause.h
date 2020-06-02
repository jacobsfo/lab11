enum pausebutton { wait, pause_press, release };

int Pause(int state) {

unsigned char press = ~PINA & 0x01;

switch(state)
	{
    case wait:
	state = press = 0x01? pause_press: wait; break;
	case pause_press:
	state = release; break;
	case release:
	state = press = 0x00? wait: pause_press; break;
	default: state = wait; break;
	}
	
switch(state)
	{
	case wait: break;
	case pause_press:
if(pause == 0)
 pause = 1;
else{pause = 0;}
break;
 	case release: break;
	}
	return state;
}
