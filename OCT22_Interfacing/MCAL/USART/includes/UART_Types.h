/*
* UART_Types.h
*
* Created: 2/17/2023 7:18:15 PM
*  Author: mohamed adel
*/


#ifndef UART_TYPES_H_
#define UART_TYPES_H_



#include "STD_Types.h"

#define UCSRC_SelectEnable (1<<7)

typedef struct
{
	u8 MBCM_Bit:1 ;
	u8 U2X_Bit:1 ;
	u8 BE_Bit:1 ;
	u8 DOR_Bit:1 ;
	u8 FE_Bit:1 ;
	u8 UDRE_Bit:1 ;
	u8 TXC_Bit:1 ;
	u8 RXC_Bit:1 ;


}UART_UCSRA_Bits;

typedef struct
{

	u8 TXB8_Bit:1 ;
	u8 RXB8_Bit:1 ;
	u8 UCSZ2_Bit:1 ;
	u8 TXEN_Bit:1 ;
	u8 RXEN_Bit:1 ;
	u8 UDRIE_Bit:1 ;
	u8 TXCIE_Bit:1 ;
	u8 RXCIE_Bit:1 ;


}UART_UCSRB_Bits;

typedef struct
{
	u8 UCBOL_Bit:1 ;
	u8 UCSZ0_Bit:1 ;
	u8 UCSZ1_Bit:1 ;
	u8 USBS_Bit:1 ;
	u8 UPM0_Bit:1 ;
	u8 UPM1_Bit:1 ;
	u8 UMSEL_Bit:1 ;
	u8 URSEL_Bit:1 ;


}UART_UCSRC_Bits;

typedef union
{
	u8 UCSRC_Reg ;
	u8 UBRRH_Reg ;

}UART_UCSRC_UBRRH_Type;

typedef struct
{
	u8 UBRRL_Reg ;
	UART_UCSRB_Bits UCSRB_Reg ;
	UART_UCSRA_Bits UCSRA_Reg ;
	u8 UDR_Reg ;
	u8 RESERVED[19] ;
	UART_UCSRC_UBRRH_Type UCSRC_UBRRH_Reg ;
	
}UART_Reg;

typedef enum
{
	TX_Disable=0 ,
	TX_Enable ,

}UART_TXTypes;

typedef enum
{
	RX_Disable=0 ,
	RX_Enable ,

}UART_RXTypes;


typedef enum
{
	CharacterSize_5Bit=0,
	CharacterSize_6Bit=0,
	CharacterSize_7Bit=0,
	CharacterSize_8Bit=0,
	CharacterSize_reserved1,
	CharacterSize_reserved2,
	CharacterSize_reserved3,
	CharacterSize_9Bit=0,
	
}UART_CharacterSizeTypes;

typedef enum
{
	Parity_Disable=0 ,
	Parity_Reserved ,
	Parity_Even ,
	Parity_Odd ,

}UART_ParityTypes;


typedef enum
{
	Stop_1Bit=0 ,
	Stop_2Bit ,
	
}UART_StopTypes;

typedef enum
{
	BaudRate_2400=2400,
	BaudRate_4800=4800,
	BaudRate_9600=9600,

	
}UART_BaudRateTypes;


typedef struct
{
	UART_BaudRateTypes BaudRate ;
	UART_TXTypes TXMode ;
	UART_RXTypes RXMode ;
	UART_ParityTypes ParityMode ;
	UART_StopTypes StopMode ;
	UART_CharacterSizeTypes CharacterSize ;
	
}UART_Config;

#endif /* UART_TYPES_H_ */