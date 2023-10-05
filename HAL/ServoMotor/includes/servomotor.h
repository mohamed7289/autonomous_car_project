/*
 * servomotor.h
 *
 * Created: 9/13/2023 2:36:40 AM
 *  Author: mohamed adel
 */ 


#ifndef SERVOMOTOR_H_
#define SERVOMOTOR_H_

#include "TIMER1.h"
#include "DIO.h"

#define miniangle 0
#define maxangle 180
#define minicount 250 
#define maxcount 500 

void servomotor(s32 angle) ;



#endif /* SERVOMOTOR_H_ */