#pragma once
#include "../utils.h"

typedef struct
{
    char board[BOARD_ROWS][BOARD_COLUMNS];
} GameBoard;

// Initialize all values to '~' (tilde)
void gameBoardInitialize(GameBoard *gameBoard);

// Place a character at a  coordinate on the game board
// returns 1 if successful 0 if unsuccessful (value out of bounds)
int gameBoardPlaceValue(GameBoard *gameBoard, const char value, const Coordinate coordinate);

// Place an array of characters beginning at a coordinate facing (placing in) a direction
// returns 1 if successful 0 if unsuccessful (values applied to the gameboard in directon can be out of bounds)
int gameBoardPlaceValues(GameBoard *gameBoard, const char *values, const Coordinate coordinate, const Direction direction);