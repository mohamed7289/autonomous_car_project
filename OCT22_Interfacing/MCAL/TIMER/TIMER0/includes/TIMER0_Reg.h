/*
 * TIMER0_Reg.h
 *
 * Created: 2/10/2023 5:59:37 PM
 *  Author: user
 */ 


#ifndef TIMER0_REG_H_
#define TIMER0_REG_H_

#include "STD_Types.h"

#define TIMER0_TCCR0_Reg (*((volatile u8*)(0x53)))
#define TIMER0_OCR0_Reg (*((volatile u8*)(0x5C)))
#define TIMER0_TCNT0_Reg (*((volatile u8*)(0x52)))

#define TIMER0_TCCR0_WGM00_Bit 6
#define TIMER0_TCCR0_WGM01_Bit 3
#define TIMER_TIMSK_TOIE0 0
#define TIMER_TIMSK_OCIE0 1

#endif /* TIMER0_REG_H_ */