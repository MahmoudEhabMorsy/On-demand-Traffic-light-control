/*
 * interrupts.c
 *
 * Created: 11/12/2022 07:15:17 PM
 *  Author: MR.MAHMOUD
 */ 
#include "interrupts.h"
/*function to enable interrupts*/
void interrupt_init(void){
				GICR|=(1<<6);/*enabling external interrupts*/
				SREG|=(1<<7);/*enabling global interrupts*/
}