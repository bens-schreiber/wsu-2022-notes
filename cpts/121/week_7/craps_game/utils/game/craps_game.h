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

// Do the first round of craps
int doRoundOne(CrapsGame *game);

// Add wager to balance and reset
void wagerWon(CrapsGame *game);

// Sub wager from balance and reset
void wagerLost(CrapsGame *game);

// Change the wager, house balance and player balance to reflect winning the game.
// Player balance + 2*Wager (2 times because it was initially subtracted)
// House balance - wager
void winGame(CrapsGame *game);

// Change the wager, house balance and player balance to reflect losing the game
// Player balance - wager
// House balance + wager
void loseGame(CrapsGame *game);