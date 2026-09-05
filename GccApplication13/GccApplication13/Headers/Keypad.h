#ifndef KEYPAD_H
#define KEYPAD_H

#include "Std_Types.h"

extern u8 arr[4][4];


s8 Keypad_press();
void Keypad_init();

#endif