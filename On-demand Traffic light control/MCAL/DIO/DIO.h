 /******************************************************************************
 * DIO.h
 *
 * Created: 05/12/2022 06:05:15 PM
 *  Author: MR.MAHMOUD
 *
 *******************************************************************************/

#ifndef DIO_H_
#define DIO_H_

#include "../../Utilities/std_types.h"
#include "../../Utilities/common_macros.h" /* To use the macros like SET_BIT */
#include <avr/io.h> /* To use the IO Ports Registers */

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define NUM_OF_PORTS           4
#define NUM_OF_PINS_PER_PORT   8

#define PORTA_ID               0
#define PORTB_ID               1
#define PORTC_ID               2
#define PORTD_ID               3

#define PIN0_ID                0
#define PIN1_ID                1
#define PIN2_ID                2
#define PIN3_ID                3
#define PIN4_ID                4
#define PIN5_ID                5
#define PIN6_ID                6
#define PIN7_ID                7

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum
{
	PIN_INPUT,PIN_OUTPUT
}DIO_PinDirectionType;
typedef enum {
	DIO_OK,DIO_FAILED
	}EN_dioError;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
EN_dioError DIO_setupPinDirection(uint8 port_num, uint8 pin_num, DIO_PinDirectionType direction);

/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
EN_dioError DIO_writePin(uint8 port_num, uint8 pin_num, uint8 value);

/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
uint8 DIO_readPin(uint8 port_num, uint8 pin_num);

#endif /* GPIO_H_ */
