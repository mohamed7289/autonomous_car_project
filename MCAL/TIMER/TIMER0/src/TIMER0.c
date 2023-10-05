/*
* TIMER0.c
*
* Created: 2/10/2023 6:01:12 PM
*  Author: user
*/
#include "TIMER0.h"

void (*Timer0_OVFIntFunPtr)(void) = 0;
void (*Timer0_COMIntFunPtr)(void) = 0;

void TIMER0_Init(TIMER0_InitTypes * options){
	switch(options->mode){
		case Normal:
		ClearBit(TIMER0_TCCR0_Reg,TIMER0_TCCR0_WGM00_Bit);
		ClearBit(TIMER0_TCCR0_Reg,TIMER0_TCCR0_WGM01_Bit);
		break;
		case PWM_Phase_Correct:
		SetBit(TIMER0_TCCR0_Reg,TIMER0_TCCR0_WGM00_Bit);
		ClearBit(TIMER0_TCCR0_Reg,TIMER0_TCCR0_WGM01_Bit);
		break;
		case CTC:
		ClearBit(TIMER0_TCCR0_Reg,TIMER0_TCCR0_WGM00_Bit);
		SetBit(TIMER0_TCCR0_Reg,TIMER0_TCCR0_WGM01_Bit);
		break;
		case PWM_Fast:
		SetBit(TIMER0_TCCR0_Reg,TIMER0_TCCR0_WGM00_Bit);
		SetBit(TIMER0_TCCR0_Reg,TIMER0_TCCR0_WGM01_Bit);
		break;
	}
	TIMER0_TCCR0_Reg = (TIMER0_TCCR0_Reg & 0b11111000)|(options->prescalling & 0b00000111);
}

void TIMER0_OVFInt_Enable(void (*Timer0_OVFIntFunCopyPtr)(void)){
	SetBit(TIMER_TIMSK_Reg,TIMER_TIMSK_TOIE0);
	TIMER0_OVFInt_SetCallBack(Timer0_OVFIntFunCopyPtr);
}

void TIMER0_COMInt_Enable(void (*Timer0_OVFIntFunCopyPtr)(void)){
	SetBit(TIMER_TIMSK_Reg,TIMER_TIMSK_OCIE0);
	TIMER0_COMInt_SetCallBack(Timer0_OVFIntFunCopyPtr);
}

void TIMER0_OVFInt_SetCallBack(void (*Timer0_OVFIntFunCopyPtr)(void)){
	Timer0_OVFIntFunPtr = Timer0_OVFIntFunCopyPtr;
}

void TIMER0_COMInt_SetCallBack(void (*Timer0_COMIntFunCopyPtr)(void)){
	Timer0_COMIntFunPtr = Timer0_COMIntFunCopyPtr;
}

ISR(TIMER0_OVF_vect){
	Timer0_OVFIntFunPtr();
}

ISR(TIMER0_COMP_vect){
	Timer0_COMIntFunPtr();
}