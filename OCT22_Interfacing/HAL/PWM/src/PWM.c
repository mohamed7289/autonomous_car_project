/*
 * PWM.c
 *
 * Created: 2/12/2023 4:45:55 PM
 *  Author: user
 */ 
#include "PWM.h"

void PWM_Generate_COM1A(u8 DutyCycle){
	DIO_ConfigChannel(DIO_ChannelD5,Output);
	TIMER1_InitTypes Timer1Options = {PWM_Fast,Clock_64,COM1A_Non_Inverting_PWM,COM1B_No_PWM,TOVInt_Disable,OC1AInt_Disable,OC1BInt_Disable,ICInt_Disable};
	u16 ICR1_value = (u16)0xFFFF;
	u16 OCR1A_value = (u16)((((float)DutyCycle/100)*((u32)ICR1_value+1))-1) ;
	TIMER1_ICR_SetValue(ICR1_value);
	TIMER1_OCR1A_SetValue(OCR1A_value);
	TIMER1_Init(&Timer1Options);
}
