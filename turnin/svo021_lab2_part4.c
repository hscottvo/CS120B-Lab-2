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
	DDRB = 0x00; PORTB = 0xFF; // Configure 8 pins of B into inputs
	DDRC = 0x00; PORTB = 0xFF; // Configure 8 pins of C into inputs
	DDRD = 0xFF; PORTB = 0x00; // Configure 8 pins of D into outputs
    /* Insert your solution below */
	unsigned char p0 = 0x00;
	unsigned char p1 = 0x00;
	unsigned char tempA = 0x00;
	unsigned char tempB = 0x00;
	unsigned char tempC = 0x00;
	unsigned short total_weight = 0x00;
	unsigned char temp = 0x00;

    while (1) {
	tempA = PINA;
	tempB = PINB;
	tempC = PINC;
	total_weight = tempA + tempB + tempC;
	if (total_weight > 0x008C) {
	    p0 = 0x01;	
	} else {
	    p0 = 0x00;
	}
	// right-shifts until reduced to less than 0x40
	while(total_weight >= 0x40) {
	    total_weight = total_weight >> 1;
	}
	// shifts left by 2 in preparation for output
	total_weight = (total_weight << 2) & 0xFC; 
	if(tempA > tempC && (tempA - tempC) > 0x50) {
	    p1 = 0x02;
	} else if (tempC > tempA && (tempC - tempA) > 0x50) {
	    p1 = 0x02;
	} else {
	    p1 = 0x00;
	}

	temp = total_weight | p0 | p1;
	PORTD = temp;
    }
    return 0;
}
