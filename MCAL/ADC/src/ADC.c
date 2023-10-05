/*
* ADC.c
*
* Created: 2/3/2023 7:46:43 PM
*  Author: user
*/
#include "ADC.h"
void ADC_Init(ADC_InitTypes * options){
	ADC_ADCSRA_Reg = (1<<ADC_ADCSRA_ADEN)|(options->adcClock);//Set Presacler & Enable ADC
	ADC_ADMUX_Reg = ((options->adcVref)<<6);//Set Vref
}
u16 ADC_Read(ADC_ChannelTypes channelID){
	u16 readValue = 0;
	ADC_ADMUX_Reg = (ADC_ADMUX_Reg & 0b11100000)|(channelID & 0b00011111);
	SetBit(ADC_ADCSRA_Reg,ADC_ADCSRA_ADSC);//ADC start conv.
	while(GetBit(ADC_ADCSRA_Reg,ADC_ADCSRA_ADIF) == 0);//waiting to finish conv.
	SetBit(ADC_ADCSRA_Reg,ADC_ADCSRA_ADIF);//Clear the Flag
	readValue = (ADC_ADCL_Reg)|(ADC_ADCH_Reg<<8);
	return readValue;
}