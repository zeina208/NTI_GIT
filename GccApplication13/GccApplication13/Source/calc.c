#include "../Headers/calc.h"
#include "../Headers/DIO.h"
#include "../Headers/Keypad.h"
#include <avr/delay.h>
#include <stdlib.h>

		
void Calc_init()
{
	//keypad init
	Keypad_init();
	
	//LCD init
	_delay_ms(30);
	DIO_voidSetPinDirection(PORTB,PIN0,OUTPUT);
	DIO_voidSetPinDirection(PORTB,PIN1,OUTPUT);
	DIO_voidSetPinDirection(PORTB,PIN2,OUTPUT);
	DIO_voidSetPortDirection(PORTA,OUTPUT);
	DIO_voidSetPinValue(PORTB,	PIN0,High);
	DIO_voidSetPinValue(PORTB,PIN1,Low);
	DIO_voidSetPinValue(PORTB,PIN2,Low);
	DIO_voidSetPortValue(PORTA,Low);
	DIO_voidSetPinValue(PORTA,PIN4,High);
	DIO_voidSetPinValue(PORTA,PIN5,High);
	
	_delay_ms(1);
	DIO_voidSetPinValue(PORTB,	PIN0,Low);
	_delay_us(40);
	
	
	
	DIO_voidSetPinValue(PORTB,	PIN0,High);
	DIO_voidSetPinValue(PORTA,	PIN4,Low);
	DIO_voidSetPinValue(PORTA,	PIN5,Low);
	DIO_voidSetPinValue(PORTA,	PIN3,High);
	DIO_voidSetPinValue(PORTA,	PIN2,High);
	DIO_voidSetPinValue(PORTA,	PIN1,High);
	DIO_voidSetPinValue(PORTA,	PIN0,High);
	
	_delay_ms(1);
	DIO_voidSetPinValue(PORTB,	PIN0,Low);
	_delay_us(40);
	
	
	DIO_voidSetPinValue(PORTB,	PIN0,High);
	DIO_voidSetPortValue(PORTA,Low);
	DIO_voidSetPinValue(PORTA,	PIN0,High);
	DIO_voidSetPinValue(PORTB,	PIN0,High);
	_delay_ms(1);
	DIO_voidSetPinValue(PORTB,	PIN0,Low);
	_delay_ms(2);
}


void LCD_sendChar(char Data)
{
	
	DPORTA = Data;
	DIO_voidSetPinValue(PORTB,	PIN2,High);
	DIO_voidSetPinValue(PORTB,	PIN1,Low);
	
	DIO_voidSetPinValue(PORTB,	PIN0,High);
	_delay_ms(1);
	DIO_voidSetPinValue(PORTB,	PIN0,Low);
	_delay_us(40);
}
void LCD_SendString (char *str)
{
	while(*str != '\0')
	{
		LCD_sendChar(*str);
		str ++;
	}
}


void LCD_WriteNumber(s32 num)
{
	char str[12];

	itoa(num, str, 10);

	LCD_SendString(str);
}


void Calc_LCD()
{
	static s32 result = 0;
	static u8 firstno = 1;
	static u8 operator = 0;
	static u8 current = 0;
	u8 x = Keypad_press();

	if(x == -1)
	return;

	switch(x)
	{
		case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:
		LCD_sendChar(x + '0');
		current = current * 10 + x; 
		break;

		case 'A':
		if(firstno)
		{
			result = current;
			firstno = 0;
		}
		else
		{
			if(operator == 'D')
			result = result + current;

			else if(operator == 'A')
			result = result - current;

			else if(operator == 'B')
			result = result * current;

			else if(operator == 'C')
			{
				if(current != 0)
				result = result / current;
			}
		}
		LCD_sendChar('-');
		operator = 'A';
		current=0;
		break;
		case 'B':
		if(firstno)
		{
			result = current;
			firstno = 0;
		}
		else
		{
			if(operator == 'D')
			result = result + current;

			else if(operator == 'A')
			result = result - current;

			else if(operator == 'B')
			result = result * current;

			else if(operator == 'C')
			{
				if(current != 0)
				result = result / current;
			}
		}
		LCD_sendChar('x');
		operator = 'B';
		current=0;
		break;
		case 'C':
		if(firstno)
		{
			result = current;
			firstno = 0;
		}
		else
		{
			if(operator == 'D')
			result = result + current;

			else if(operator == 'A')
			result = result - current;

			else if(operator == 'B')
			result = result * current;

			else if(operator == 'C')
			{
				if(current != 0)
				result = result / current;
			}
		}
		LCD_sendChar('/');
		operator = 'C';
		current=0;
		break;
		case 'D':
		if(firstno)
		{
			result = current;
			firstno = 0;
		}
		else
		{
			if(operator == 'D')
			result = result + current;

			else if(operator == 'A')
			result = result - current;

			else if(operator == 'B')
			result = result * current;

			else if(operator == 'C')
			{
				if(current != 0)
				result = result / current;
			}
		}
		LCD_sendChar('+');
		operator = 'D';
		current=0;
		break;
		case '#':
		LCD_sendChar('=');
		if(operator == 'D')
		result = result + current;

		else if(operator == 'A')
		result = result - current;

		else if(operator == 'B')
		result = result * current;

		else if(operator == 'C')
		{
			if(current != 0)
			result = result / current;
		}
		if(result < 0)
		{
			LCD_sendChar('-');
			result = -result;
		}
		LCD_WriteNumber(result);
		current=0;
		break;
		case '*':
		Calc_init();
		result = 0;
		firstno = 1;
		operator = 0;
		break;
	}
}
	
