#include "Std_Types.h"
#define Clear_display	0
#define Return_home		1
#define Entry_mode	2
#define Display	3
#define Cursor  4
#define Function_set 5
#define Set_CGRAM 6
#define Set_DDRAM 7
#define Read_data 8



void LCD_ClearDisplay();
void LCD_ReturnHome();
void LCD_Entrymode(u8 I_D);
void LCD_Display();
void LCD_Functionset();
void LCD_Cursor(u8 S_C, u8 R_L);
void LCD_SetCGRAM(u8 address);
void LCD_SetDDRAM(u8 address);
u8 LCD_ReadData();
void LCD_voidWriteNumber(s32 num);
//init
void LCD_init();

//char
void LCD_sendChar(char Data);

//send command
void LCD_SendCommand(u8 command,u8 I_D,u8 S_C,u8 address);

//Send String
void LCD_SendString (char *str);