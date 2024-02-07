#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "uitrasonic_intreface.h"
#include "util/delay.h"
#include "dc_motor_interface.h"
#include "Servo_config.h"
#include "Servo_interface.h"
#include "tim_interface.h"

u8 Global_Counter = 0;
u32 local_timval = 0;



int main(void){
	DC_MOTOR_void_init();
	ULT_Int();
	Servo_void_Init(20000);
	u16 distance = 0;
	while(1)
	{
		distance = ULT_Read();

		if (distance<30)
		{
			DC_MOTOR_STOP();
			for(u16 i = 1500 ; i <= 2000; i+=100)
			{
				TIM1_SETCHANALCOMPERMATCH(i);
				_delay_ms(1000);
				distance = ULT_Read();
				if(distance > 30){
					Move_right(500);
					_delay_ms(500);

					
					break;
				}
			}
			for(u16 i = 2000 ; i >= 1000; i-=100)
			{
				TIM1_SETCHANALCOMPERMATCH(i);
				_delay_ms(1000);
				distance = ULT_Read();
				if(distance > 30){
					Move_left(500);
					_delay_ms(500);

					break;
				}
			}
			TIM1_SETCHANALCOMPERMATCH(1500);
			_delay_ms(1000);
			GO_Straight(200);
		}
		else
		{
			GO_Straight(200);
		}


	}


	return 0;
}