/*
 * LED.h
 *
 * Created: 05/12/2022 06:02:24 PM
 *  Author: MR.MAHMOUD
 */ 


#ifndef LED_H_
#define LED_H_
#include "../../Utilities/std_types.h"
#include "../../MCAL/DIO/DIO.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define CAR_LED_PORT_ID PORTA_ID
#define CAR_GREEN_LED_PIN_ID	PIN0_ID
#define CAR_YELLOW_LED_PIN_ID   PIN1_ID
#define CAR_RED_LED_PIN_ID  PIN2_ID
#define PED_LED_PORT_ID	PORTB_ID
#define PED_GREEN_LED_PIN_ID	PIN0_ID
#define PED_YELLOW_LED_PIN_ID	PIN1_ID
#define PED_RED_LED_PIN_ID	PIN2_ID

typedef enum {
	LED_OK,LED_FAILED
	}EN_ledError;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * initiate LED using dio driver
 * Inputs:port id & pin id
 *
 */
EN_ledError LED_init(uint8 port_id,uint8 pin_id);
/*
 * Description :
 * turn on LED using dio driver
 * Inputs:port id & pin id
 *
 */
EN_ledError LED_on(uint8 port_id,uint8 pin_id);
/*
 * Description :
 * turn off using dio driver
 * Inputs:port id & pin id
 *
 */
EN_ledError LED_off(uint8 port_id,uint8 pin_id);


#endif /* LED_H_ */