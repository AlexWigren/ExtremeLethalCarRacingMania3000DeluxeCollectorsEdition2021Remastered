/*
 * This file is responisble for checking if objects collide with the player controlled car.
 * 
 * Created by Alexander Wigren 2021 - 03 - 04
 */

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */



// compares hitbox of the player car to the corners of rocks and oil patches. If they do, then do something.
int collisionRockOil(int index) {
	int j;
	int k;
	for (j = 0; j < 2; j++) {
		if (xCords[0] + j * 2 == xCords[index]
				|| xCords[0] + j * 2 == xCords[index] + 3) {
			for (k = 0; k < 3; k++) {
				if (yCords[0] + k == yCords[index]
						|| yCords[0] + k == yCords[index] + 3) {
					return 1;
				}

			}
		}
	}
	return 0;
}

// This function disables player control of the car when you hit an oil patch
// This should probably be controlled with interrupts, so that the game can keep going while you are out of controll
void collisionWithOil() {
	playerDisableControll = 30;
}



int collisionNPC(int index){
	int j;
		int k;
		for (j = 0; j < 2; j++) {
			if (xCords[0] + j * 2 == xCords[index]
					|| xCords[0] + j * 2 == xCords[index] + 2) {
				for (k = 0; k < 3; k++) {
					if (yCords[0] + k == yCords[index]
							|| yCords[0] + k == yCords[index] + 2) {
						return 1;
					}

				}
			}
		}
		return 0;
}

void collisionCheck() {
	int i;
	for (i = 1; i < MAXOBJECTS; i++) {
		switch (objectType[i]) {
		case 2:
			if(collisionRockOil(i))
				// gamestate = 2;
				checkDeath = 1;
			break;
		case 3:
			if(collisionRockOil(i))
				collisionWithOil();
			break;
		case 4:
			if(collisionNPC(i))
				// gamestate = 2;
				checkDeath = 1;
			break;
		default:
			break;
		}
	}
}
