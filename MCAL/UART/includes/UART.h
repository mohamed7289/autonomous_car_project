/*
 * UART.h
 *
 * Created: 2/17/2023 7:17:59 PM
 *  Author: user
 */ 


#ifndef UART_H_
#define UART_H_

#include "STD_Types.h"
#include "UART_Reg.h"
#include "UART_Types.h"
#include "Clock.h"

void UART_Init(UART_Config * options);
void UART_Transmite(u8 data);
u8 UART_Receive(void);
void UART_TransmiteString(s8 * string);

#endif /* UART_H_ */