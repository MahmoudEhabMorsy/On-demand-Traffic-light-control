/*
 * timer1.c
 *
 * Created: 05/12/2022 06:03:34 PM
 *  Author: MR.MAHMOUD
 */
#include "timer1.h"

/*******************************************************************************
 *                                Global Variables                                  *
 *******************************************************************************/

/* Global variable to hold the address of the call back function  */
static volatile void (*g_callBackPtr)(void) = NULL_PTR;
/*******************************************************************************
 *                                ISRs                                  *
 *******************************************************************************/

ISR(TIMER1_COMPA_vect){
	
	if (g_callBackPtr != NULL_PTR) {
		(*g_callBackPtr)();
	}
}


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * initiate Timer1
 * Inputs:a struct containing {mode of the timer, compare value, initial value , prescaler}
 *
 */
EN_timer1Error Timer1_init(const Timer1_ConfigType *Config_Ptr) {
	if ((Config_Ptr->mode) == 0) {
		TCCR1A = (Config_Ptr->mode);
	} else {
		TCCR1B = ((Config_Ptr->mode) << 3);
		OCR1A = Config_Ptr->compare_value;
		TIMSK = (1 << OCIE1A);
	}
	TCCR1B |= (Config_Ptr->prescaler);
	TCNT1 = Config_Ptr->initial_value;
	TIMSK |= (1 << TOIE1);
	return TIMER1_OK;
}

/*
 * Description :
 * de-initiate timer1
 */
EN_timer1Error Timer1_deInit(void) {
	TCCR1A = 0;
	TCCR1B = 0;
	TIMSK = 0;
	return TIMER1_OK;
}

/*
 * Description :
 * a function to store the address of callback function in a pointer
 */
EN_timer1Error Timer1_setCallBack(void (*a_ptr)(void)) {
	g_callBackPtr = a_ptr;
	return TIMER1_OK;
}

