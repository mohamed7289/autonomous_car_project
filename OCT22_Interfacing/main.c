/*
* OCT22_Interfacing.c
*
* Created: 1/6/2023 2:55:18 PM
* Author : user
*/

#include <avr/interrupt.h>
#include <stdlib.h>
#include <stdio.h>
#include "DIO.h"
#include "Clock.h"
#include "Ext_Int.h"
#include "GINT.h"
#include "LED.h"
#include "STD_Types.h"
#include "TIMER1.h"
#include "Ultrasonic.h"
#include "TIMERS.h"
#include "LCD.h"
#include "motors.h"
#include "servomotor.h"

u8 x=0 ;

u8 R_Distance=0 ;
u8 L_Distance=0 ;

int main(void)
{

	DIO_Init() ;
	LCD_Init() ;
	GINT_EnableAllInterrupts() ;
	
	DIO_WriteChannel(DIO_ChannelD0,STD_High) ;
	DIO_WriteChannel(DIO_ChannelD2,STD_Low) ;
		

	MOVE_Forward() ;


	while(1)
	{
		
		
		if ((u16)Ultrasonic_Read()<17)
		{
			DIO_WriteChannel(DIO_ChannelA3,STD_High) ;
			_delay_ms(200) ;
			Stop() ;
			DIO_WriteChannel(DIO_ChannelA3,STD_Low) ;

			servomotor(90) ;  //0 position
			_delay_ms(1600) ;
			servomotor(-90) ; // right
			_delay_ms(1500) ;
			R_Distance=Ultrasonic_Read() ;
			servomotor(270) ; // left
			_delay_ms(1500) ;
			L_Distance=Ultrasonic_Read() ;
			servomotor(90) ;  //0 position
			_delay_ms(1500) ;
			
			if(R_Distance>L_Distance)
			{
				MOVE_Backward() ;
				MOVE_Right() ;
				
			}
			else
			{
				MOVE_Backward() ;
				MOVE_Left() ;
			}
		}
		
		

	}

}







