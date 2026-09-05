#include "Std_Types.h"
#define clockwise 0
#define counterclockwise 1
void motor_init();
void motor_fullstep(u8 direction);
void motor_halfstep(u8 direction);