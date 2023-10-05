/*
 * GINT.c
 *
 * Created: 1/28/2023 7:32:36 PM
 *  Author: user
 */ 
#include "GINT.h"

void GINT_EnableAllInterrupts(void){
	SetBit(GINT_SREG_Reg,GINT_SREG_Ibit);
}
void GINT_DisableAllInterrupts(void){
	ClearBit(GINT_SREG_Reg,GINT_SREG_Ibit);
}