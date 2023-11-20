/*
 *  This file contains functions that draw the graphics for the course (i.e. the stripes on the top and bottom)
 *  
 *  Created by Axel Karlsson 2021 - 03 - 04
 * 
 */

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

uint8_t index = 8;
int i;
int j;

// This funcion draws white stripes that are 4 x 1 pixels on the top and bottom most two rows to the given image
// This is probably not the best way to implement this but I can't be arsed
// Written by Axel Karlsson
void drawStripes(uint8_t *image) {
	// Basically a for loop that iterats once each time the function is called
	if (index == 0)
		index = 8;
	// Top row of the screen
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 8; j++) {
			image[index + i + (16 * j)] |= 1;
			image[index + i + (16 * j) + 384] |= 128;
			if (index + i + 8 > 15) {
				image[index + i + (16 * j) - 8] |= 1;
				image[index + i + (16 * j) - 8 + 384] |= 128;
			} else {
				image[index + i + (16 * j) + 8] |= 1;
				image[index + i + (16 * j) + 8 + 384] |= 128;
			}
		}
	}
	index--;
}
