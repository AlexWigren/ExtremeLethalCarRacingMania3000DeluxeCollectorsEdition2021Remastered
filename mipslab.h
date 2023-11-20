/* mipslab.h
   Header file for all labs.
   This file written 2015 by F Lundevall
   Some parts are original code written by Axel Isaksson

   The parts that were written for our project are marked with comments

   Latest update 2015-08-28 by F Lundevall

   For copyright and licensing, see file COPYING */
/* Declare display-related functions from mipslabfunc.c */
void display_image(int x, const uint8_t *data);
void display_init(void);
void display_string(int line, char *s);
void display_update(void);
uint8_t spi_send_recv(uint8_t data);

/* Declare lab-related functions from mipslabfunc.c */
char * itoaconv( int num );
void labwork(void);
int nextprime( int inval );
void quicksleep(int cyc);
void tick( unsigned int * timep );

// This code represents the game state
// Written by Axel Karlsson
typedef enum {
	eSplashScreen,
	eMainMenu,
	eRaceTrack,
	eGameOver,
} eGameState;

// Our own functions
void set1(int x, int y, uint8_t *image);
void set0(int x, int y, uint8_t *image);
void spawnPlayerCar(uint8_t xCord, uint8_t yCord);
void spawnRock(int x, int y, int index);
void drawRock(int x, int y, uint8_t *image);
void spawnOil(int x, int y, int index);
void drawOil(int x, int y, uint8_t *image);
void display_fullscreen(const uint8_t *data);
void movePlayerUp();
void movePlayerDown();
void movePlayerLeft();
void movePlayerRight();
void moveObjectUp(int index);
void moveObjectDown(int index);
void moveObjectLeft(int index);
void moveObjectRight(int index);
void drawStripes(uint8_t *image);
void updatePositions();
void collisionCheck();
void gameState0();
void gameState1();
void gameState2();
void gameInit();

// Our own variables
extern uint8_t gameDisplay[];
extern uint8_t objectType[];
extern uint8_t xCords[];
extern uint8_t yCords[];
extern uint8_t behaviour[];
extern uint8_t const logo[];
extern int gamestate;
extern int buttonStates;
extern int switchStates;
extern eGameState nextState;
extern int checkDeath;
extern int playerDisableControll;
#define MAXOBJECTS 8
extern int secondsSurvived;



/* Declare display_debug - a function to help debugging.

   After calling display_debug,
   the two middle lines of the display show
   an address and its current contents.

   There's one parameter: the address to read and display.

   Note: When you use this function, you should comment out any
   repeated calls to display_image; display_image overwrites
   about half of the digits shown by display_debug.
*/
void display_debug( volatile int * const addr );

/* Declare bitmap array containing font */
extern const uint8_t const font[128*8];
/* Declare bitmap array containing icon */
extern const uint8_t const icon[128];
/* Declare text buffer for display output */
extern char textbuffer[4][16];

/* Declare functions written by students.
   Note: Since we declare these functions here,
   students must define their functions with the exact types
   specified in the laboratory instructions. */
/* Written as part of asm lab: delay, time2string */
void delay(int);
void time2string( char *, int );
/* Written as part of i/o lab: getbtns, getsw, enable_interrupt */
int getbtns();
int getsw();
void enable_interrupt(void);
