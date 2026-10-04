/*
 * pwm.c
 *
 *  Created on: 9 Mar 2024
 *      Author: Lenovo
 */

#include"pwm.h"
#include"gpio.h"
#include<avr/io.h>


/*
 * The function responsible for trigger the Timer0 with the PWM Mode.
* Setup the PWM mode with Non-Inverting.
* Setup the prescaler with F_CPU/8.
* Setup the compare value based on the required input duty cycle
* Setup the direction for OC0 as output pin through the GPIO driver.
* The generated PWM signal frequency will be 500Hz to control the DC Motor speed.

 *duty_cycle: The required duty cycle percentage of the generated PWM signal.
 */

void PWM_Timer0_Start(uint8 duty_cycle)
{

	TCNT0 = 0;

	OCR0 = duty_cycle;

	GPIO_setupPinDirection(PORTB_ID, PIN3_ID, PIN_OUTPUT);

	TCCR0 = (1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS01);

}
