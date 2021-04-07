/*	Author: svo021
 *  Partner(s) Name: Scott Vo
 *	Lab Section:021
 *	Assignment: Lab #2  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF; // Configure 8 pins of A into inputs
	DDRB = 0xFF; PORTB = 0x00; // Configure 8 pins of B into outputs, initialize to 0s
    /* Insert your solution below */
	unsigned char temp = 0;
	unsigned char tempA = 0x00;
	unsigned char i = 0;

    while (1) {
	// read input
	// Computation: count number of 0 bits in A3:A0
	tempA = PINA;
	temp = 0;
	for (i = 0; i < 4; ++i) {
	    if ((tempA & 0x01) == 0x00){
		temp = temp + 1;
	    } 
	    tempA = tempA >> 1;
        }
	
	PORTC = temp;
    }
    return 0;
}
