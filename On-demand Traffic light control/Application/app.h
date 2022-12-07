/*
 * app.h
 *
 * Created: 05/12/2022 08:03:01 PM
 *  Author: MR.MAHMOUD
 */ 


#ifndef APP_H_
#define APP_H_
#include "../ECUAL/BUTTON/BUTTON.h"
#include "../ECUAL/LED/LED.h"
#include "../ECUAL/TIMER/timer1.h"
#include "../Utilities/registers.h"
#include <avr/interrupt.h>
#include <util/delay.h>

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum{
	GREEN,YELLOW,RED
	}LED_COLOR;
typedef enum{
	PEDSTARIAN,NORMAL
	}LED_MODE;
	/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
	/*
 * Description :
 * initiate application by initiating timer1 and button and leds and enabling interrupts
 *
 */
void APP_init(void);
/*
 * Description :
 * start application
 *
 */
void APP_start(void);
/*call back function to calculate time in mili seconds on every interrupt by timer1*/
void msecondPassed(void) ;
/*function to delay time using timer1*/
void wait(uint16 time);
/*call back function for the external interrupt (button) changes the mode of operation to pedestrian and eliminate any wait loops by the timer*/
void BUTTON_pressed(void);

#endif /* APP_H_ */
