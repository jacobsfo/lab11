enum pausebutton { p_wait, pause_press, release };

int Pause(int state) {

unsigned char press = ~PINA & 0x01;

switch(state)
	{
    case p_wait:
	state = press = 0x01? pause_press: p_wait; break;
	case pause_press:
	state = release; break;
	case release:
	state = press = 0x00? p_wait: pause_press; break;
	default: state = p_wait; break;
	}
	
switch(state)
	{
	case p_wait: break;
	case pause_press:
if(pause == 0)
 pause = 1;
else{pause = 0;}
break;
 	case release: break;
	}
	return state;
}
