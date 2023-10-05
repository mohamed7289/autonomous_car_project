

#include "GLCD.h"


void GLCD_Command (u8 command)
{
	DIO_WritePort(DATA_PORT,command) ;
	DIO_WriteChannel(DIO_ChannelC1,STD_Low) ; //make RW = 0 to write
	DIO_WriteChannel(DIO_ChannelC2,STD_Low) ; // make RS = 0 to send a command
	DIO_WriteChannel(DIO_ChannelC0,STD_High) ;
	_delay_us(5) ;
	DIO_WriteChannel(DIO_ChannelC0,STD_Low) ;
	_delay_us(5) ;
	
}
void GLCD_Init(void)
{
	DIO_WriteChannel(DIO_ChannelC3,STD_Low) ; //cs1,cs2 are active low
	DIO_WriteChannel(DIO_ChannelC4,STD_High) ;
	DIO_WriteChannel(DIO_ChannelC5,STD_High) ;
	
	_delay_ms(20);
	GLCD_Command(0x3e);		/* Display OFF */
	GLCD_Command(0x40);		/* Set Y address (column=0) */
	GLCD_Command(0xB8);		/* Set x address (page=0) */
	GLCD_Command(0xC0);		/* Set z address (start line=0) */
	GLCD_Command(0x3f);		/* Display ON */
}


void GLCD_Data(u8 data)
{
	DIO_WritePort(DATA_PORT,data) ;
	DIO_WriteChannel(DIO_ChannelC1,STD_Low) ; //make RW = 0 to write
	DIO_WriteChannel(DIO_ChannelC2,STD_High) ; // make RS = 1 to send a data
	DIO_WriteChannel(DIO_ChannelC0,STD_High) ;
	_delay_us(5) ;
	DIO_WriteChannel(DIO_ChannelC0,STD_Low) ;
	_delay_us(5) ;
	
}
void GLCD_CharCapital(u8 alphabet)
{
	u8 data = ADDRESS + (alphabet*8) ;
	for (short ct =0 ; ct<8 ; ct++)
	{
		
		DIO_WritePort(DATA_PORT,data) ;
		DIO_WriteChannel(DIO_ChannelC1,STD_Low) ; //make RW = 0 to write
		DIO_WriteChannel(DIO_ChannelC2,STD_High) ; // make RS = 1 to send a data
		DIO_WriteChannel(DIO_ChannelC0,STD_High) ;
		_delay_us(5) ;
		DIO_WriteChannel(DIO_ChannelC0,STD_Low) ;
		_delay_us(5) ;
		data +=1 ;

	}
	
}
void GLCD_CharSmall(u8 alphabet)
{
	u8 data = address + (alphabet*8) ;
	for (short ct =0 ; ct<8 ; ct++)
	{
		DIO_WritePort(DATA_PORT,data) ;
		DIO_WriteChannel(DIO_ChannelC1,STD_Low) ; //make RW = 0 to write
		DIO_WriteChannel(DIO_ChannelC2,STD_High) ; // make RS = 1 to send a data
		DIO_WriteChannel(DIO_ChannelC0,STD_High) ;
		_delay_us(5) ;
		DIO_WriteChannel(DIO_ChannelC0,STD_Low) ;
		_delay_us(5) ;
				data +=1 ;

	}
	
}


