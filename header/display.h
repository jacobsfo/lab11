enum display_states { Display};

int display(int state) {
unsigned char out = 0;
switch(state)
	{
   case Display:
	state = Display; break;

	default: state = Display; break;
	}
	
switch(state)
	{
	case Display : break;

out = led0_output | led1_output << 1 ;  
break;
	}
	//return state;
PORTB = out;
return state;
}
