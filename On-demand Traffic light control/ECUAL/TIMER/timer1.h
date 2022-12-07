/*
 * timer1.h
 *
 * Created: 05/12/2022 06:03:24 PM
 *  Author: MR.MAHMOUD
 */

#ifndef TIMER1_H_
#define TIMER1_H_
#include "../../Utilities/std_types.h"
#include "../../Utilities/registers.h"
#include <avr/interrupt.h>
#define TIMER1_INITIAL_VALUE 0
#define TIMER1_OCRA_VALUE 1000

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

typedef enum {
	NORMAL_TIMER, COMPARE_OCR, COMPARE_ICR
} Timer1_Mode;
typedef enum{
	NO_CLOCK,
	F_CPU_CLOCK,
	F_CPU_8,
	F_CPU_64,
	F_CPU_256,
	F_CPU_1024,
	F_TIMER1_EXTERNAL_FALLING,
	F_TIMER1_EXTERNAL_RISING
} Timer1_Prescaler;
typedef struct {
	uint16 initial_value;
	uint16 compare_value; /*used in compare mode only*/
	Timer1_Prescaler prescaler;
	Timer1_Mode mode;
} Timer1_ConfigType;
typedef enum {
	TIMER1_OK,TIMER1_FAILED
	}EN_timer1Error;
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * initiate Timer1
 * Inputs:a struct containing {mode of the timer, compare value, initial value , prescaler}
 *
 */
EN_timer1Error Timer1_init(const Timer1_ConfigType *Config_Ptr);
/*
 * Description :
 * de-initiate timer1
 */
EN_timer1Error Timer1_deInit(void);
/*
 * Description :
 * a function to store the address of callback function in a pointer
 */
EN_timer1Error Timer1_setCallBack(void (*a_ptr)(void));

#endif /* TIMER1_H_ */
