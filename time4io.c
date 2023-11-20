/*
 * time4io.c
 *
 *  Created on: 22 feb. 2021
 *      Author: Axel
 */


#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"

// return the states of switch 1 - 4, switch 1 is lsb. All other bits should be 0.
int getsw(void) {
	return (PORTD >> 8) & 0xf;
}

// return the states of buttons 4 - 2, button 2 is lsb. All other bits should be 0.
int getbtns(void) {
	return (PORTD >> 5) & 0x7;
}

