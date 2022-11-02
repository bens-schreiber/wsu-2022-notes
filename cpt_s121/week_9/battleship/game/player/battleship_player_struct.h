#pragma once
#include "../ship/battleship_struct.h"
#include "../game_struct.h"
#include "../../utils.h"
#include "../../board/board_struct.h"

// A player contains the locations of their ships
// and the score relative to how many ships they hit
typedef struct
{
    BattleShip *shipMap[BOARD_ROWS][BOARD_COLUMNS];
    unsigned char score;
} BattleShipPlayer;

// Fill shipMap with SHIPS_PER_PLAYER ships
void battleShipPlayerPlaceShips(BattleShipGame *game);

// Fill shipMap with SHIPS_PER_PLAYER ships
void battleShipPlayerGenerateShips(BattleShipGame *game);