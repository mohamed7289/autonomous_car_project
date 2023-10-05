/*
 * GINT_Reg.h
 *
 * Created: 1/28/2023 7:27:00 PM
 *  Author: user
 */ 


#ifndef GINT_REG_H_
#define GINT_REG_H_

#include "STD_Types.h"

#define GINT_SREG_Ibit 7

#define GINT_SREG_Reg (*((volatile u8*)(0x5F)))

#endif /* GINT_REG_H_ */