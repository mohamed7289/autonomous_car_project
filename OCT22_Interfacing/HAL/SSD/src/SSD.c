/*
* SSD.c
*
* Created: 1/27/2023 3:41:45 PM
*  Author: user
*/
#include "SSD.h"

void SSD_Init(void){
	/*	Configure SSD Enable Lines as Output	*/
	DIO_ConfigChannel(DIO_ChannelB1, Output);
	DIO_ConfigChannel(DIO_ChannelB2, Output);
	/*	Configure SSD DP Line as Output	*/
	DIO_ConfigChannel(DIO_ChannelB3, Output);
	/*	Configure SSD Data Lines as Output		*/
	DIO_ConfigChannel(DIO_ChannelA4, Output);
	DIO_ConfigChannel(DIO_ChannelA5, Output);
	DIO_ConfigChannel(DIO_ChannelA6, Output);
	DIO_ConfigChannel(DIO_ChannelA7, Output);
	/*	Turn OFF SSD	*/
	DIO_WriteChannel(DIO_ChannelB1,STD_Low);
	DIO_WriteChannel(DIO_ChannelB2,STD_Low);
}
void SSD_Display(u8 num){
	u8 loc_SSD_First_Digit = (num%10)<<4;
	u8 loc_SSD_Second_Digit = (num/10)<<4;

	if (num <= 99)
	{
		/*	Enable SSD1	*/
		DIO_WriteChannel(DIO_ChannelB1,STD_High);
		/*	Disable SSD2	*/
		DIO_WriteChannel(DIO_ChannelB2,STD_Low);
		/*	Write First Digit	*/
		DIO_WriteChannelGroup(DIO_PortA,0xF0,loc_SSD_First_Digit);
		_delay_ms(1);

		/*	Disable SSD1	*/
		DIO_WriteChannel(DIO_ChannelB1,STD_Low);
		/*	Enable SSD2	*/
		DIO_WriteChannel(DIO_ChannelB2,STD_High);
		/*	Write Second Digit	*/
		DIO_WriteChannelGroup(DIO_PortA,0xF0,loc_SSD_Second_Digit);
		_delay_ms(1);
	}
	else
	{
		/*	Do Nothing	*/
	}
}
void SSD_Display_With_Delay(u8 num,u32 delay){
	u32 count = 0;
	for (count =0; count<delay; count+=3)
	{
		SSD_Display(num);
		_delay_ms(1);
	}
}