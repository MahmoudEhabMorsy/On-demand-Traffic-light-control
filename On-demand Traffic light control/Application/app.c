/*
 * app.c
 *
 * Created: 05/12/2022 08:02:53 PM
 *  Author: MR.MAHMOUD
 */ 
#include "app.h"
/*******************************************************************************
 *                                Global Variables                                  *
 *******************************************************************************/
uint8 carled=GREEN;/*variable to indicate the current lighted led*/
uint8 mode=NORMAL;/*variable to indicate the current mode*/
/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
/*
 * Description :
 * initiate application by initiating timer1 and button and leds and enabling interrupts
 *
 */
void APP_init(void){
	
	LED_init(CAR_LED_PORT_ID,CAR_GREEN_LED_PIN_ID);
	LED_init(CAR_LED_PORT_ID,CAR_YELLOW_LED_PIN_ID);
	LED_init(CAR_LED_PORT_ID,CAR_RED_LED_PIN_ID);
	
	LED_init(PED_LED_PORT_ID,PED_GREEN_LED_PIN_ID);
	LED_init(PED_LED_PORT_ID,PED_YELLOW_LED_PIN_ID);
	LED_init(PED_LED_PORT_ID,PED_RED_LED_PIN_ID);
	
	BUTTON_init(BUTTON_PORT_ID,BUTTON_PIN_ID);
	BUTTON_setCallBack(BUTTON_pressed);/*getting the address of the callback function*/
	wait_init();		
}


/*
 * Description :
 * start application
 *
 */
void APP_start(void){
	uint8 i;/*variable for for loops*/
	mode=NORMAL;
	/*while loop for the normal mode of the traffic light
	it switch lights colors every 5 seconds and blink yellow light for 5 seconds
	*/
while(mode==NORMAL){
			LED_on(CAR_LED_PORT_ID,CAR_GREEN_LED_PIN_ID);
			LED_on(PED_LED_PORT_ID,PED_RED_LED_PIN_ID);
			carled=GREEN;
			wait(5000);
			LED_off(CAR_LED_PORT_ID,CAR_GREEN_LED_PIN_ID);
			if(mode==PEDSTARIAN){
				break;
			}
			carled=YELLOW;
			
			for(i=0;i<5;i++){
				LED_on(CAR_LED_PORT_ID,CAR_YELLOW_LED_PIN_ID);
				wait(250);
				LED_off(CAR_LED_PORT_ID,CAR_YELLOW_LED_PIN_ID);
				if(mode==PEDSTARIAN){
					break;
				}
				wait(250);
				if(mode==PEDSTARIAN){
					break;
				}
				LED_on(CAR_LED_PORT_ID,CAR_YELLOW_LED_PIN_ID);
				wait(250);
				LED_off(CAR_LED_PORT_ID,CAR_YELLOW_LED_PIN_ID);
				if(mode==PEDSTARIAN){
					break;
				}
				wait(250);
				if(mode==PEDSTARIAN){
					break;
				}
			}
			if(mode==PEDSTARIAN){
				break;
			}
			LED_off(PED_LED_PORT_ID,PED_RED_LED_PIN_ID);
			LED_on(CAR_LED_PORT_ID,CAR_RED_LED_PIN_ID);
			LED_on(PED_LED_PORT_ID,PED_GREEN_LED_PIN_ID);
			carled=RED;
			wait(5000);
			LED_off(CAR_LED_PORT_ID,CAR_RED_LED_PIN_ID);
			LED_off(PED_LED_PORT_ID,PED_GREEN_LED_PIN_ID);
			if(mode==PEDSTARIAN){
				break;
			}
			carled=YELLOW;
			LED_on(PED_LED_PORT_ID,PED_RED_LED_PIN_ID);
			for(i=0;i<5;i++){
				LED_on(CAR_LED_PORT_ID,CAR_YELLOW_LED_PIN_ID);
				wait(250);
				LED_off(CAR_LED_PORT_ID,CAR_YELLOW_LED_PIN_ID);
				if(mode==PEDSTARIAN){
					break;
				}
				wait(250);
				if(mode==PEDSTARIAN){
					break;
				}
				LED_on(CAR_LED_PORT_ID,CAR_YELLOW_LED_PIN_ID);
				wait(250);
				LED_off(CAR_LED_PORT_ID,CAR_YELLOW_LED_PIN_ID);
				if(mode==PEDSTARIAN){
					break;
				}
				wait(250);
				if(mode==PEDSTARIAN){
					break;
				}
			}
			if(mode==PEDSTARIAN){
				break;
			}
}
/*activated when the button is pressed to manipulate lights for the pedestrian to walk safely
consists of a switch case that choses the case based on the variable (carled) and handling each case as described in the rubric*/
	switch (carled)
	{
		case RED:
		mode=NORMAL;
		break;
		case YELLOW:
		LED_off(PED_LED_PORT_ID,PED_RED_LED_PIN_ID);
		for(i=0;i<5;i++){
			LED_on(CAR_LED_PORT_ID,CAR_YELLOW_LED_PIN_ID);
			LED_on(PED_LED_PORT_ID,PED_YELLOW_LED_PIN_ID);
			wait(250);
			LED_off(CAR_LED_PORT_ID,CAR_YELLOW_LED_PIN_ID);
			LED_off(PED_LED_PORT_ID,PED_YELLOW_LED_PIN_ID);
			wait(250);
			LED_on(CAR_LED_PORT_ID,CAR_YELLOW_LED_PIN_ID);
			LED_on(PED_LED_PORT_ID,PED_YELLOW_LED_PIN_ID);
			wait(250);
			LED_off(CAR_LED_PORT_ID,CAR_YELLOW_LED_PIN_ID);
			LED_off(PED_LED_PORT_ID,PED_YELLOW_LED_PIN_ID);
			wait(250);
		}
		LED_on(CAR_LED_PORT_ID,CAR_RED_LED_PIN_ID);
		LED_on(PED_LED_PORT_ID,PED_GREEN_LED_PIN_ID);
		carled=RED;
		wait(5000);
		LED_off(CAR_LED_PORT_ID,CAR_RED_LED_PIN_ID);
		LED_off(PED_LED_PORT_ID,PED_GREEN_LED_PIN_ID);
		LED_on(PED_LED_PORT_ID,PED_RED_LED_PIN_ID);
				for(i=0;i<5;i++){
					LED_on(CAR_LED_PORT_ID,CAR_YELLOW_LED_PIN_ID);
					wait(250);
					LED_off(CAR_LED_PORT_ID,CAR_YELLOW_LED_PIN_ID);
					wait(250);
					LED_on(CAR_LED_PORT_ID,CAR_YELLOW_LED_PIN_ID);
					wait(250);
					LED_off(CAR_LED_PORT_ID,CAR_YELLOW_LED_PIN_ID);
					wait(250);
				}
		mode=NORMAL;
		break;
		case GREEN:
		LED_off(PED_LED_PORT_ID,PED_RED_LED_PIN_ID);
		for(i=0;i<5;i++){
			LED_on(CAR_LED_PORT_ID,CAR_YELLOW_LED_PIN_ID);
			LED_on(PED_LED_PORT_ID,PED_YELLOW_LED_PIN_ID);
			wait(250);
			LED_off(CAR_LED_PORT_ID,CAR_YELLOW_LED_PIN_ID);
			LED_off(PED_LED_PORT_ID,PED_YELLOW_LED_PIN_ID);
			wait(250);
			LED_on(CAR_LED_PORT_ID,CAR_YELLOW_LED_PIN_ID);
			LED_on(PED_LED_PORT_ID,PED_YELLOW_LED_PIN_ID);
			wait(250);
			LED_off(CAR_LED_PORT_ID,CAR_YELLOW_LED_PIN_ID);
			LED_off(PED_LED_PORT_ID,PED_YELLOW_LED_PIN_ID);
			wait(250);
		}
		LED_on(CAR_LED_PORT_ID,CAR_RED_LED_PIN_ID);
		LED_on(PED_LED_PORT_ID,PED_GREEN_LED_PIN_ID);
		carled=RED;
		wait(5000);
		LED_off(CAR_LED_PORT_ID,CAR_RED_LED_PIN_ID);
		LED_off(PED_LED_PORT_ID,PED_GREEN_LED_PIN_ID);
		LED_on(PED_LED_PORT_ID,PED_RED_LED_PIN_ID);
				for(i=0;i<5;i++){
					LED_on(CAR_LED_PORT_ID,CAR_YELLOW_LED_PIN_ID);
					wait(250);
					LED_off(CAR_LED_PORT_ID,CAR_YELLOW_LED_PIN_ID);
					wait(250);
					LED_on(CAR_LED_PORT_ID,CAR_YELLOW_LED_PIN_ID);
					wait(250);
					LED_off(CAR_LED_PORT_ID,CAR_YELLOW_LED_PIN_ID);
					wait(250);
				}
		mode=NORMAL;
		break;
	}
}

/*call back function for the external interrupt (button) changes the mode of operation to pedestrian and eliminate any wait loops by the timer*/
void BUTTON_pressed(void){
	unsigned char flag = 0;    // button flag
	if(!BUTTON_read(BUTTON_PORT_ID,BUTTON_PIN_ID)) /*check if the button is pressed or not*/
	{
		_delay_ms(250);
		if(BUTTON_read(BUTTON_PORT_ID,BUTTON_PIN_ID)) /*second check if the button is released or still pressed to handle the long press case where if it is still pressed the if condition wont be satisfied and nothing will happen*/
		{
			if(flag == 0)
			{

				if(carled!=RED){
					mode=PEDSTARIAN;
					g_msecond=5000;/*to break any wait loops*/
				}
				//set the button flag value to 1 to not enter here again until the button is released.
				flag = 1;
			}
		}
	}
	else
	{
		// button is released reset the button flag to value 0 again.
		flag = 0;
	}
}


