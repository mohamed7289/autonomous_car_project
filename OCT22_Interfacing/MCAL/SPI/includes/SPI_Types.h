/*
* SPI_Type.h
*
* Created: 2/18/2023 7:22:57 PM
*  Author: user
*/


#ifndef SPI_TYPES_H_
#define SPI_TYPES_H_

#include "STD_Types.h"

typedef enum{
	Slave=0,
	Master
}SPI_StateTypes;

typedef enum{
	MSB=0,
	LSB
}SPI_DordTypes;

typedef struct{
	SPI_StateTypes stateMode;
	SPI_DordTypes dataorderMode;
}SPI_ConfigTypes;

typedef struct{
	u8 SPR_Bits:2;
	u8 CPHA_Bit:1;
	u8 CPOL_Bit:1;
	u8 MSTR_Bit:1;
	u8 DORD_Bit:1;
	u8 SPE_Bit:1;
	u8 SPIE_Bit:1;
}SPI_SPCRBits;

typedef union{
	u8 AllRegister;
	SPI_SPCRBits Bits;
}SPI_SPCRTypes;

typedef struct{
	u8 SPI2X_Bit:1;
	u8 RESERVED:5;
	u8 WCOL_Bit:1;
	u8 SPIF_Bit:1;
}SPI_SPSRBits;

typedef union{
	u8 AllRegister;
	SPI_SPSRBits Bits;
}SPI_SPSRTypes;

typedef struct  
{
	SPI_SPCRTypes SPCR_Reg;
	SPI_SPSRTypes SPSR_Reg;
	u8 SPDR_Reg;
}SPI_RegistersTypes;

#endif /* SPI_TYPES_H_ */