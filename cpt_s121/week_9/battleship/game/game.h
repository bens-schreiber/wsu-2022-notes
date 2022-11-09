#pragma once
#include "game_types.h"
#include "./player/player.h"
#include "../utils.h"
#include "../board/board_struct.h"
#include "../messages/messages.h"
#include "../log/log.h"

// Begins a game of battleship
// Loops round until the sum of all battleship sizes in consants.h is reached in a Player.score
void battleShipGameStart();

// Does a single round of the game for the player
void _battleShipGameDoPlayerRound(BattleShipGame *game);

// Does a single round for the computer
void _battleShipGameDoComputerRound(BattleShipGame *game);

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