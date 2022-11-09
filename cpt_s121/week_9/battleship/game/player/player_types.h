#pragma once
#include "../ship/ship_types.h"
#include "../../utils.h"
#include "../../board/board_struct.h"
#include "../../messages/messages.h"
#include <time.h>
#include <string.h>
#include <stdlib.h>

// [ships] - An array of all the ships that will be placed on [shipMap]
// [shipMap] - An array of pointers to the ships in [ships]. Used to attack a battleship in constant time.
// [gameBoard] - A physical representation of the 2d board
// [score] - Players score, incremenets with every successful hit
typedef struct
{
    BattleShip ships[SHIPS_PER_PLAYER];
    BattleShip *shipMap[BOARD_ROWS][BOARD_COLUMNS];
    GameBoard *gameBoard;
    unsigned char score;
} BattleShipPlayer;

// Fill shipMap with SHIPS_PER_PLAYER ships
void battleShipPlayerPlaceShips(BattleShipPlayer *player);

// Fill shipMap with SHIPS_PER_PLAYER ships
void battleShipPlayerGenerateShips(BattleShipPlayer *player);