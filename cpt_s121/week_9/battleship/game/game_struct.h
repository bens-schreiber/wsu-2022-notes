#pragma once
#include "../utils.h"
#include "../board/board_struct.h"
#include "./player/battleship_player_struct.h"
#include "./ship/battleship_struct.h"
#include "../messages/messages.h"

// [player] - The main player of the game
// [computer] - The enemy. Has a blank gameBoard that is the board the player sees.
// [round] - Keeps track of how many rounds the game has gone through
typedef struct
{
    BattleShipPlayer *player;
    BattleShipPlayer *computer;
    unsigned char round;
} BattleShipGame;


// Begins a game of battleship
// Loops round until the sum of all battleship sizes in consants.h is reached in a Player.score
void battleShipGameStart();

// Does a single round of the game for the player
void _battleShipGameDoPlayerRound(BattleShipGame *game);

// Does a single round for the computer
void _battleShipGameDoComputerRound(BattleShipGame *game);

// Outcomes of an attack
typedef enum
{
    MISS,
    HIT,
    SANK
} AttackResult;

// Fires an attack to a coordinate
// Returns an AttackResult (MISS, HIT, SANK)
AttackResult battleShipGameAttack(BattleShipPlayer *attack, BattleShipPlayer *player, Coordinate coordinate);

// Processes what to do with an AttackResult
// Returns 1 if sank 0 if hit or miss.
unsigned char _processAttackResult(AttackResult attackResult, BattleShipPlayer *player, Coordinate coordinate);

// MESSAGES

// prints the score, and what ships are remaining
void printScoreBoard(BattleShipGame *game);

// prints the ship that was sank
void printShipSank(BattleShipPlayer *player, Coordinate coordinate);