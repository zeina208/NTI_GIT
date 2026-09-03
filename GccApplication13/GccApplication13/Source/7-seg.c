#include "../Headers/7-seg.h"
#include "../Headers/DIO.h"


u8 seg[10] ={0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111};
void seg_init()
{
	DIO_voidSetPortDirection(PORTD,OUTPUT);
}

void seg_setvalue( u8 PortId , u8 num)
{
	u8 x = seg[num];
	for(int i =0; i<8;i++)
	{
		DIO_voidSetPinValue(PortId,i,GET_BIT(x,i));
	}
}