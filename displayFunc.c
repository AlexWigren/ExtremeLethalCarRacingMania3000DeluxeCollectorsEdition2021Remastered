/*
 * This file contains functions which write 1 or 0 to a specified coordinate on a given image
 * 
 * Written by Axel Karlsson 2021 - 03 - 02
 */

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

// Currently only works for 128 x 32 pixel images
// Written by Axel Karlsson
void set1(int x, int y, uint8_t *image) {
	// If the coordinate(s) are not on the screen
	if (x < 0 || x > 127 || y < 0 || y > 31)
		return;
	if (y < 8) {
		image[x] |= (1 << y);
	} else if (y < 16) {
		x += 128;
		y -= 8;
		image[x] |= (1 << y);
	} else if (y < 24) {
		x += 256;
		y -= 16;
		image[x] |= (1 << y);
	} else {
		x += 384;
		y -= 24;
		image[x] |= (1 << y);
	}
}

// Written by Axel Karlsson
void set0(int x, int y, uint8_t *image) {
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
// This function draws all the objects in the objectType array to gameDisplay
// Written by Axel Karlsson
void drawGameDisplay() {
	// Hacky solution, fix this later
	// Clears the array where the image will be written
	// Don't know what a proper solution would look like - this probably works
	int j;
	for (j = 0; j < 512; j++) {
		gameDisplay[j] = 0;
	}
	// Draws the objects which are currently active
	int i;
	for (i = 0; i < MAXOBJECTS; i++) {
		switch (objectType[i]) {
		case 1:
			drawCar(xCords[0], yCords[0], gameDisplay);
			break;
		case 2:
			drawRock(xCords[i], yCords[i], gameDisplay);
			break;
		case 3:
			drawOil(xCords[i], yCords[i], gameDisplay);
			break;
		case 4:
			drawCar(xCords[i], yCords[i], gameDisplay);
			break;
		default:
			break;
		}
	}
	// Draws the sidelines of the track
	drawStripes(gameDisplay);

}
