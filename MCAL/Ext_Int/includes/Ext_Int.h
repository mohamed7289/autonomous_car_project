/*
 * Ext_Int.h
 *
 * Created: 1/28/2023 7:50:00 PM
 *  Author: user
 */ 


#ifndef EXT_INT_H_
#define EXT_INT_H_

#include "Ext_Int_Reg.h"
#include "Ext_Int_Types.h"
#include "BitMath.h"
#include <avr/interrupt.h>


void Ext_Interrupt_Enable(Ext_Int_Types IntId);
void Ext_Interrupt_Disable(Ext_Int_Types IntId);
void Ext_Interrupt_Sncontrol(Ext_Int_Types IntId,Snc_Mode_Types mode);
void Ext_Int_SetCallBack(Ext_Int_Types IntId,void (*ExtIntFunCopyPtr)(void)) ;

#endif /* EXT_INT_H_ */