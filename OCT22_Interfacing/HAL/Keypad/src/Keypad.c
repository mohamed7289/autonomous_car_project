/*
* Keypad.c
*
* Created: 1/27/2023 6:52:07 PM
*  Author: user
*/
#include "Keypad.h"

u8 KeypadRows[RowsCount] = {r0,r1,r2,r3};
u8 KeypadCols[ColsCount] = {c0,c1,c2,c3};
u8 Keypad[RowsCount][ColsCount] = {{'7','8','9','/'},
{'4','5','6','*'},
{'1','2','3','-'},
{'C','0','=','+'}};

void Keypad_Init(void){
	//config Col. Input
	DIO_ConfigChannel(c0,Input);
	DIO_ConfigChannel(c1,Input);
	DIO_ConfigChannel(c2,Input);
	DIO_ConfigChannel(c3,Input);
	
	//config rows output
	DIO_ConfigChannel(r0,Output);
	DIO_ConfigChannel(r1,Output);
	DIO_ConfigChannel(r2,Output);
	DIO_ConfigChannel(r3,Output);
}
u8 GetKey(void){
	for (u8 w=0;w<ColsCount;w++)
	{
		DIO_WriteChannel(KeypadRows[w],STD_High);//OUTPUT ->5V
		DIO_WriteChannel(KeypadCols[w],STD_High);//INPUT -> Pullup 
	}
	for(u8 i=0;i<RowsCount;i++){
		DIO_WriteChannel(KeypadRows[i],STD_Low);
		for(u8 j=0;j<ColsCount;j++){
			if(DIO_ReadChannel(KeypadCols[j]) == STD_Low){
				while(DIO_ReadChannel(KeypadCols[j]) == STD_Low);
				return Keypad[i][j];
			}
		}
		DIO_WriteChannel(KeypadRows[i],STD_High);
	}
	return STD_Low;
}