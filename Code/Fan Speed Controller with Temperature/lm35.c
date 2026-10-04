/*
 * lm35.c
 *
 *  Created on: 26 Jan 2024
 *      Author: Lenovo
 */



#include"lm35.h"
#include"adc.h"



/*******************************************************
 * 					Functions Definitions
 ******************************************************/

uint8 LM35_getTemperature(void)
{

	uint16 adc_value=0;
	uint8 temp_value=0;

	adc_value = ADC_readChannel(SENSOR_CHANNEL_ID);

	temp_value = (uint8)(((uint32)adc_value*ADC_REF_VOLT_VALUE*SENSOR_MAX_TEMP_VALUE)/(SENSOR_MAX_VOLT_VALUE*ADC_MAXIMUM_VALUE));

	return temp_value;
}
