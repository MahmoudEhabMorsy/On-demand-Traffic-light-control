/*
 * BUTTON.c
 *
 * Created: 05/12/2022 06:02:38 PM
 *  Author: MR.MAHMOUD
 */ 
#include "BUTTON.H"
/*******************************************************************************
 *                                Global Variables                                  *
 *******************************************************************************/
/* Global variable to hold the address of the call back function  */
static volatile void (*g_callBackPtr)(void) = NULL_PTR;
/*******************************************************************************
 *                                ISRs                                  *
 *******************************************************************************/

ISR(INT0_vect){
		if (g_callBackPtr != NULL_PTR) {
			(*g_callBackPtr)();
		}
}
/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*button connected to INT0 (PD2)*/
/*
 * Description :
 * initiate BUTTON using dio driver and activating the pull up resistor
 * Inputs:port id & pin id
 *
 */
EN_buttonError BUTTON_init(uint8 port_id,uint8 pin_id){
	MCUCR=0x02;/*interrupt work with falling edge*/
	DIO_setupPinDirection(port_id,pin_id,PIN_INPUT);
	DIO_writePin(port_id,pin_id,LOGIC_HIGH);/*activating internal pull up resistor*/
	return BUTTON_OK;
}
/*
 * Description :
 * read BUTTON using dio driver and return the button value
 * Inputs:port id & pin id
 *
 */
uint8 BUTTON_read(uint8 port_id,uint8 pin_id){

	return (DIO_readPin(port_id,pin_id));
	
}
/*
 * Description :
 * a function to store the address of callback function in a pointer
 */
EN_buttonError BUTTON_setCallBack(void (*a_ptr)(void)) {
	g_callBackPtr = a_ptr;
	return BUTTON_OK;
}
