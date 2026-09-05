#include "../Headers/StepperMotor.h"
#include "../Headers/DIO.h"
#include <avr/delay.h>


u8 arr[8] = {0b00001001, 0b00000001, 0b00000011, 0b00000010, 0b00000110, 0b00000100, 0b00001100, 0b00001000};
u8 half[4] = {0b00000011,0b00000001,0b00000011,0b00000010};
void motor_init()
{
	DIO_voidSetPortDirection(PORTC,OUTPUT);
}

void motor_fullstep(u8 direction)
{
	if(direction==clockwise)
	{
		for(int i =0;i<8;i++)
	{
		DIO_voidSetPinValue(PORTC,PIN3,GET_BIT(arr[i],0));
		DIO_voidSetPinValue(PORTC,PIN2,GET_BIT(arr[i],1));
		DIO_voidSetPinValue(PORTC,PIN1,GET_BIT(arr[i],2));
		DIO_voidSetPinValue(PORTC,PIN0,GET_BIT(arr[i],3));
		_delay_ms(100);
	}
	}
	else
	{
		for(int i =7;i>=0;i--)
		{
			DIO_voidSetPinValue(PORTC,PIN3,GET_BIT(arr[i],0));
			DIO_voidSetPinValue(PORTC,PIN2,GET_BIT(arr[i],1));
			DIO_voidSetPinValue(PORTC,PIN1,GET_BIT(arr[i],2));
			DIO_voidSetPinValue(PORTC,PIN0,GET_BIT(arr[i],3));
			_delay_ms(100);
		}
	}
}

void motor_halfstep(u8 direction)
{
	if(direction==clockwise)
	{
		for(int i =0;i<4;i++)
		{
			DIO_voidSetPinValue(PORTC,PIN3,GET_BIT(half[i],0));
			DIO_voidSetPinValue(PORTC,PIN2,GET_BIT(half[i],1));
			DIO_voidSetPinValue(PORTC,PIN1,GET_BIT(half[i],2));
			DIO_voidSetPinValue(PORTC,PIN0,GET_BIT(half[i],3));
			_delay_ms(100);
		}
	}
	else
	{
		for(int i =3;i>=0;i--)
		{
			DIO_voidSetPinValue(PORTC,PIN3,GET_BIT(half[i],0));
			DIO_voidSetPinValue(PORTC,PIN2,GET_BIT(half[i],1));
			DIO_voidSetPinValue(PORTC,PIN1,GET_BIT(half[i],2));
			DIO_voidSetPinValue(PORTC,PIN0,GET_BIT(half[i],3));
			_delay_ms(100);
		}
	}

}