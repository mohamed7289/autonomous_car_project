/*
* SPI.c
*
* Created: 2/18/2023 7:23:30 PM
*  Author: user
*/
#include "SPI.h"

void SPI_Init(SPI_ConfigTypes * options){
	switch(options->stateMode){
		case Master:
		DIO_ConfigChannel(SPI_SSPin,Output);
		DIO_ConfigChannel(SPI_MOSIPin,Output);
		DIO_ConfigChannel(SPI_MISOPin,Input);
		DIO_ConfigChannel(SPI_SCKPin,Output);
		SPI->SPCR_Reg.Bits.MSTR_Bit = 1;
		SPI->SPCR_Reg.Bits.SPE_Bit = 1;
		break;
		case Slave:
		DIO_ConfigChannel(SPI_SSPin,Input);
		DIO_ConfigChannel(SPI_MOSIPin,Input);
		DIO_ConfigChannel(SPI_MISOPin,Output);
		DIO_ConfigChannel(SPI_SCKPin,Input);
		SPI->SPCR_Reg.Bits.SPE_Bit = 1;
		break;
		default:
		break;
	}
	if (options->dataorderMode == LSB)
	{
		SPI->SPCR_Reg.Bits.DORD_Bit = 1;
	}
	else
	{
		SPI->SPCR_Reg.Bits.DORD_Bit = 0;
	}
}
u8 SPI_TxRx(u8 data){
	SPI->SPDR_Reg = data;
	while(SPI->SPSR_Reg.Bits.SPIF_Bit == 0);
	return SPI->SPDR_Reg;
}
void SPI_SlaveEnable(DIO_ChannelTypes channelId){
	DIO_ConfigChannel(channelId,Output);
	DIO_WriteChannel(channelId,STD_Low);
}
void SPI_SlaveDisable(DIO_ChannelTypes channelId){
	DIO_ConfigChannel(channelId,Output);
	DIO_WriteChannel(channelId,STD_High);
}