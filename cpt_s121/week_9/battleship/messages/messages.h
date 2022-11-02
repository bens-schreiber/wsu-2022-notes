#pragma once
#include <stdio.h>
#include "../board/board_struct.h"
#include "../game/game_struct.h"
#include "../game/ship/battleship_struct.h"

void printMenu();

void printRules();

void printExit();

// press any key to continue
void awaitInput();

// returns the input
unsigned char getIntOrCharInput(const char *inputMessage);

// Prints the game board
void printGameBoard(GameBoard *gameBoard);

// Prints the game board and remaining ships in the ship array
void printBattleshipPlacement(BattleShipGame *game, BattleShip *ship[SHIPS_PER_PLAYER]);

void printInvalidArgument();

// enter the coordinates x and y for your ship
void printShipPlacementInstructions(const BattleShip *ship);

// prints the score, and what ships are remaining
void printScoreBoard(BattleShipGame *game);

// returns coordinates
Coordinate getCoordinates();

void printShipMissed(BattleShipGame *game);

void printShipHit(BattleShipGame *game);

void printShipSank(BattleShipGame *game);

void printGameWon(int winner);
