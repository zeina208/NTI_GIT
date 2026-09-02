#include"../Headers/Std_Types.h"
#include"../Headers/Bit_Maths.h"
#include "../Headers/DIO.h"

void	DIO_voidSetPortDirection	(u8 PortId,u8 Direction)
{
    if(Direction == OUTPUT)
    {
        switch(PortId)
        {
            case 0: DDRA = 0b11111111; break;
            case 1: DDRB = 0b11111111; break;
            case 2: DDRC = 0b11111111; break;
            case 3: DDRD = 0b11111111; break;
        }
    }
    else if(Direction == INPUT)
    {
        switch(PortId)
        {
            case 0: DDRA = 0b00000000; break;
            case 1: DDRB = 0b00000000; break;
            case 2: DDRC = 0b00000000; break;
            case 3: DDRD = 0b00000000; break;
        }
    }
}

void	DIO_voidSetPinDirection		(u8 PortId,u8 PinId,u8 Direction)
{
    if(Direction == OUTPUT)
    {
        switch(PortId)
        {
            case PORTA: SET_BIT(DDRA,PinId); break;
            case PORTB: SET_BIT(DDRB,PinId); break;
            case PORTC: SET_BIT(DDRC,PinId); break;
            case PORTD: SET_BIT(DDRD,PinId); break;
        }
    }
    else if(Direction == INPUT)
    {
        switch(PortId)
        {
            case PORTA: CLS_BIT(DDRA,PinId); break;
            case PORTB: CLS_BIT(DDRB,PinId); break;
            case PORTC: CLS_BIT(DDRC,PinId); break;
            case PORTD: CLS_BIT(DDRD,PinId); break;
        }
    }
}

void	DIO_voidSetPinValue(u8 PortId,u8 PinId,u8 Value)
{
    if(Value == High)
    {
        switch(PortId)
        {
            case 0:SET_BIT(DPORTA,PinId); break;
            case 1:SET_BIT(DPORTB,PinId); break;
            case 2:SET_BIT(DPORTC,PinId); break;
            case 3:SET_BIT(DPORTD,PinId); break;
        }
    }
    else if(Value == Low)
    {
        switch(PortId)
        {
            case 0:CLS_BIT(DPORTA,PinId); break;
            case 1:CLS_BIT(DPORTB,PinId); break;
            case 2:CLS_BIT(DPORTC,PinId); break;
            case 3:CLS_BIT(DPORTD,PinId); break;
        }
    }
}

u8		DIO_u8GetPinValue(u8 PortId,u8 PinId)
{   
    u8 value;
    switch(PortId)
    {
        case 0: value = GET_BIT(PINA,PinId); break;
        case 1: value = GET_BIT(PINB,PinId); break;
        case 2: value = GET_BIT(PINC,PinId); break;
        case 3: value = GET_BIT(PIND,PinId); break;
    }
    return value;
}

void	DIO_voidSetPortValue(u8 PortId,u8 Value)
{
    if(Value == High)
    {
        switch(PortId)
        {
            case 0: DPORTA = 0b11111111; break;
            case 1: DPORTB = 0b11111111; break;
            case 2: DPORTC = 0b11111111; break;
            case 3: DPORTD = 0b11111111; break;
        }
    }
    else if(Value == Low)
    {
        switch(PortId)
        {
            case 0: DPORTA = 0b00000000; break;
            case 1: DPORTB = 0b00000000; break;
            case 2: DPORTC = 0b00000000; break;
            case 3: DPORTD = 0b00000000; break;
        }
    }

}