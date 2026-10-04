/*
 * dcmotor.c
 *
 *  Created on: 9 Mar 2024
 *      Author: Lenovo
 */

#include"dcmotor.h"
#include"pwm.h"
#include"gpio.h"


void DCMotor_Init(void)
{

	GPIO_setupPinDirection(DCMOTOR_PORT_ID, DCMOTOR_PIN1_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(DCMOTOR_PORT_ID, DCMOTOR_PIN2_ID, PIN_OUTPUT);
}


void DCMotor_Rotate(DCMotor_State state,uint8 speed)
{

	uint8 duty;

	duty = (speed*255)/100;

	switch(state)
	{
	case(CW):
			PWM_Timer0_Start(duty);
			GPIO_writePin(DCMOTOR_PORT_ID, DCMOTOR_PIN1_ID, LOGIC_HIGH);
			GPIO_writePin(DCMOTOR_PORT_ID, DCMOTOR_PIN2_ID, LOGIC_LOW);
			break;

	case(A_CW):
			PWM_Timer0_Start(duty);
			GPIO_writePin(DCMOTOR_PORT_ID, DCMOTOR_PIN1_ID, LOGIC_LOW);
			GPIO_writePin(DCMOTOR_PORT_ID, DCMOTOR_PIN2_ID, LOGIC_HIGH);
			break;

	case(STOP):
			PWM_Timer0_Start(0);
			GPIO_writePin(DCMOTOR_PORT_ID, DCMOTOR_PIN1_ID, LOGIC_LOW);
			GPIO_writePin(DCMOTOR_PORT_ID, DCMOTOR_PIN2_ID, LOGIC_LOW);
			break;

	default:
			break;

	}

}
