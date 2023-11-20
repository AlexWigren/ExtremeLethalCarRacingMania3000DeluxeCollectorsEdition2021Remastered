/*
 * This file is responisble for moving the objects on the screen
 * 
 * Created by Axel Karlsson 2021 - 03 - 03
 */

// Vi borde göra så att alla objekt är lika stora, och att de därmed kan använda samma logik för rörelse då de har
// samma begränsingar för hur nära kanten de kan vara

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

// These functions are responisble for moving rock and oil patch objects
// They are 4x4 pixels and has limitations on their movement accordingly
// Written by Axel Karlsson
void moveObjectUp(int index) {
	if (yCords[index] == 1) {
		return;
	}
	yCords[index]--;
}
void moveObjectDown(int index) {
	if (yCords[index] == 27) {
		return;
	}
	yCords[index]++;
}
void moveObjectLeft(int index) {
	if (xCords[index] == 0) {
		return;
	}
	xCords[index]--;
}
void moveObjectRight(int index) {
	if (xCords[index] == 123) {
		return;
	}
	xCords[index]++;
}

// Draws a rock to the given coordinates, the starting point is the top left pixel
// Written by Axel Karlsson
void drawRock(int x, int y, uint8_t *image) {
	// Kanske skriva kod som hanterar fallen då stenen hamnar helt eller delvis utanför skärmen
	set1(x, y, image);
	set1(x + 1, y, image);
	set1(x + 2, y, image);
	set1(x + 3, y, image);

	set1(x, y + 1, image);
	set1(x + 1, y + 1, image);
	set1(x + 2, y + 1, image);
	set1(x + 3, y + 1, image);

	set1(x, y + 2, image);
	set1(x + 1, y + 2, image);
	set1(x + 2, y + 2, image);
	set1(x + 3, y + 2, image);

	set1(x, y + 3, image);
	set1(x + 1, y + 3, image);
	set1(x + 2, y + 3, image);
	set1(x + 3, y + 3, image);
}
// Creates a rock object in objectType at the given index with the given coordinates
// Written by Axel Karlsson
void spawnRock(int x, int y, int index) {
	objectType[index] = 2;
	xCords[index] = x;
	yCords[index] = y;
}

// Draws am oil patch to the given coordinates, the starting point is the top left pixel
// Written by Axel Karlsson
void drawOil(int x, int y, uint8_t *image) {

	set1(x, y, image);
	set1(x + 3, y, image);

	set1(x + 1, y + 1, image);
	set1(x + 2, y + 1, image);

	set1(x + 1, y + 2, image);
	set1(x + 2, y + 2, image);

	set1(x, y + 3, image);
	set1(x + 3, y + 3, image);

}
// Creates an oil patch object in objectType at the given index with the given coordinates
// Written by Axel Karlsson
void spawnOil(int x, int y, int index) {
	objectType[index] = 3;
	xCords[index] = x;
	yCords[index] = y;
}

// The code which controls the movement of npc cars which is located at a given index in objectType[]
// If the car has reached the top or bottom edge of the screen, it will start moving in the opposite direction in the case that
// it is moving up/down. If it is moving sideways it will "bounce" at the edge of the screen at a 90 degree angle
// If the car reaches the left most edge of the screen while moving backwards or the rightmost edge while moving
// forwards it will depspawn. Currently it moves to x = 127 which means that a part of the object is outside of the screen,
// should be handeled by the set1 function. This may cause errors
// Written by Axel Karlsson

// Maybe it's a good idea to write two functions that check if the given coordinate is at the edge of the screen
// It'll probably make the code much more compact.

void moveNPC(int index) {
	switch(behaviour[index]){
		case 0:
				break;
		case 1:
			moveObjectUp(index);
			if (yCords[index] == 1)
				behaviour[index] = 2;
			break;
		case 2:
			moveObjectDown(index);
			if (yCords[index] == 27)
				behaviour[index] = 1;
			break;
		case 3:
			moveObjectRight(index);
			if (xCords[index] == 127)
				objectType[index] = 0;
			break;
		case 4:
			moveObjectLeft(index);
			if (xCords[index] == 0)
				objectType[index] = 0;
			break;
		case 5:
			moveObjectUp(index);
			moveObjectRight(index);
			if (xCords[index] == 127) {
				objectType[index] = 0;
				return;
			}
			if (yCords[index] == 1) {
				behaviour[index] = 7;
			}
			break;
		case 6:
			moveObjectUp(index);
			moveObjectLeft(index);
			if (xCords[index] == 0) {
					objectType[index] = 0;
					return;
			}
			if (yCords[index] == 1) {
				behaviour[index] = 8;
			}
			break;
		case 7:
			moveObjectDown(index);
			moveObjectRight(index);
			if (xCords[index] == 127) {
				objectType[index] = 0;
				return;
			}
			if (yCords[index] == 27) {
				behaviour[index] = 5;
			}
			break;
		case 8:
			moveObjectDown(index);
			moveObjectLeft(index);
			if (xCords[index] == 0) {
				objectType[index] = 0;
				return;
			}
			if (yCords[index] == 27) {
				behaviour[index] = 6;
			}
			break;
		default:
			break;
	}
}
// Creates a npc car object in objectType in the given index with the given coordinates
void spawnNPC(int x, int y, int index, int behave) {
	objectType[index] = 4;
	xCords[index] = x;
	yCords[index] = y;
	behaviour[index] = behave;
}
