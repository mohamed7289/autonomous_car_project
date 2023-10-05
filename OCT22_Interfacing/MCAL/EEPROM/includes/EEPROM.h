/*
 * EEPROM.h
 *
 * Created: 2/25/2023 7:01:31 PM
 *  Author: mohamed adel
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "TWI.h"

void EEPROMWriteBYTE(u8 DeviceAdd, u8 LocAdd , u8 data) ;
u8 EEPROM_ReadByte(u8 DeviceAdd, u8 LocAdd ) ;



#endif /* EEPROM_H_ */