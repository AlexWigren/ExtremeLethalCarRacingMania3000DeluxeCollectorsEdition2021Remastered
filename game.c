/*
 * This file is responisble for calling all functions necessary for the actual game itself to run.
 * 
 * Created by Alexander Wigren 2021 - 03 - 04
 */

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

void gameState1() {
	int buttonStates = getbtns();
	int switchStates = getsw();
	delay(50);

	// PORTD 567
	// PORTF bit 1
	// if button 1 is pressed
	if (buttonStates & 0x1) {
		movePlayerUp();
	}
	// if button 2 is pressed
	if (buttonStates & 0x2) {
		movePlayerDown();
	}
	// if button 3 is pressed
	if (buttonStates & 0x4) {
		movePlayerLeft();
	}
	// if button 4 is pressed
	if (buttonStates & 0x8) {
		movePlayerRight();
	}
	if (switchStates & 0x1) {
		moveObjectLeft(2);
		moveObjectLeft(3);
	}
	if (switchStates & 0x2) {
		moveObjectRight(2);
		moveObjectRight(3);
	}
	if (switchStates & 0x4) {
		moveObjectUp(2);
		moveObjectUp(3);
	}
	if (switchStates & 0x8) {
		moveObjectDown(2);
		moveObjectDown(3);
	}

	updatePositions();
	collisionCheck();
	drawGameDisplay();
	display_fullscreen (gameDisplay);
}

void gameInit() {
	spawnPlayerCar(10, 25);
	// spawnRock(110, 0, 2);
	spawnOil(70, 0, 3);
	spawnNPC(120, 10, 4, 4);
}

void raceTrack() {
	int buttonStates = getbtns();
	int switchStates = getsw();
	delay(50);

	// PORTD 567
	// PORTF bit 1
	// if button 1 is pressed
	if (buttonStates & 0x1) {
		movePlayerUp();
	}
	// if button 2 is pressed
	if (buttonStates & 0x2) {
		movePlayerDown();
	}
	// if button 3 is pressed
	if (buttonStates & 0x4) {
		movePlayerLeft();
	}
	// if button 4 is pressed
	if (buttonStates & 0x8) {
		movePlayerRight();
	}
	if (switchStates & 0x1) {
		moveObjectLeft(2);
		moveObjectLeft(3);
	}
	if (switchStates & 0x2) {
		moveObjectRight(2);
		moveObjectRight(3);
	}
	if (switchStates & 0x4) {
		moveObjectUp(2);
		moveObjectUp(3);
	}
	if (switchStates & 0x8) {
		moveObjectDown(2);
		moveObjectDown(3);
	}

	updatePositions();
	collisionCheck();
	if (death) {
		nextState = eGameOver;
		checkDeath = 0;
	}
	drawGameDisplay();
	display_fullscreen (gameDisplay);
}
