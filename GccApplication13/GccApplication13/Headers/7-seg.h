#ifndef SEG7_H
#define SEG7_H

#include "Std_Types.h"
extern u8 seg[10];


void seg_init();
void seg_setvalue(u8 PortId ,u8 num);
#endif