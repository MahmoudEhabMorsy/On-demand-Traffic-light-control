/*
 * BUTTON.h
 *
 * Created: 05/12/2022 06:02:52 PM
 *  Author: MR.MAHMOUD
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
#include "../../Utilities/std_types.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../Utilities/registers.h"
#include "../../MCAL/INTERRUPTS/interrupts.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define BUTTON_PORT_ID PORTD_ID
#define BUTTON_PIN_ID  PIN2_ID
#define BUTTON_PRESSED 0
#define BUTTON_RELEASED 1

typedef enum {
	BUTTON_OK,BUTTON_FAILED
	}EN_buttonError;
/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
/*
 * Description :
 * initiate BUTTON using dio driver and activating the pull up resistor
 * Inputs:port id & pin id
 **/
EN_buttonError BUTTON_init(uint8 port_id,uint8 pin_id);
/*
 * Description :
 * a function to store the address of callback function in a pointer
 */
EN_buttonError BUTTON_setCallBack(void (*a_ptr)(void));
/*
 * Description :
 * read BUTTON using dio driver and return the button value
 * Inputs:port id & pin id
 *
 */
uint8 BUTTON_read(uint8 port_id,uint8 pin_id);





#endif /* BUTTON_H_ */
