#include "../Headers/calc.h"
#include "../Headers/DIO.h"
#include "../Headers/Keypad.h"
#include <avr/delay.h>
int main(void)
{
	Calc_init();
	while(1)
	{
		Calc_LCD();
	
	}
}