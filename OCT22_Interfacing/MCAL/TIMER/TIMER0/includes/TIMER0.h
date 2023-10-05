/*
 * TIMER0.h
 *
 * Created: 2/10/2023 5:59:58 PM
 *  Author: user
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#include "TIMER0_Reg.h"
#include "TIMER0_Types.h"
#include "BitMath.h"
#include "TIMER_Reg.h"
#include <avr/interrupt.h>

void TIMER0_Init(TIMER0_InitTypes * options);
void TIMER0_OVFInt_Enable(void (*Timer0_OVFIntFunCopyPtr)(void));
void TIMER0_COMInt_Enable(void (*Timer0_OVFIntFunCopyPtr)(void));
void TIMER0_OVFInt_SetCallBack(void (*Timer0_OVFIntFunCopyPtr)(void));
void TIMER0_COMInt_SetCallBack(void (*Timer0_COMIntFunCopyPtr)(void));

#endif /* TIMER0_H_ */