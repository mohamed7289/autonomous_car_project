/*
* UART_Types.h
*
* Created: 2/17/2023 7:18:15 PM
*  Author: user
*/


#ifndef UART_TYPES_H_
#define UART_TYPES_H_

#include "STD_Types.h"

#define UCSRC_SelectEnable (1<<7)

typedef struct{
	u8 MPCM_Bit:1;
	u8 U2X_Bit:1;
	u8 PE_Bit:1;
	u8 DOR_Bit:1;
	u8 FE_Bit:1;
	u8 UDRE_Bit:1;
	u8 TXC_Bit:1;
	u8 RXC_Bit:1;
}UART_UCSRA_Bits;

typedef struct{
	u8 TXB8_Bit:1;
	u8 RXB8_Bit:1;
	u8 UCSZ2_Bit:1;
	u8 TXEN_Bit:1;
	u8 RXEN_Bit:1;
	u8 UDRIE_Bit:1;
	u8 TXCIE_Bit:1;
	u8 RXCIE_Bit:1;
}UART_UCSRB_Bits;

typedef struct{
	u8 UCPOL_Bit:1;
	u8 UCSZ0_Bit:1;
	u8 UCSZ1_Bit:1;
	u8 USBS_Bit:1;
	u8 UPM0_Bit:1;
	u8 UPM1_Bit:1;
	u8 UMSEL_Bit:1;
	u8 URSEL_Bit:1;
}UART_UCSRC_Bits;

typedef union{
	u8 UCSRC_Reg;
	u8 UBRRH_Reg;
}UART_UCSRC_UBRRH_Type;

typedef struct
{
	u8 UBRRL_Reg;
	UART_UCSRB_Bits UCSRB_Reg;
	UART_UCSRA_Bits UCSRA_Reg;
	u8 UDR_Reg;
	u8 RESERVED[19];
	UART_UCSRC_UBRRH_Type UCSRC_UBRRH_Reg;
}UART_Registers;

typedef enum{
	TX_Disable=0,
	TX_Enable
}UART_TXType;

typedef enum{
	RX_Disable=0,
	RX_Enable
}UART_RXType;

typedef enum{
	Parity_Disable=0,
	Parity_Reserved,
	Parity_Even,
	Parity_Odd
}UART_ParityType;

typedef enum{
	Stop_1Bit=0,
	Stop_2Bit
}UART_StopType;

typedef enum{
	BaudRate_2400=2400,
	BaudRate_4800=4800,
	BaudRate_9600=9600
}UART_BaudRateType;

typedef enum{
	CharacterSize_5Bit=0,
	CharacterSize_6Bit,
	CharacterSize_7Bit,
	CharacterSize_8Bit,
	CharacterSize_RESERVED1,
	CharacterSize_RESERVED2,
	CharacterSize_RESERVED3,
	CharacterSize_9Bit
}UART_CharacterSizeType;

typedef struct{
	UART_BaudRateType BaudRate;
	UART_TXType TXMode;
	UART_RXType RXMode;
	UART_CharacterSizeType CharacterSize;
	UART_ParityType ParityMode;
	UART_StopType StopMode;
}UART_Config;

#endif /* UART_TYPES_H_ */