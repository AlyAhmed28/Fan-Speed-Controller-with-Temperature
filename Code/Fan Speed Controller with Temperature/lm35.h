/*
 * lm35.h
 *
 *  Created on: 26 Jan 2024
 *      Author: Lenovo
 */

#ifndef LM35_H_
#define LM35_H_

#include"std_types.h"


/****************************************************
 * 					Definitions
 ****************************************************/

#define SENSOR_CHANNEL_ID				2
#define SENSOR_MAX_VOLT_VALUE			1.5
#define SENSOR_MAX_TEMP_VALUE			150


/*******************************************************
 * 					Functions Prototypes
 ******************************************************/


uint8 LM35_getTemperature(void);


#endif /* LM35_H_ */
