/*
* servomotor.c
*
* Created: 9/13/2023 2:36:54 AM
*  Author: mohamed adel
*/
#include "servomotor.h"

void servomotor(s32 angle)
{
	DIO_ConfigChannel(DIO_ChannelD5,Output) ;
	TIMER1_InitTypes Timer1Options = {PWM_Fast,Clock_64,COM1A_Non_Inverting_PWM,COM1B_No_PWM,TOVInt_Disable,OC1AInt_Disable,OC1BInt_Disable,ICInt_Disable};
	u16 ICR1_value = 4999;
	u16 OCR1A_value = (u16)(((angle-miniangle)*((float)(maxcount-minicount))/(maxangle-miniangle)))+minicount-1 ;
	TIMER1_ICR_SetValue(ICR1_value);
	TIMER1_OCR1A_SetValue(OCR1A_value);
	TIMER1_Init(&Timer1Options);
}
