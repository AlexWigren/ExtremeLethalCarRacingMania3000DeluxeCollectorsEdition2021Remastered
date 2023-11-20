/*
 * This file is responisble for controlling and drawing a car to gameDisplay
 * 
 * Created by Axel Karlsson
 * 2021 - 03 - 02
 */

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

// This function draws a car to the given coordinates. The car starts drawing from the top left most pixel
// Written by Axel Karlsson
void drawCar(int xCord, int yCord, uint8_t *image) {
	set1(xCord, yCord, image);
	set1(xCord, yCord + 1, image);
	set1(xCord, yCord + 2, image);
	set1(xCord + 1, yCord + 1, image);
	set1(xCord + 2, yCord, image);
	set1(xCord + 2, yCord + 1, image);
	set1(xCord + 2, yCord + 2, image);
	set1(xCord + 3, yCord + 1, image);
}
// Spawns the player controlled car to the given coordinates in gameDisplay and changes coordinates accordingly
// Written by Axel Karlsson
void spawnPlayerCar(uint8_t x, uint8_t y) {
	xCords[0] = x;
	yCords[0] = y;
}
// Moves the player controlled car 1 in a given direction and moves it on the display
// Written by Axel Karlsson
void movePlayerUp() {
	if (yCords[0] == 1 || playerDisableControll) {
		return;
	}
	yCords[0]--;
}
void movePlayerDown() {
	if (yCords[0] == 28 || playerDisableControll) {
		return;
	}
	yCords[0]++;
}
void movePlayerLeft() {
	if (xCords[0] == 0 || playerDisableControll) {
		return;
	}
	xCords[0]--;
}
void movePlayerRight() {
	if (xCords[0] == 124 || playerDisableControll) {
		return;
	}
	xCords[0]++;
}
