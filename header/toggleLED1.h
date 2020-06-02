enum toggleLED1_states { LED1_wait, blink};

int Toggle_LED1(int state) {
switch(state)
	{
    case LED1_wait:
	state = !pause ? blink: wait; break;
	case blink:
	state = pause ? LED1_wait: blink; break;

	default: state = LED1_wait; break;
	}
	
switch(state)
	{
	case LED1_wait: break;
	case blink:
led1_output = (led1_output == 0x00) ? 0x01 : 0x00;  
break;
	}
	return state;
}
