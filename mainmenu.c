/*
 * This file is responisble for handling the functions of the main menu and to switch gamemode.
 *
 * Created by Alexander Wigren 2021 - 03 - 04
 */

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

int difficultysetting = 1;

void mainMenu() {
	int buttonStates = getbtns();

	display_string(0, "Button 1: Play");
	display_string(1, "Button 2: Diffuculty");

    // displays the chosen difficulty
    switch(difficultysetting)
    case 1:
        display_string(2, "Slow and steady");
        break;
    case 2:
        display_string(2, "Speedy Gonzales");
        break;
    case 3:
        display_string(2, "Extreme Racer");
        break;
	display_update();

	// switches between difficulty settings if button 2 is pressed.
	if(buttonStates & 0x2){
        switch(difficultysetting)
        case 1:
            difficultysetting = 2;
            break;
        case 2:
            difficultysetting = 3;
            break;
        case 3:
            difficultysetting = 1;
            break;
	}

	if (buttonStates & 0x1) {
		nextState = eRaceTrack;
	}
}
