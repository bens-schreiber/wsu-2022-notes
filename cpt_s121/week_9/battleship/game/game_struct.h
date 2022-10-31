#pragma once
#include "../utils.h"
#include "../board/board_struct.h"
#include "battleship_struct.h"

// A player contains the hash of where their ships are
// and the score relative to how many ships they hit
typedef struct
{
    BattleShip *shipMap[BOARD_ROWS * BOARD_COLUMNS];
    unsigned char score;
} BattleShipPlayer;

// Hashes a coordiante (x,y) into (( x*137 ) + y) % (BOARD_ROWS * BOARD_COLUMNS)
// for the BattleshipGamn.shipMap indexes
unsigned char _battleShipPlayerHashCoordinate(const Coordinate *coordinate);

typedef struct
{
    BattleShipPlayer *player;
    BattleShipPlayer *computer;
    GameBoard *gameBoard;
    unsigned char round;
} BattleShipGame;

// Initializes both players with default values / blank.
void _battleShipGameInitialize(BattleShipGame *game);

// Initializes the game.gameBoard and player.shipMap as default values / blank
void _battleShipGameBoardInitialize(BattleShipGame *game);

// Fill the shipMap and gameBoard with SHIPS_PER_PLAYER ships
void _battleShipGamePlaceShips(BattleShipGame *game);

// Begins a game of battleship
// Loops round until the sum of all battleship sizes in consants.h is reached in a Player.score
void battleShipGameStart();

// Does a single round of the game for the player
void _battleShipGameDoPlayerRound(BattleShipGame *game);

// Does a single round for the computer
void _battleShipGameDoComputerRound(BattleShipGame *game);

typedef enum
{
    MISS,
    HIT,
    SANK
} AttackResult;

// Fires an attack to a coordinate
// Returns an AttackResult (MISS, HIT, SANK)
AttackResult battleShipGameAttack(BattleShipGame *game, Coordinate coordinate);