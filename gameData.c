/*
 * This file stores the objects that are displayed on the screen
 * 
 * Created by Axel Karlsson
 * 2021 - 03 - 02
 * 
 */

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */	



/* The type of objects displayed are stored here
 * 0 represents null (no object in this index)
 * 1 represents the player controlled car
 * 2 represents a rock
 * 3 represents an oil patch
 * 4 represents a computer controlled car
 * 
 * Index 0 is always the player controlled car
 */ 
uint8_t objectType[MAXOBJECTS] = {1, 0, 0, 0, 0, 0, 0, 0};

/*
 * The positions of the objects are stored here. Each index is connected to an index
 * in objectType. For example, indexes 0 store the player controlled cars coordinates and
 * index 1 stores the coordinates of whatever object is stored in index 1 in objectType.
 */
uint8_t xCords[MAXOBJECTS];
uint8_t yCords[MAXOBJECTS];

/* Stores behaviours of computer controlled cars
 * Behaviours:
 * Which direction should it move next time? (Up, down, left, right or a combination of 2)
 *
 * 		0 = don't move
 * 		1 = move up
 * 		2 = move down
 * 		3 = move right
 * 		4 = move left
 * 		5 = move up + right
 * 		6 = move up + left
 * 		7 = move down + right
 * 		8 = move down + left
 */

uint8_t behaviour[MAXOBJECTS];





