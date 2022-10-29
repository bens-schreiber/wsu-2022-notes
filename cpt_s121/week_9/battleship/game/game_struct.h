#pragma once
#include "../utils.h"
#include "../board/board_struct.h"
#include "battleship_struct.h"

typedef struct
{
    GameBoard *gameBoard;
    BattleShip *shipMap[BOARD_ROWS * BOARD_COLUMNS];
    unsigned char score;
} BattleShipPlayer;

// Hashes a coordiante (x,y) into (( x*137 ) + y) % (BOARD_ROWS * BOARD_COLUMNS)
// for the BattleshipGamn.shipMap indexes
unsigned char _battleShipPlayerHashCoordinate(const Coordinate *coordinate);

// Initializes the player.gameBoard and player.shipMap as default values / blank
void _battleShipPlayerInitialize(BattleShipPlayer *player);

typedef struct
{
    BattleShipPlayer *playerOne;
    BattleShipPlayer *playerTwo;
    unsigned char round;
} BattleShipGame;

// Initializes both players with default values / blank.
void _battleShipGameInitialize(BattleShipGame *game);

// Fill the shipMap and gameBoard with SHIPS_PER_PLAYER ships
void _battleShipGamePlaceShips(BattleShipGame *game);

// Begins a game of battleship
// Loops round until the sum of all battleship sizes in consants.h is reached in a Player.score
void battleShipGameStart();

// Does a single round of the game
void _battleShipGameDoRound(BattleShipGame *game);

typedef enum
{
    MISS,
    HIT,
    SANK
} AttackResult;

// Fires an attack to a coordinate
// Returns an AttackResult (MISS, HIT, SANK)
AttackResult battleShipGameAttack(BattleShipGame *game, Coordinate coordinate);