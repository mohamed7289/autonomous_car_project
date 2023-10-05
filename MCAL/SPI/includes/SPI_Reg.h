/*
 * SPI_Reg.h
 *
 * Created: 2/18/2023 7:23:15 PM
 *  Author: user
 */ 


#ifndef SPI_REG_H_
#define SPI_REG_H_

#include "SPI_Types.h"
#include "DIO.h"

#define SPI_SSPin DIO_ChannelB4
#define SPI_MOSIPin DIO_ChannelB5
#define SPI_MISOPin DIO_ChannelB6
#define SPI_SCKPin DIO_ChannelB7

#define SPI ((volatile SPI_RegistersTypes *)0x2D)

#endif /* SPI_REG_H_ */