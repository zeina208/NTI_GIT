#include "../Headers/DIO.h"
#include "../Headers/LCD.h"
#include "Std_Types.h"
#include "avr/delay.h"
#include <stdlib.h>

void LCD_ClearDisplay()
{
	DIO_voidSetPinValue(PORTC,	PIN0,Low);
	DIO_voidSetPinValue(PORTC,	PIN1,Low);
	DIO_voidSetPortValue(PORTD,Low);
	DIO_voidSetPinValue(PORTD,	PIN0,High);
}
void LCD_ReturnHome()
{
	DIO_voidSetPinValue(PORTC,	PIN0,Low);
	DIO_voidSetPinValue(PORTC,	PIN1,Low);
	DIO_voidSetPortValue(PORTD,Low);
	DIO_voidSetPinValue(PORTD,	PIN1,High);
}
void LCD_Entrymode(u8 I_D)
{//I_D increment or decrement
	DIO_voidSetPinValue(PORTC,	PIN0,Low);
	DIO_voidSetPinValue(PORTC,	PIN1,Low);
	DIO_voidSetPortValue(PORTD,Low);
	DIO_voidSetPinValue(PORTD,	PIN2,High);
	DIO_voidSetPinValue(PORTD,	PIN0,High);
	if(I_D==0)
	{
		DIO_voidSetPinValue(PORTD,	PIN1,Low);
	}
	else
	{
		DIO_voidSetPinValue(PORTD,	PIN1,High);
	}
}
void LCD_Display()
{
	DIO_voidSetPinValue(PORTC,	PIN0,Low);
	DIO_voidSetPinValue(PORTC,	PIN1,Low);
	DIO_voidSetPinValue(PORTD,	PIN4,Low);
	DIO_voidSetPinValue(PORTD,	PIN5,Low);
	DIO_voidSetPinValue(PORTD,	PIN3,High);
	DIO_voidSetPinValue(PORTD,	PIN2,High);
	DIO_voidSetPinValue(PORTD,	PIN1,High);
	DIO_voidSetPinValue(PORTD,	PIN0,High);
}

void LCD_Cursor(u8 S_C, u8 R_L)
{//S_c display shift or cursor move, R_L shift right or left
	DIO_voidSetPinValue(PORTC,	PIN0,Low);
	DIO_voidSetPinValue(PORTC,	PIN1,Low);
	DIO_voidSetPortValue(PORTD,Low);
	DIO_voidSetPinValue(PORTD,	PIN4,High);
	if(S_C==0)
	{
		DIO_voidSetPinValue(PORTD,	PIN3,Low);
	}
	else
	{
		DIO_voidSetPinValue(PORTD,	PIN3,High);
	}
	if(R_L==0)
	{
		DIO_voidSetPinValue(PORTD,	PIN2,Low);
	}
	else
	{
		DIO_voidSetPinValue(PORTD,	PIN2,High);
	}
}

void LCD_Functionset()
{
	DIO_voidSetPinValue(PORTC,	PIN0,Low);
	DIO_voidSetPinValue(PORTC,	PIN1,Low);
	DIO_voidSetPortValue(PORTD,Low);
	DIO_voidSetPinValue(PORTD,	PIN4,High);
	DIO_voidSetPinValue(PORTD,	PIN5,High);
}

void LCD_SetCGRAM(u8 address)
{
	DIO_voidSetPinValue(PORTC, PIN0, Low);   
	DIO_voidSetPinValue(PORTC, PIN1, Low);   

	DPORTD = 0b01000000 | address;

	DIO_voidSetPinValue(PORTC, PIN2, High);
	_delay_ms(1);
	DIO_voidSetPinValue(PORTC, PIN2, Low);
	_delay_us(40);
}

void LCD_SetDDRAM(u8 address)
{
	DIO_voidSetPinValue(PORTC, PIN0, Low);
	DIO_voidSetPinValue(PORTC, PIN1, Low);

	DPORTD = 0b1000000 | address;

	DIO_voidSetPinValue(PORTC, PIN2, High);
	_delay_ms(1);
	DIO_voidSetPinValue(PORTC, PIN2, Low);
	_delay_us(40);
}


u8 LCD_ReadData()
{
	u8 data;

	DIO_voidSetPinValue(PORTC, PIN0, High); 
	DIO_voidSetPinValue(PORTC, PIN1, High); 
	DIO_voidSetPortDirection(PORTD, INPUT);
	DIO_voidSetPinValue(PORTC, PIN2, High);
	_delay_ms(1);
	data = DPORTD;
	DIO_voidSetPinValue(PORTC, PIN2, Low);
	DIO_voidSetPortDirection(PORTD, OUTPUT);
	return data;
}

void LCD_SendCommand(u8 command,u8 I_D,u8 S_C,u8 address)
{
	DIO_voidSetPinValue(PORTC,	PIN0,Low);
	DIO_voidSetPinValue(PORTC,	PIN1,Low);
	switch(command)
	{
		case 0:  LCD_ClearDisplay();break;
		case 1: LCD_ReturnHome();break;
		case 2:  LCD_Entrymode(I_D);break;
		case 3:  LCD_Display();break;
		case 4: LCD_Cursor(I_D,S_C);break;
		case 5: LCD_Functionset();break;
		case 6: LCD_SetCGRAM(address);break;
		case 7: LCD_SetDDRAM(address);break;
		case 8: LCD_ReadData();break;
		
		
	}
	DIO_voidSetPinValue(PORTC,	PIN2,High);
	_delay_ms(1);
	DIO_voidSetPinValue(PORTC,	PIN2,Low);
}

void LCD_init()
{
	_delay_ms(30);
	//Function Set
	DIO_voidSetPinDirection(PORTC,PIN0,OUTPUT);
	DIO_voidSetPinDirection(PORTC,PIN1,OUTPUT);
	DIO_voidSetPinDirection(PORTC,PIN2,OUTPUT);
	DIO_voidSetPortDirection(PORTD,OUTPUT);
	LCD_SendCommand(Function_set, 0, 0, 0);
	_delay_us(40);
	
	//Display ON/OFF
	LCD_SendCommand(Display, 0, 0, 0);
	_delay_us(40);
	
	//display clear
	LCD_SendCommand(Clear_display, 0, 0, 0);
	_delay_ms(2);
}

void LCD_sendChar(char Data)
{
	DPORTD = Data;
	DIO_voidSetPinValue(PORTC,	PIN0,High);
	DIO_voidSetPinValue(PORTC,	PIN1,Low);
	
	DIO_voidSetPinValue(PORTC,	PIN2,High);
	_delay_ms(1);
	DIO_voidSetPinValue(PORTC,	PIN2,Low);
	_delay_us(4);
}

void LCD_SendString (char *str)
{
	while(*str != '\0')
	{
		LCD_sendChar(*str);
		str ++;
	}
}

void LCD_voidWriteNumber(s32 num)
{
	char arr[12];
	itoa(num,arr,10);
	LCD_SendString(arr);
}