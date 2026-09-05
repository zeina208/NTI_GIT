#include <avr/io.h>
#include <avr/delay.h>

int main(void)
{
	DDRC = 0b00000001;
	
	while(1)
	{
		PORTC=0b00000001;
		_delay_ms(5000);
		PORTC=0b00000000;
		_delay_ms(5000);
	}
	
}