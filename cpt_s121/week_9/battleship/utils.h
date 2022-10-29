#pragma once
#define BOARD_ROWS 10
#define BOARD_COLUMNS 10
#define SHIPS_PER_PLAYER 5
#define PLAYERS 2 // this shouldn't ever be changed or i'll come to your house and fight you

// ship sizes and also points
// winning score is determined by the sum of these
#define CARRIER_SIZE 5
#define BATTLESHIP_SIZE 4
#define CRUISER_SIZE 3
#define SUBMARINE_SIZE 3
#define DESTROYER_SIZE 2

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