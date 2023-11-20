/*
 * This file is responisble for handling the functions of the main menu and to switch gamemode.
 * 
 * Created by Alexander Wigren 2021 - 03 - 04
 */

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

void gameState2(){
	int buttonStates = getbtns();
	display_string(0, "stefan is dead");
	display_update();

	if (buttonStates & 0x1) {
		gamestate = 0;
	}
}

void gameOver() {
	int buttonStates = getbtns();
	display_string(0, "Game over");
	display_string(1, "you survived2")
	display_string(3, "press button 1 to go to main menu");
	display_update();

	if (buttonStates & 0x1) {
		nextState = eMainMenu;
	}
}

