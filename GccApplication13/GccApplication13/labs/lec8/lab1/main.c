/*
 * GccApplication9.c
 *
 * Created: 9/2/2026 7:09:00 PM
 * Author : zenas
 */ 

#include <avr/io.h>
#include "Bit_Maths.h"

int main(void)
{
    /* Replace with your application code */
	DDRA = 0b00000010;
    while (1) 
    {
		if(GET_BIT(PINA,0)==0)
		{
			PORTA=0b00000011;
		}
		else
		{ PORTA=0b00000001;}
    }
}

