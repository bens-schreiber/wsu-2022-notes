#pragma once
#include "../utils.h"
#include "../board/board_struct.h"
#include "battleship_struct.h"
#include "../messages/messages.h"

// A player contains the locations of their ships
// and the score relative to how many ships they hit
typedef struct
{
    BattleShip *shipMap[BOARD_ROWS][BOARD_COLUMNS];
    unsigned char score;
} BattleShipPlayer;

typedef struct
{
    BattleShipPlayer *player;
    BattleShipPlayer *computer;
    GameBoard *gameBoard;
    unsigned char round;
} BattleShipGame;

// Initializes all valeus of BattleShipGame
BattleShipGame *battleShipGame();

// Fill the shipMap and gameBoard with SHIPS_PER_PLAYER ships
void _battleShipGamePlaceShips(BattleShipGame *game);

// Begins a game of battleship
// Loops round until the sum of all battleship sizes in consants.h is reached in a Player.score
void battleShipGameStart(BattleShipGame *game);

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