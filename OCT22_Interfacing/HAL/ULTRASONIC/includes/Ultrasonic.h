/*
 * Ultrasonic.h
 *
 * Created: 2/11/2023 7:45:59 PM
 *  Author: user
 */ 


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "STD_Types.h"
#include "BitMath.h"
#include "DIO.h"
#include "TIMERS.h"
#include "Clock.h"

#define TIMER1_TCCR1B_CS10_Bit 0
#define TIMER1_TCCR1B_CS11_Bit 1
#define TIMER1_TCCR1B_CS12_Bit 2

#define TIMER1_TCCR1B_ICES1_Bit 6
#define TIMER_TIFR_ICF_Bit 5

double Ultrasonic_Read();
void OVF_Counter(void) ;


#endif /* ULTRASONIC_H_ */