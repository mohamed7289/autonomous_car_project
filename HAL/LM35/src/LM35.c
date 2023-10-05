/*
 * LM35.c
 *
 * Created: 2/3/2023 8:51:22 PM
 *  Author: user
 */ 
#include "LM35.h"

void LM35_Init(ADC_InitTypes * options){
	ADC_Init(options);
}
u16 LM35_Read(ADC_ChannelTypes channelID){
	u16 readValue = 0;
	u16 Temp = 0;
	readValue = ADC_Read(channelID);
	Temp = readValue/4;
	return Temp;
}