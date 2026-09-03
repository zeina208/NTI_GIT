#include "../Headers/LCD.h"
#include "../Headers/DIO.h"

 int main(void)
 {
	 LCD_init();
	 LCD_SendString("Zeina Sherif ");
	 LCD_voidWriteNumber(20);
	 while(1)
	 {
		 
	 }
 }