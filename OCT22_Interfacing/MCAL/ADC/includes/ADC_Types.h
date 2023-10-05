/*
* ADC_Types.h
*
* Created: 2/3/2023 7:46:01 PM
*  Author: user
*/


#ifndef ADC_TYPES_H_
#define ADC_TYPES_H_

typedef enum{
	ADC_Channel0=0,
	ADC_Channel1,
	ADC_Channel2,
	ADC_Channel3,
	ADC_Channel4,
	ADC_Channel5,
	ADC_Channel6,
	ADC_Channel7
}ADC_ChannelTypes;

typedef enum{
	ADC_PreScaler2=1,
	ADC_PreScaler4,
	ADC_PreScaler8,
	ADC_PreScaler16,
	ADC_PreScaler32,
	ADC_PreScaler64,
	ADC_PreScaler128
}ADC_PreScalerTypes;

typedef enum{
	ADC_Vref_Aref=0,
	ADC_Vref_Avcc,
	ADC_RESERVED,
	ADC_Vref_Internal
}ADC_VrefTypes;

typedef struct  
{
	ADC_PreScalerTypes adcClock;
	ADC_VrefTypes adcVref;
}ADC_InitTypes;



#endif /* ADC_TYPES_H_ */