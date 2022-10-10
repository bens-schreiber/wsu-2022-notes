#pragma once
#include "./die/die.h"
#include "../messages/craps_messages.h"
#include "./craps_struct.h"

#define CONTINUE_GAME 1
#define EXIT_GAME 0

// Entrypoint for the craps game. Begin the game.
int crapsGame();

// Do a round of craps
int doRound(CrapsGame *game);

void placeWager(CrapsGame *game);

void addToWager(CrapsGame *game);

void winGame(CrapsGame *game);

void loseGame(CrapsGame *game);