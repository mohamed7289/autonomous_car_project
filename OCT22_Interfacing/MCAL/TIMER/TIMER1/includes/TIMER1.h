/*
 * TIMER1.h
 *
 * Created: 2/11/2023 7:20:19 PM
 *  Author: user
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_

#include "TIMER1_Reg.h"
#include "TIMER1_Types.h"
#include "TIMER_Reg.h"
#include "GINT.h"
#include "avr/interrupt.h"

void TIMER1_Init(TIMER1_InitTypes * options);
void TIMER1_TOVInt_SetCallBack(void (*Timer1_OVFIntFunCopyPtr)(void));
void TIMER1_OC1AInt_SetCallBack(void (*Timer1_OC1AIntFunCopyPtr)(void));
void TIMER1_OC1BInt_SetCallBack(void (*Timer1_OC1BIntFunCopyPtr)(void));
void TIMER1_OCR1A_SetValue(u16 value);
void TIMER1_OCR1B_SetValue(u16 value);
void TIMER1_ICR_SetValue(u16 value);
#endif /* TIMER1_H_ */