/*
 * interrupts.h
 *
 * Created: 09/12/2022 12:30:27 AM
 *  Author: MR.MAHMOUD
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_


/* External Interrupt Request 0 */
#define INT0_vect			__vector_1




/* Timer/Counter1 Compare Match A */
#define TIMER1_OCA_vect		__vector_7


//ISR macro
#  define ISR(vector,...)            \
void vector (void) __attribute__ ((signal))__VA_ARGS__ ; \
void vector (void)


#endif /* INTERRUPTS_H_ */