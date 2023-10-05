/*
 * TWI.h
 *
 * Created: 2/24/2023 7:38:34 PM
 *  Author: user
 */ 


#ifndef TWI_H_
#define TWI_H_

#include "TWI_Types.h"
#include "TWI_Reg.h"
#include "Clock.h"

#define F_TWI 400000UL
#define MyTWPS 1
#define MyTWBR (((F_CPU/F_TWI)-16)/(2*4^MyTWPS))

void TWI_Init(u8 address);
u8 TWI_Send(u8 data);
u8 TWI_Start(void);
void TWI_Stop(void);
u8 TWI_Status();
u8 TWI_Read_Ack(u8 * data);
u8 TWI_Read_NAck(u8 * data);

#endif /* TWI_H_ */