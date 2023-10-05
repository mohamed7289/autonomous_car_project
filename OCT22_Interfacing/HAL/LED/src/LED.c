/*
 * LED.c
 *
 * Created: 1/20/2023 7:59:16 PM
 *  Author: user
 */ 
#include "LED.h"

void LED_ON(DIO_ChannelTypes ChannelId){
	DIO_WriteChannel(ChannelId,STD_High);
}
void LED_OFF(DIO_ChannelTypes ChannelId){
	DIO_WriteChannel(ChannelId,STD_Low);
}
void LED_Toggle(DIO_ChannelTypes ChannelId){
	DIO_ToggleChannel(ChannelId);
}