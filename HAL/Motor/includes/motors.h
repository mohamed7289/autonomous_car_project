/*
* motors.h
*
* Created: 7/24/2023 11:29:21 AM
*  Author: mohamed adel
*/


#ifndef MOTORS_H_
#define MOTORS_H_

#include "DIO.h"
#include "Clock.h"
#include "LCD.h"


void Left_Front_Wheel_Forward(void) ;
void Right_Front_Wheel_Forward(void) ;
void Left_Back_Wheel_Forward(void) ;
void Right_Back_Wheel_Forward(void) ;


void Left_Front_Wheel_Backward(void) ;
void Right_Front_Wheel_Backward(void) ;
void Left_Back_Wheel_Backward(void) ;
void Right_Back_Wheel_Backward(void) ;


void MOVE_Forward(void) ;
void MOVE_Right(void) ;
void MOVE_Left(void) ;
void MOVE_Backward(void) ;
void Stop(void) ;




#endif /* MOTORS_H_ */