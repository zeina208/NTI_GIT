#include "../Headers/DIO.h"
#include "../Headers/Keypad.h"


u8 arr[4][4] = {
{7,8,9,'C'},
{4,5,6,'B'},
{1,2,3,'A'},
{'*',0,'#','D'}};


void Keypad_init()
{
	DIO_voidSetPinDirection(PORTC,PIN0,INPUT);
	DIO_voidSetPinDirection(PORTC,PIN1,INPUT);
	DIO_voidSetPinDirection(PORTC,PIN2,INPUT);
	DIO_voidSetPinDirection(PORTC,PIN3,INPUT);
	DIO_voidSetPinDirection(PORTC,PIN4,OUTPUT);
	DIO_voidSetPinDirection(PORTC,PIN5,OUTPUT);
	DIO_voidSetPinDirection(PORTC,PIN6,OUTPUT);
	DIO_voidSetPinDirection(PORTC,PIN7,OUTPUT);
	
	DIO_voidSetPinValue(PORTC,PIN0,High);
	DIO_voidSetPinValue(PORTC,PIN1,High);
	DIO_voidSetPinValue(PORTC,PIN2,High);
	DIO_voidSetPinValue(PORTC,PIN3,High);
}


u8 Keypad_press()
{
	
	u8 i=0;
	u8 j=4;
	u8 x;
	for(j;j<8;j++)
	{
		
		DIO_voidSetPortValue(PORTC,High);
		DIO_voidSetPinValue(PORTC,j,Low);
		i =0;
		for(i;i<4;i++)
		{
			if(DIO_u8GetPinValue(PORTC,i)==0)
			{
				return arr[i][(j-4)];
				i =0;
				j=4;
				
			}
			else{}
		}
		
	}
	return -1;
}
