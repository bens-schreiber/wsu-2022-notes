#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "../board/board_struct.h"
#include "../game/ship/battleship_struct.h"

#define ATTACK_INSTRUCTIONS "Select a tile to attack! (WASD to move, Y to place) (X: HIT) (M: MISS) (O: CURSOR)"
#define ATTACK_LAUNCHED "Attack Launched (X: HIT) (M: MISS) (O: CURSOR)"

void printMenu();

void printRules();

void printExit();

// press any key to continue
void awaitInput();

// returns the input
int getIntInput(const char *inputMessage);

char getCharInput(const char *inputMessage);

// Prints the game board
void printGameBoard(GameBoard *gameBoard, const char *titleMessage);

void printInvalidArgument();

void printComputerWins();

void printPlayerWins();
