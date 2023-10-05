/*
 * TIMER1_Reg.h
 *
 * Created: 2/11/2023 7:20:04 PM
 *  Author: user
 */ 


#ifndef TIMER1_REG_H_
#define TIMER1_REG_H_

#include "STD_Types.h"

#define TIMER1_TCCR1A_Reg (*((volatile TIMER1_TCCR1A_Bits*)(0x4F)))
#define TIMER1_TCCR1B_Reg (*((volatile TIMER1_TCCR1B_Bits*)(0x4E)))
#define TIMER1_OCR1A_Reg (*((volatile u16*)(0x4A)))
#define TIMER1_OCR1B_Reg (*((volatile u16*)(0x48)))
#define TIMER1_TCNT1_Reg (*((volatile u16*)(0x4C)))
#define TIMER1_ICR1_Reg (*((volatile u16*)(0x46)))


#endif /* TIMER1_REG_H_ */