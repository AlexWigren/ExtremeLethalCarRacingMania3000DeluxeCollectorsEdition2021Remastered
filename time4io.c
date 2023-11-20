/*
 * time4io.c
 *
 *  Created on: 22 feb. 2021
 *  This code was written together for the lab
 */


#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"

// return the states of switch 1 - 4, switch 1 is lsb. All other bits should be 0.
int getsw(void) {
	return (PORTD >> 8) & 0xf;
}

// return the states of buttons 4 - 2, button 2 is lsb. All other bits should be 0.
// Could be optimized, it works so we left it as is
int getbtns(void) {
	// Buttons 2 - 4
	int sendBtns = 0;
	sendBtns = (PORTD >> 4) & 0xE;
	sendBtns |= (PORTF >> 1) & 0x1;
	return sendBtns;
}

