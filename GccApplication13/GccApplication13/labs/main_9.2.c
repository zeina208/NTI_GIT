# include "../Headers/Keypad.h"
#include "../Headers/DIO.h"
#include "../Headers/7-seg.h"
#include "avr/delay.h"

int main(void)
{
	Keypad_init();
	seg_init();
	
	while(1)
	{
		s8 x = Keypad_press();
		if(x != -1)
		{seg_setvalue(PORTD,x);}
		
	}
}