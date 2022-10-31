#pragma once
#include "./game/battleship_struct.h"

// max val 16 x 16 (uint8 range)
#define BOARD_ROWS 10
#define BOARD_COLUMNS 10

#define SHIPS_PER_PLAYER 5
#define HASH_SALT 137

typedef struct
{
    const unsigned int X;
    const unsigned int Y;
} Coordinate;

typedef enum
{
    UP,
    DOWN,
    LEFT,
    RIGHT
} Direction;