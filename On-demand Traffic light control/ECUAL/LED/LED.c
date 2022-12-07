/*
 * LED.c
 *
 * Created: 05/12/2022 06:02:11 PM
 *  Author: MR.MAHMOUD
 */ 
#include "LED.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * initiate LED using dio driver
 * Inputs:port id & pin id
 *
 */
EN_ledError LED_init(uint8 port_id,uint8 pin_id){
	DIO_setupPinDirection(port_id,pin_id,PIN_OUTPUT);
	return LED_OK;
}
/*
 * Description :
 * turn on LED using dio driver
 * Inputs:port id & pin id
 *
 */
EN_ledError LED_on(uint8 port_id,uint8 pin_id){
	DIO_writePin(port_id,pin_id,LOGIC_HIGH);
	return LED_OK;
}
/*
 * Description :
 * turn off using dio driver
 * Inputs:port id & pin id
 *
 */
EN_ledError LED_off(uint8 port_id,uint8 pin_id){
	DIO_writePin(port_id,pin_id,LOGIC_LOW);
	return LED_OK;
}