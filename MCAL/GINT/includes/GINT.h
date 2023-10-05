/*
 * GINT.h
 *
 * Created: 1/28/2023 7:26:29 PM
 *  Author: user
 */ 


#ifndef GINT_H_
#define GINT_H_

#include "GINT_Reg.h"
#include "BitMath.h"

void GINT_EnableAllInterrupts(void);
void GINT_DisableAllInterrupts(void);

#endif /* GINT_H_ */