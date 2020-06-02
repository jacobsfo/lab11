enum toggleLED0_states { LED0_wait, Blink};

int Toggle_LED0(int state) {
switch(state)
	{
    case LED0_wait:
	state = !pause ? Blink: wait; break;
	case Blink:
	state = pause ? LED0_wait: Blink; break;

	default: state = LED0_wait; break;
	}
	
switch(state)
	{
	case LED0_wait: break;
	case Blink:
led0_output = (led0_output == 0x00) ? 0x01 : 0x00;  
break;
	}
	return state;
}
