/*
 * This file is responisble for updating the positional data of objects in game memory.
 * 
 * Created by Alexander Wigren 2021 - 03 - 04
 */

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

// iterates through the objectType array and determines if objects are to be moved or killed and prepared
// for a new spawn cycle.
void updatePositions() {
	int i = 0;
	for (i = 0; i < MAXOBJECTS; i++) {
		switch (objectType[i]) {
		case 2:
			if (xCords[i] == 0) {
				objectType[i] = 0;
				return;
			}
			moveObjectLeft(i);
			break;
		case 3:
			if (xCords[i] == 0) {
				objectType[i] = 0;
				return;
			}
			moveObjectLeft(i);
			break;
		case 4:
			moveNPC(i);
			break;
		default:
			break;
		}
	}
}