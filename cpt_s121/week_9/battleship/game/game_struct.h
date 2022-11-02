#pragma once
#include "../utils.h"
#include "../board/board_struct.h"
#include "./player/battleship_player_struct.h"
#include "./ship/battleship_struct.h"
#include "../messages/messages.h"

typedef struct
{
    BattleShipPlayer *player;
    BattleShipPlayer *computer;
    GameBoard *gameBoard;
    unsigned char round;
} BattleShipGame;


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

// MESSAGES

// Prints the game board and remaining ships in the ship array
void printBattleshipPlacement(BattleShipGame *game, BattleShip *ship[SHIPS_PER_PLAYER]);

// prints the score, and what ships are remaining
void printScoreBoard(BattleShipGame *game);

void printShipMissed(BattleShipGame *game);

void printShipHit(BattleShipGame *game);

void printShipSank(BattleShipGame *game);