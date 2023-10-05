/*
* TIMER0_Types.h
*
* Created: 2/10/2023 6:09:26 PM
*  Author: user
*/


#ifndef TIMER0_TYPES_H_
#define TIMER0_TYPES_H_

typedef enum{
	Normal=0,
	PWM_Phase_Correct,
	CTC,
	PWM_Fast
}TIMER0_ModeTypes;

typedef enum{
	No_Clock=0,
	No_Prescalling,
	Clock_8,
	Clock_64,
	Clock_256,
	Clock_1024,
	Clock_Ext_Falling,
	Clock_Ext_Rising
}TIMER0_ClockTypes;

typedef struct  
{
	TIMER0_ModeTypes mode;
	TIMER0_ClockTypes prescalling;
}TIMER0_InitTypes;

#endif /* TIMER0_TYPES_H_ */