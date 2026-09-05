#include <avr/io.h>
#include <avr/delay.h>

int main(void)
{
	DDRC = 0b00001111;
	
	while(1)
	{
		PORTC=0b00000011;
		_delay_ms(5000);
		PORTC=0b00001100;
		_delay_ms(5000);
	}
	
}