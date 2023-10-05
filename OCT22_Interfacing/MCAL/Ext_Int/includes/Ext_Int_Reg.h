/*
 * Ext_Int_Reg.h
 *
 * Created: 1/28/2023 7:45:37 PM
 *  Author: user
 */ 


#ifndef EXT_INT_REG_H_
#define EXT_INT_REG_H_

#include "STD_Types.h"

#define Ext_Int_MCUCSR_Reg (*((volatile u8*)(0x54)))
#define Ext_Int_MCUCR_Reg (*((volatile u8*)(0x55)))
#define Ext_Int_GIFR_Reg (*((volatile u8*)(0x5A)))
#define Ext_Int_GICR_Reg (*((volatile u8*)(0x5B)))

#endif /* EXT_INT_REG_H_ */