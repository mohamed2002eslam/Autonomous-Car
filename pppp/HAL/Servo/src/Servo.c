

#include"util/delay.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Dio_interface.h"

#include "Servo_config.h"
#include "Servo_interface.h"


void Servo_void_Init(u16 TopValue){
	DIO_voidSetPinDirection(DIO_u8PORT_D, DIO_u8PIN_5, DIO_u8OUTPUT); //Servo PWM Signal
	TIM1_VoidInt();
	TIM1_TOPVALU(TopValue);
}