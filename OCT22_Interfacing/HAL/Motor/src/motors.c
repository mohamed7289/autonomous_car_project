/*
* motors.c
*
* Created: 7/24/2023 11:29:40 AM
*  Author: mohamed adel
*/

#include "motors.h"


void Left_Front_Wheel_Forward(void)
{
	DIO_WriteChannel(DIO_ChannelC3,STD_High) ;
	DIO_WriteChannel(DIO_ChannelC4,STD_Low) ;
}
void Right_Front_Wheel_Forward(void)
{
	DIO_WriteChannel(DIO_ChannelC5,STD_High) ;
	DIO_WriteChannel(DIO_ChannelC6,STD_Low) ;
}
void Left_Back_Wheel_Forward(void)
{
	DIO_WriteChannel(DIO_ChannelB6,STD_High) ;
	DIO_WriteChannel(DIO_ChannelB7,STD_Low) ;
}
void Right_Back_Wheel_Forward(void)
{
	DIO_WriteChannel(DIO_ChannelB4,STD_High) ;
	DIO_WriteChannel(DIO_ChannelB5,STD_Low) ;
}
void Left_Front_Wheel_Backward(void)
{
	DIO_WriteChannel(DIO_ChannelC3,STD_Low) ;
	DIO_WriteChannel(DIO_ChannelC4,STD_High) ;
}
void Right_Front_Wheel_Backward(void)
{
	DIO_WriteChannel(DIO_ChannelC5,STD_Low) ;
	DIO_WriteChannel(DIO_ChannelC6,STD_High) ;
}
void Left_Back_Wheel_Backward(void)
{
	DIO_WriteChannel(DIO_ChannelB6,STD_Low) ;
	DIO_WriteChannel(DIO_ChannelB7,STD_High) ;
}
void Right_Back_Wheel_Backward(void)
{
	DIO_WriteChannel(DIO_ChannelB4,STD_Low) ;
	DIO_WriteChannel(DIO_ChannelB5,STD_High) ;
}

void MOVE_Forward(void)
{
	
	
	
	Left_Back_Wheel_Forward() ;
	Right_Back_Wheel_Forward() ;
	Left_Front_Wheel_Forward() ;
	Right_Front_Wheel_Forward() ;
	
	
	LCD_String("moving forward") ;
	
	
	
}
void MOVE_Right(void)
{
	LCD_String("moving right") ;
	
	Left_Back_Wheel_Forward() ;
	Left_Front_Wheel_Forward() ;
		
	_delay_ms(2225) ;
	Stop() ;
	_delay_ms(500) ;
	MOVE_Forward() ;
	
	
	
}
void MOVE_Left(void)
{
	LCD_String("moving left") ;
	
	Left_Back_Wheel_Backward() ;
	Left_Front_Wheel_Backward() ;
	//Left_Back_Wheel_Backward() ;
	
	_delay_ms(2225) ;
	Stop() ;
	_delay_ms(500) ;
	MOVE_Forward() ;
	
}
void MOVE_Backward(void)
{
	Left_Back_Wheel_Backward() ;
	Right_Back_Wheel_Backward() ;
	Left_Front_Wheel_Backward() ;
	Right_Front_Wheel_Backward() ;
	_delay_ms(700) ;
	Stop() ;
	
}
void Stop(void)
{
	LCD_String("Stop") ;
	LCD_Cmd(0x01) ;
	
	DIO_WriteChannel(DIO_ChannelC3,STD_Low) ;
	DIO_WriteChannel(DIO_ChannelC5,STD_Low) ;
	DIO_WriteChannel(DIO_ChannelB4,STD_Low) ;
	DIO_WriteChannel(DIO_ChannelB6,STD_Low) ;

	DIO_WriteChannel(DIO_ChannelC4,STD_Low) ;
	DIO_WriteChannel(DIO_ChannelC6,STD_Low) ;
	DIO_WriteChannel(DIO_ChannelB5,STD_Low) ;
	DIO_WriteChannel(DIO_ChannelB7,STD_Low) ;
	
}

/*  put in main while using proteus

DIO_WriteChannel(DIO_ChannelD2,STD_High) ;
DIO_WriteChannel(DIO_ChannelD5,STD_High) ;
DIO_WriteChannel(DIO_ChannelD0,STD_High) ;
DIO_WriteChannel(DIO_ChannelD6,STD_High) ;

*/