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

ISR(TIMER1_OCA_vect){
	
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
 *
 */
EN_timer1Error Timer1_init(void) {
		TCCR1B = (COMPARE_OCR << 3);
		OCR1A = TIMER1_OCRA_VALUE;
		TIMSK = (1 << OCIE1A);
	
	TCCR1B |= F_CPU_CLOCK;
	TCNT1 = TIMER1_INITIAL_VALUE;
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

