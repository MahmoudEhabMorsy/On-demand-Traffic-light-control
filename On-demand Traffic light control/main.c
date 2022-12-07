/*
 * On-demand Traffic light control.c
 *
 * Created: 05/12/2022 05:45:18 PM
 * Author : MR.MAHMOUD
 */ 

#include "Application/app.h"


int main(void)
{
 APP_init();
    while (1) 
    {
		APP_start();
    }
}






/*
void DIO_test(void){
	DIO_setupPinDirection(PORTC_ID,PIN0_ID,PIN_OUTPUT);
	DIO_setupPinDirection(PORTC_ID,PIN1_ID,PIN_INPUT);
	DIO_setupPinDirection(PORTC_ID,PIN2_ID,PIN_OUTPUT);
	DIO_writePin(PORTC_ID,PIN0_ID,LOGIC_HIGH);
	if(DIO_readPin(PORTC_ID,PIN1_ID)){
		DIO_writePin(PORTC_ID,PIN2_ID,LOGIC_HIGH);
	}
	
}
void LED_test(void){
	LED_init(PORTC_ID,PIN0_ID);
	LED_init(PORTC_ID,PIN2_ID);
	LED_on(PORTC_ID,PIN0_ID);
	LED_off(PORTC_ID,PIN2_ID);
	_delay_ms(1000);
	LED_on(PORTC_ID,PIN2_ID);
	LED_off(PORTC_ID,PIN0_ID);
	_delay_ms(1000);
}
void BUTTON_test(void){
		LED_init(PORTC_ID,PIN2_ID);
		BUTTON_init(PORTC_ID,PIN1_ID);
		if(!BUTTON_read(PORTC_ID,PIN1_ID)){
			LED_on(PORTC_ID,PIN2_ID);
			
		}

}
void TIMER_test(void){
		LED_init(PORTC_ID,PIN0_ID);
		LED_init(PORTC_ID,PIN2_ID);
		LED_on(PORTC_ID,PIN0_ID);
		LED_off(PORTC_ID,PIN2_ID);
		wait(1000);
		LED_on(PORTC_ID,PIN2_ID);
		LED_off(PORTC_ID,PIN0_ID);
		wait(1000);
}*/
/*for testing*/
/*int main(void){
	APP_init();
	while(1){
		//DIO_test();
		//LED_test();
		//BUTTON_test();
		TIMER_test();
	}
}*/