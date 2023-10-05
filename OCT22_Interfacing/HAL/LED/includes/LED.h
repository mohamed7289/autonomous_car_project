/*
 * LED.h
 *
 * Created: 1/20/2023 7:59:05 PM
 *  Author: user
 */ 


#ifndef LED_H_
#define LED_H_

#include "DIO.h"

void LED_ON(DIO_ChannelTypes ChannelId);
void LED_OFF(DIO_ChannelTypes ChannelId);
void LED_Toggle(DIO_ChannelTypes ChannelId);

#endif /* LED_H_ */