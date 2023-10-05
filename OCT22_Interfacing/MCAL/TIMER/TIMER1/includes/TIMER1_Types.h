/*
* TIMER1_Types.h
*
* Created: 2/11/2023 7:26:02 PM
*  Author: user
*/


#ifndef TIMER1_TYPES_H_
#define TIMER1_TYPES_H_

#include "STD_Types.h"

typedef struct
{
	u8 WGM10_Bit:1;
	u8 WGM11_Bit:1;
	u8 FOC1B_Bit:1;
	u8 FOC1A_Bit:1;
	u8 COM1B0_Bit:1;
	u8 COM1B1_Bit:1;
	u8 COM1A0_Bit:1;
	u8 COM1A1_Bit:1;
}TIMER1_TCCR1A_Bits;

typedef struct
{
	u8 CS10_Bit:1;
	u8 CS11_Bit:1;
	u8 CS12_Bit:1;
	u8 WGM12_Bit:1;
	u8 WGM13_Bit:1;
	u8 RESERVED:1;
	u8 ICES1_Bit:1;
	u8 ICNC1_Bit:1;
}TIMER1_TCCR1B_Bits;

typedef enum{
	Normal=0,
	PWM_Phase_Correct,
	CTC,
	PWM_Fast
}TIMER1_ModeTypes;

typedef enum{
	No_Clock=0,
	No_Prescalling,
	Clock_8,
	Clock_64,
	Clock_256,
	Clock_1024,
	Clock_Ext_Falling,
	Clock_Ext_Rising
}TIMER1_ClockTypes;

typedef enum{
	COM1A_No_PWM=0,
	COM1A_Non_Inverting_PWM=2,
	COM1A_Inverting_PWM
}TIMER1_COM1APWMTypes;

typedef enum{
	COM1B_No_PWM=0,
	COM1B_Non_Inverting_PWM=2,
	COM1B_Inverting_PWM
}TIMER1_COM1BPWMTypes;

typedef enum{
	TOVInt_Disable=0,
	TOVInt_Enable
}TIMER1_TOVIntTypes;

typedef enum{
	OC1AInt_Disable=0,
	OC1AInt_Enable
}TIMER1_OC1AIntTypes;

typedef enum{
	OC1BInt_Disable=0,
	OC1BInt_Enable
}TIMER1_OC1BIntTypes;

typedef enum{
	ICInt_Disable=0,
	ICInt_Enable
}TIMER1_ICIntTypes;

typedef struct
{
	TIMER1_ModeTypes mode;
	TIMER1_ClockTypes prescalling;
	TIMER1_COM1APWMTypes COM1APWM_mode;
	TIMER1_COM1BPWMTypes COM1BPWM_mode;
	TIMER1_TOVIntTypes TOVInt_status;
	TIMER1_OC1AIntTypes OC1AInt_status;
	TIMER1_OC1BIntTypes OC1BInt_status;
	TIMER1_ICIntTypes ICInt_status;
}TIMER1_InitTypes;




#endif /* TIMER1_TYPES_H_ */