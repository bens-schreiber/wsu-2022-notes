#pragma once
#include "./game/ship/battleship_struct.h"

// max val 16 x 16 (uint8 range)
#define BOARD_ROWS 10
#define BOARD_COLUMNS 10

// Tweak how many ships you want and what the values should be
// Winning score should be the total of all hitpoints of the ships (defined in battleship_struct.h)
#define SHIPS_PER_PLAYER 5
#define SHIPS {BATTLE_SHIP_CARRIER, BATTLE_SHIP_BATTLESHIP, BATTLE_SHIP_CRUISER, BATTLE_SHIP_SUBMARINE, BATTLE_SHIP_DESTROYER}
#define WINNING_SCORE 17

// Change to 0 if you want to see the generated ship locations
#define HIDE_ENEMY_SHIPS 0

// should probabluy keep this low
#define SHIP_PLACEMENT_SALT 3

typedef struct
{
    const unsigned int X;
    const unsigned int Y;
} Coordinate;

typedef enum
{
    HORITZONTAL,
    VERTICAL
} Axis;