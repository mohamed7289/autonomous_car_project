/*
 * Keypad.h
 *
 * Created: 1/27/2023 6:51:47 PM
 *  Author: user
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "DIO.h"

#define r0 DIO_ChannelD0
#define r1 DIO_ChannelD1
#define r2 DIO_ChannelA0
#define r3 DIO_ChannelD3

#define c0 DIO_ChannelC0
#define c1 DIO_ChannelC1
#define c2 DIO_ChannelA2
#define c3 DIO_ChannelC3

#define ColsCount 4
#define RowsCount 4

void Keypad_Init(void);
u8 GetKey(void);

#endif /* KEYPAD_H_ */