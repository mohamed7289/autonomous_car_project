/*
 * LM35.h
 *
 * Created: 2/3/2023 8:51:10 PM
 *  Author: user
 */ 


#ifndef LM35_H_
#define LM35_H_

#include "ADC.h"

void LM35_Init(ADC_InitTypes * options);
u16 LM35_Read(ADC_ChannelTypes channelID);

#endif /* LM35_H_ */