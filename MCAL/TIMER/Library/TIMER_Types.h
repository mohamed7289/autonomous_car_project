/*
 * TIMER_Types.h
 *
 * Created: 2/11/2023 7:34:04 PM
 *  Author: user
 */ 


#ifndef TIMER_TYPES_H_
#define TIMER_TYPES_H_

typedef struct
{
	u8 TOIE0_Bit:1;
	u8 OCIE0_Bit:1;
	u8 TOIE1_Bit:1;
	u8 OCIE1B_Bit:1;
	u8 OCIE1A_Bit:1;
	u8 TICIE1_Bit:1;
	u8 TOIE2_Bit:1;
	u8 OCIE2_Bit:1;
}TIMER_TIMSK_Bits;

typedef struct
{
	u8 TOV0_Bit:1;
	u8 OCF0_Bit:1;
	u8 TOV1_Bit:1;
	u8 OCF1B_Bit:1;
	u8 OCF1A_Bit:1;
	u8 ICF1_Bit:1;
	u8 TOV2_Bit:1;
	u8 OCF2_Bit:1;
}TIMER_TIFR_Bits;


#endif /* TIMER_TYPES_H_ */