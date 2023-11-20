/*
 * This file contains functions which write 1 or 0 to a specified coordinate on a given image
 * 
 * Written by Axel Karlsson 2021 - 03 - 02
 */

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

void set1 (uint8_t x, uint8_t y, uint8_t *image) {
	// Kollar vilken page och justerar x-kordinaten för att välja byte, sedan byter den ut läplig bit i det byte
	if (y < 7) {
		image[x] |= (1 << y);
	} else if (y < 15) {
		x += 128;
		y -= 8;
		image[x] |= (1 << y);
	} else if (y < 24	) {
		x += 256;
		y -= 16;
		image[x] |= (1 << y);
	} else {
		x += 384;
		y -= 24;
		image[x] |= (1 << y);
	}
}

void set0 (int x, int y, uint8_t *image) {
	// Kollar vilken page och justerar x-kordinaten för att välja byte, sedan byter den ut lämplig bit i det byte
	if (y < 7) {
		image[x] &= ~(1 << y);
	} else if (y < 15) {
		x += 128;
		y -= 8;
		image[x] &= ~(1 << y);
	} else if (y < 24) {
		x += 256;
		y -= 16;
		image[x] &= ~(1 << y);
	} else {
		x += 384;
		y -= 24;
		image[x] &= ~(1 << y);
	}
}