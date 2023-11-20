/* mipslabwork.c

 This file written 2015 by F Lundevall
 Updated 2017-04-21 by F Lundevall

 This file should be changed by YOU! So you must
 add comment(s) here with your name(s) and date(s):

 This file modified 2017-04-31 by Ture Teknolog

 For copyright and licensing, see file COPYING */

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

int mytime = 0x5957;
int timeoutcount = 0;
int prime = 1234567;

char textstring[] = "text, more text, and even more text!";

/* Interrupt Service Routine - By Axek */
void user_isr(void) {
	if (IFS(0) & 0x100) {		// Checks if the interrupt for timer2 is 1
		timeoutcount++;
		if (timeoutcount == 10) {
			time2string(textstring, mytime);
			display_string(3, textstring);
			display_update();
			tick(&mytime);
			timeoutcount = 0;
		}
		IFS(0) &= ~0x100;		// Resets the interrupt flag for timer2
	}
}

/* Lab-specific initialization goes here */
void labinit(void)
    // Enable PushBTN1 as input. -by Wig
	TRISFSET = 1;
	// Set PushBTN2,3,4 and the Switches 1,2,3,4 as inputs. -by Wig
	TRISDSET = (0x7f << 5);

	//placeholder timer
        // Initialize 16 bit timer
        // Clears the timers we are using
        T2CON = 0X0;
        // The settings for the timer
        T2CONSET = 0X00000070;		// (0b 0000 0000 0000 0000 0000 0000 0111 0000);
        // Sets the timer to 0
        TMR2 = 0X0;
        // Sets the period
        PR2 = 31250;
        // Starts the timer
        T2CONSET = 0X00008000;		// (0b 0000 0000 0000 0000 1000 0000 0000 0000);

        IEC(0) |= 0x100;				// enables interupts for timer 2 0b0000 0000 0000 0000 0000 0001 0000 0000
        IPC(2) |= 0x1F;					// sets priority to 7 and subpriority to 3 (Are these the right bits? Check family reference manual page 10)
        enable_interrupt();				// Enables global interupts
}

/* This function is called repetitively from the main program */
void labwork(void) {
	prime = nextprime(prime);
	display_string(0, itoaconv(prime));
	display_update();
}
