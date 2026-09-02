#include "Std_Types.h"
#include "Bit_Maths.h"
#define INPUT 0
#define OUTPUT 1
 
#define Low 0
#define High 1

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define DDRA *((volatile u8 *)0x3A)
#define DPORTA *((volatile u8 *)0x3B)
#define PINA *((volatile u8 *)0x39)

#define DDRB *((volatile u8 *)0x37)
#define DPORTB *((volatile u8 *)0x38)
#define PINB *((volatile u8 *)0x36)

#define DDRC *((volatile u8 *)0x34)
#define DPORTC *((volatile u8 *)0x35)
#define PINC *((volatile u8 *)0x33)

#define DDRD *((volatile u8 *)0x31)
#define DPORTD *((volatile u8 *)0x32)
#define PIND *((volatile u8 *)0x30)

 
 
void	DIO_voidSetPinDirection		(u8 PortId,u8 PinId,u8 Direction); //DDR FOR EVERY PIN
 
void	DIO_voidSetPinValue			(u8 PortId,u8 PinId,u8 Value);//PORT FOR EVERY PIN
 
u8		DIO_u8GetPinValue			(u8 PortId,u8 PinId);//RETURN PIN VALUE
 
 
void	DIO_voidSetPortDirection	(u8 PortId,u8 Direction);//DDR FOR ALL PINS , PORT

void	DIO_voidSetPortValue		(u8 PortId,u8 Value);//PORT_REGISTER FOR ALL PINS
 