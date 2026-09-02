#include "../Headers/DIO.h"


int main(void)
{
	DIO_voidSetPortDirection(PORTA,INPUT);
	DIO_voidSetPinDirection(PORTC,PIN0,OUTPUT);
	DIO_voidSetPinDirection(PORTC,PIN1,OUTPUT);
	DIO_voidSetPinDirection(PORTC,PIN2,OUTPUT);
	DIO_voidSetPinValue(PORTA,PIN0,High);
	DIO_voidSetPinValue(PORTA,PIN1,High);
	DIO_voidSetPinValue(PORTA,PIN2,High);
	DIO_voidSetPinValue(PORTA,PIN7,High);
	while(1)
	{
		if(DIO_u8GetPinValue(PORTA,PIN0)==0)
		{
			DIO_voidSetPinValue(PORTC,PIN0,High);
		}
		else if(DIO_u8GetPinValue(PORTA,PIN7)==0)
		{
			DIO_voidSetPinValue(PORTC,PIN0,High);
		}
		else
		{
			DIO_voidSetPinValue(PORTC,PIN0,Low);
		}
		if(DIO_u8GetPinValue(PORTA,PIN1)==0)
		{
			DIO_voidSetPinValue(PORTC,PIN1,High);
		}
		else if(DIO_u8GetPinValue(PORTA,PIN7)==0)
		{
			DIO_voidSetPinValue(PORTC,PIN1,High);
		}
		else
		{
			DIO_voidSetPinValue(PORTC,PIN1,Low);
		}
		
		if(DIO_u8GetPinValue(PORTA,PIN2)==0)
		{
			DIO_voidSetPinValue(PORTC,PIN2,High);
		}
		else if(DIO_u8GetPinValue(PORTA,PIN7)==0)
		{
			DIO_voidSetPinValue(PORTC,PIN2,High);
		}
		else
		{
			DIO_voidSetPinValue(PORTC,PIN2,Low);
		}

	}
}

