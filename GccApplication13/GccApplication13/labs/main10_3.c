#include "../Headers/StepperMotor.h"

int main(void)
{
	motor_init();
	
	while(1)
	{
		motor_halfstep(clockwise);
	}
	
}