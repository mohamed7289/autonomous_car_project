/*
 * ADC_Reg.h
 *
 * Created: 2/3/2023 7:46:17 PM
 *  Author: user
 */ 


#ifndef ADC_REG_H_
#define ADC_REG_H_

#include "STD_Types.h"

#define ADC_ADMUX_Reg (*((volatile u8*)(0x27)))
#define ADC_ADCSRA_Reg (*((volatile u8*)(0x26)))
#define ADC_ADCH_Reg (*((volatile u8*)(0x25)))
#define ADC_ADCL_Reg (*((volatile u8*)(0x24)))


#endif /* ADC_REG_H_ */