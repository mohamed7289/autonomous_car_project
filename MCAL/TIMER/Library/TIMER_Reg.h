/*
 * TIMER_Reg.h
 *
 * Created: 2/11/2023 7:33:49 PM
 *  Author: user
 */ 


#ifndef TIMER_REG_H_
#define TIMER_REG_H_

#include "STD_Types.h"
#include "TIMER_Types.h"

#define TIMER_TIMSK_Reg (*((volatile TIMER_TIMSK_Bits*)(0x59)))
#define TIMER_TIFR_Reg (*((volatile TIMER_TIFR_Bits*)(0x58)))


#endif /* TIMER_REG_H_ */