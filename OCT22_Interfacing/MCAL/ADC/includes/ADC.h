/*
 * ADC.h
 *
 * Created: 2/3/2023 7:46:29 PM
 *  Author: user
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "STD_Types.h"
#include "BitMath.h"
#include "ADC_Reg.h"
#include "ADC_Types.h"


#define ADC_ADCSRA_ADEN 7
#define ADC_ADCSRA_ADSC 6
#define ADC_ADCSRA_ADIF 4

void ADC_Init(ADC_InitTypes * options);
u16 ADC_Read(ADC_ChannelTypes channelID);

#endif /* ADC_H_ */