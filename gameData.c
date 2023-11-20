/*
 * This file stores the objects that are displayed on the screen
 * 
 * Created by Axel Karlsson
 * 2021 - 03 - 02
 * 
 */
/* The type of objects displayed are stored here
 * 0 represents the player controlled car
 * 1 represents a rock
 * 2 represents an oil patch
 * 3 represents a computer controlled car
 * 
 * Index 0 is always the player controlled car
 */ 
uint8_t objectType[8];

/*
 * The positions of the objects are stored here. Each index is connected to an index
 * in objectType. For example, indexes 0 store the player controlled cars coordinates and
 * index 1 stores the coordinates of whatever object is stored in index 1 in objectType.
 */
uint8_t xCords[8];
uint8_t yCords[8];