#pragma once
#include "./game/ship/ship_types.h"

// max val 15 x 15 (uint8 range but 256,256 is saved for NULL)
// display gets wonky over 10 thoughw
#define BOARD_ROWS 10
#define BOARD_COLUMNS 10

// Tweak how many ships you want and what the values should be
// Winning score should be the total of all hitpoints of the ships (defined in battleship_struct.h)
#define SHIPS_PER_PLAYER 5
#define SHIPS {BATTLE_SHIP_CARRIER, BATTLE_SHIP_BATTLESHIP, BATTLE_SHIP_CRUISER, BATTLE_SHIP_SUBMARINE, BATTLE_SHIP_DESTROYER}
#define WINNING_SCORE 17

// Markers on the game board
#define HIT_MARKER 'X'
#define MISS_MARKER 'M'
#define CURSOR_MARKER '0'

// Change to 0 if you want to see how the ships generated at the beginning of the game
#define HIDE_ENEMY_SHIPS 1

// should probabluy keep this low
#define SHIP_PLACEMENT_SALT 3

typedef struct
{
    unsigned int X;
    unsigned int Y;
} Coordinate;

typedef enum
{
    HORITZONTAL,
    VERTICAL
} Axis;