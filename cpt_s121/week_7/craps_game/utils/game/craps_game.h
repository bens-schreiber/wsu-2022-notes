#include "./die/die.h"
#include "craps_messages.h"

#define CONTINUE_GAME 1
#define EXIT_GAME 0

typedef struct {
    int diceSum;
    int wager;
    int houseBalance;
    int playerBalance;
    int crapsPoint;
    int round;
} CrapsGame;

// Entrypoint for the craps game. Begin the game.
int crapsGame();

// Do a round of craps
int doRound(CrapsGame *game);

void placeWager(CrapsGame *game);

void addToWager(CrapsGame *game);



