/*
 * registers.h
 *
 * Created: 06/12/2022 07:02:57 PM
 *  Author: MR.MAHMOUD
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_
#include "std_types.h"


//PINS
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7


//****************************
//* DIO REGISTERS
//****************************
//PortA registers
#define PORTA (*(volatile uint8*)(0x3B))
#define DDRA (*(volatile uint8*)(0x3A))
#define PINA (*(volatile uint8*)(0x39))

//PortB registers
#define PORTB (*(volatile uint8*)(0x38))
#define DDRB (*(volatile uint8*)(0x37))
#define PINB (*(volatile uint8*)(0x36))

//PortC registers
#define PORTC (*(volatile uint8*)(0x35))
#define DDRC (*(volatile uint8*)(0x34))
#define PINC (*(volatile uint8*)(0x33))

//PortD registers
#define PORTD (*(volatile uint8*)(0x32))
#define DDRD (*(volatile uint8*)(0x31))
#define PIND (*(volatile uint8*)(0x30))

//****************************
//* Timer1 REGISTERS
//****************************
#define TCCR1A (*(volatile uint8*)(0x4F))
#define TCCR1B (*(volatile uint8*)(0x4E))
#define OCR1A (*(volatile uint16*)(0x4B))
#define OCR1AL  (*(volatile uint8*)(0x4B))
#define OCR1AH  (*(volatile uint8*)(0x4A))
#define TCNT1 (*(volatile uint16*)(0x4D))
#define TCNT1L  (*(volatile uint8*)(0x4D))
#define TCNT1H  (*(volatile uint8*)(0x4C))
#define TIMSK (*(volatile uint8*)(0x59))
#define TOIE1				2
#define OCIE1A				4


//****************************
//* Interrupt REGISTERS
//****************************
#define SREG (*(volatile uint8*)(0x5F))
#define GICR (*(volatile uint8*)(0x5B))
#define MCUCR (*(volatile uint8*)(0x55))

#endif /* REGISTERS_H_ */