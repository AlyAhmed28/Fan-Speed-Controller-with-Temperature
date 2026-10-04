/*
 * dcmotor.h
 *
 *  Created on: 9 Mar 2024
 *      Author: Lenovo
 */

#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#include"std_types.h"

/************************************************
 * 					Definitions
 ************************************************/

#define DCMOTOR_PORT_ID						PORTB_ID
#define DCMOTOR_PIN1_ID						PIN1_ID
#define DCMOTOR_PIN2_ID						PIN2_ID


typedef enum
{
	CW,A_CW,STOP
}DCMotor_State;


/************************************************
 * 				Functions Prototype
 ************************************************/


void DCMotor_Init(void);

void DCMotor_Rotate(DCMotor_State state,uint8 speed);
#endif /* DCMOTOR_H_ */
