/*
 * LED.c
 *
 * Created: 05/12/2022 06:02:11 PM
 *  Author: MR.MAHMOUD
 */ 
#include "LED.h"

/*******************************************************************************
 *                                Global Variables                                  *
 *******************************************************************************/
uint16 g_msecond = 0;/*variable for storing mili seconds*/

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
/*function to delay time using timer1*/
void wait(uint16 time) {
	g_msecond = 0;
	
	while (g_msecond < time)
	;
}
/*call back function to calculate time in mili seconds on every interrupt by timer1*/
void msecondPassed(void) {
	g_msecond++;
}
/*function to initialize wait function and timer*/
void wait_init(void){
	Timer1_init();
	Timer1_setCallBack(msecondPassed);/*getting the address of the callback function*/
	interrupt_init();
}
