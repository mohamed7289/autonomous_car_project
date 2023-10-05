/*
 * EEPROM.h
 *
 * Created: 2/25/2023 7:00:24 PM
 *  Author: user
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "TWI.h"

void EEPROM_WriteByte(u8 DeviceAdd,u8 LocAdd,u8 data);
u8 EEPROM_ReadByte(u8 DeviceAdd,u8 LocAdd);

#endif /* EEPROM_H_ */