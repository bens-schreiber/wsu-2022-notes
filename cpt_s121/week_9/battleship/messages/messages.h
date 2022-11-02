#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "../board/board_struct.h"
#include "../game/ship/battleship_struct.h"

void printMenu();

void printRules();

void printExit();

// press any key to continue
void awaitInput();

// returns the input
int getIntInput(const char *inputMessage);

// Prints the game board
void printGameBoard(GameBoard *gameBoard);

void printInvalidArgument();

void printComputerWins();

void printPlayerWins();
