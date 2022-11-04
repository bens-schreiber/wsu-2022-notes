#pragma once
#include "../ship/battleship_struct.h"
#include "../../utils.h"
#include "../../board/board_struct.h"
#include "../../messages/messages.h"
#include <time.h>
#include <string.h>
#include <stdlib.h>

// A player contains the locations of their ships
// and the score relative to how many ships they hit
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

unsigned char _notTouchingAndNoShips(unsigned char row, unsigned char column, unsigned char valid[BOARD_ROWS][BOARD_COLUMNS]);