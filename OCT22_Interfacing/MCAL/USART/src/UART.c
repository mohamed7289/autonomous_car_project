/*
* UART.c
*
* Created: 2/17/2023 7:21:03 PM
*  Author: mohamed adel
*/

#include "UART.h"

void UART_Init(UART_Config * options)
{
	u16 MyBaudRate=	((F_CPU/(16UL * options->BaudRate))-1) ;
	UART->UBRRL_Reg=MyBaudRate ;
	UART->UCSRC_UBRRH_Reg.UBRRH_Reg=MyBaudRate>>8 ;
	if(options->CharacterSize==CharacterSize_9Bit)
	{
		
	}
	else
	{
		
		UART->UCSRC_UBRRH_Reg.UCSRC_Reg |=(UCSRC_SelectEnable)|(options->CharacterSize<<1) ;
		
	}
	
	UART->UCSRC_UBRRH_Reg.UCSRC_Reg|=(UCSRC_SelectEnable)|(options->ParityMode<<4) ;
	UART->UCSRC_UBRRH_Reg.UCSRC_Reg|=(UCSRC_SelectEnable)|(options->StopMode<<3) ;
	if (options->TXMode==TX_Enable)
	{
		UART->UCSRB_Reg.TXEN_Bit = TX_Enable ;
	}
	else
	{
		UART->UCSRB_Reg.TXEN_Bit=TX_Disable ;

	}
	
	if (options->RXMode==RX_Enable)
	{
		UART->UCSRB_Reg.RXEN_Bit=RX_Enable ;
	}
	else
	{
		UART->UCSRB_Reg.RXEN_Bit=RX_Disable ;

	}

	
}
void UART_Transmite(u8 data)
{
	while(UART->UCSRA_Reg.UDRE_Bit==0) ;
	UART->UDR_Reg = data ;
	
}
u8 UART_Receive(void)
{
	while(UART->UCSRA_Reg.RXC_Bit==0) ;

	return UART->UDR_Reg ;
	
	
}
void UART_TransmiteString(u8 * string)
{
	
	u8 i=0 ;
	
	while(string[i]!='\0')
	{
		UART_Transmite(string[i]) ;
		i++ ;
	}
	
}