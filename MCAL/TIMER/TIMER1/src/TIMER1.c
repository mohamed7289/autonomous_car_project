/*
* TIMER1.c
*
* Created: 2/11/2023 7:43:38 PM
*  Author: user
*/
#include "TIMER1.h"

void (*Timer1_TOVIntFunPtr)(void) = 0;
void (*Timer1_OC1AIntFunPtr)(void) = 0;
void (*Timer1_OC1BIntFunPtr)(void) = 0;
void (*Timer1_ICUIntFunPtr)(void) = 0;


void TIMER1_Init(TIMER1_InitTypes * options){
	switch(options->mode){
		case Normal:
		TIMER1_TCCR1A_Reg.WGM10_Bit = 0;
		TIMER1_TCCR1A_Reg.WGM11_Bit = 0;
		TIMER1_TCCR1B_Reg.WGM12_Bit = 0;
		TIMER1_TCCR1B_Reg.WGM13_Bit = 0;
		break;
		case CTC:
		TIMER1_TCCR1A_Reg.WGM10_Bit = 0;
		TIMER1_TCCR1A_Reg.WGM11_Bit = 0;
		TIMER1_TCCR1B_Reg.WGM12_Bit = 1;
		TIMER1_TCCR1B_Reg.WGM13_Bit = 0;
		break;
		case PWM_Fast:
		TIMER1_TCCR1A_Reg.WGM10_Bit = 0;
		TIMER1_TCCR1A_Reg.WGM11_Bit = 1;
		TIMER1_TCCR1B_Reg.WGM12_Bit = 1;
		TIMER1_TCCR1B_Reg.WGM13_Bit = 1;
		break;
		case PWM_Phase_Correct:
		TIMER1_TCCR1A_Reg.WGM10_Bit = 1;
		TIMER1_TCCR1A_Reg.WGM11_Bit = 1;
		TIMER1_TCCR1B_Reg.WGM12_Bit = 0;
		TIMER1_TCCR1B_Reg.WGM13_Bit = 0;
		break;
	}
	switch(options->prescalling){
		case No_Clock:
		TIMER1_TCCR1B_Reg.CS10_Bit = 0;
		TIMER1_TCCR1B_Reg.CS11_Bit = 0;
		TIMER1_TCCR1B_Reg.CS12_Bit = 0;
		break;
		case No_Prescalling:
		TIMER1_TCCR1B_Reg.CS10_Bit = 1;
		TIMER1_TCCR1B_Reg.CS11_Bit = 0;
		TIMER1_TCCR1B_Reg.CS12_Bit = 0;
		break;
		case Clock_8:
		TIMER1_TCCR1B_Reg.CS10_Bit = 0;
		TIMER1_TCCR1B_Reg.CS11_Bit = 1;
		TIMER1_TCCR1B_Reg.CS12_Bit = 0;
		break;
		case Clock_64:
		TIMER1_TCCR1B_Reg.CS10_Bit = 1;
		TIMER1_TCCR1B_Reg.CS11_Bit = 1;
		TIMER1_TCCR1B_Reg.CS12_Bit = 0;
		break;
		case Clock_256:
		TIMER1_TCCR1B_Reg.CS10_Bit = 0;
		TIMER1_TCCR1B_Reg.CS11_Bit = 0;
		TIMER1_TCCR1B_Reg.CS12_Bit = 1;
		break;
		case Clock_1024:
		TIMER1_TCCR1B_Reg.CS10_Bit = 1;
		TIMER1_TCCR1B_Reg.CS11_Bit = 0;
		TIMER1_TCCR1B_Reg.CS12_Bit = 1;
		break;
		case Clock_Ext_Falling:
		TIMER1_TCCR1B_Reg.CS10_Bit = 0;
		TIMER1_TCCR1B_Reg.CS11_Bit = 1;
		TIMER1_TCCR1B_Reg.CS12_Bit = 1;
		break;
		case Clock_Ext_Rising:
		TIMER1_TCCR1B_Reg.CS10_Bit = 1;
		TIMER1_TCCR1B_Reg.CS11_Bit = 1;
		TIMER1_TCCR1B_Reg.CS12_Bit = 1;
		break;
	}
	switch(options->COM1APWM_mode){
		case COM1A_No_PWM:
		TIMER1_TCCR1A_Reg.COM1A0_Bit = 0;
		TIMER1_TCCR1A_Reg.COM1A1_Bit = 0;
		break;
		case COM1A_Non_Inverting_PWM:
		TIMER1_TCCR1A_Reg.COM1A0_Bit = 0;
		TIMER1_TCCR1A_Reg.COM1A1_Bit = 1;
		break;
		case COM1A_Inverting_PWM:
		TIMER1_TCCR1A_Reg.COM1A0_Bit = 1;
		TIMER1_TCCR1A_Reg.COM1A1_Bit = 1;
		break;
	}
	switch(options->COM1BPWM_mode){
		case COM1B_No_PWM:
		TIMER1_TCCR1A_Reg.COM1B0_Bit = 0;
		TIMER1_TCCR1A_Reg.COM1B1_Bit = 0;
		break;
		case COM1B_Non_Inverting_PWM:
		TIMER1_TCCR1A_Reg.COM1B0_Bit = 0;
		TIMER1_TCCR1A_Reg.COM1B1_Bit = 1;
		break;
		case COM1B_Inverting_PWM:
		TIMER1_TCCR1A_Reg.COM1B0_Bit = 1;
		TIMER1_TCCR1A_Reg.COM1B1_Bit = 1;
		break;
	}
	if (options->TOVInt_status == TOVInt_Enable){
		TIMER_TIMSK_Reg.TOIE1_Bit = 1;
		GINT_EnableAllInterrupts();
	}
	else{
		TIMER_TIMSK_Reg.TOIE1_Bit = 0;
	}
	if (options->OC1AInt_status == OC1AInt_Enable){
		TIMER_TIMSK_Reg.OCIE1A_Bit = 1;
		GINT_EnableAllInterrupts();
	}
	else{
		TIMER_TIMSK_Reg.OCIE1A_Bit = 0;
	}
	if (options->OC1BInt_status == OC1BInt_Enable){
		TIMER_TIMSK_Reg.OCIE1B_Bit = 1;
		GINT_EnableAllInterrupts();
	}
	else{
		TIMER_TIMSK_Reg.OCIE1B_Bit = 0;
	}
	if (options->ICInt_status == ICInt_Enable){
		TIMER_TIMSK_Reg.TICIE1_Bit = 1;
		GINT_EnableAllInterrupts();
	}
	else
	{
		TIMER_TIMSK_Reg.TICIE1_Bit = 0;
	}
}
void TIMER1_TOVInt_SetCallBack(void (*Timer1_OVFIntFunCopyPtr)(void)){
	Timer1_TOVIntFunPtr = Timer1_OVFIntFunCopyPtr;
}

void TIMER1_OC1AInt_SetCallBack(void (*Timer1_OC1AIntFunCopyPtr)(void)){
	Timer1_OC1AIntFunPtr = Timer1_OC1AIntFunCopyPtr;
}

void TIMER1_OC1BInt_SetCallBack(void (*Timer1_OC1BIntFunCopyPtr)(void)){
	Timer1_OC1BIntFunPtr = Timer1_OC1BIntFunCopyPtr;
}

void TIMER1_ICUInt_SetCallBack(void (*Timer1_ICUIntFunCopyPtr)(void)){
	Timer1_ICUIntFunPtr = Timer1_ICUIntFunCopyPtr;
}

void TIMER1_OCR1A_SetValue(u16 value){
	TIMER1_OCR1A_Reg = value;
}

void TIMER1_OCR1B_SetValue(u16 value){
	TIMER1_OCR1B_Reg = value;
}

void TIMER1_ICR_SetValue(u16 value){
	TIMER1_ICR1_Reg = value;
}

ISR(TIMER1_OVF_vect){
	Timer1_TOVIntFunPtr();
}

ISR(TIMER1_COMPA_vect){
	Timer1_OC1AIntFunPtr();
}

ISR(TIMER1_COMPB_vect){
	Timer1_OC1BIntFunPtr();
}
ISR(TIMER1_CAPT_vect)
{
	Timer1_ICUIntFunPtr() ;
}