#include "../game/yahtzeegamestruct.h"
#include <stdio.h>
#include <stdlib.h>
#define TITLE "### YAHTZEE By Benjamin Schreiber ###\n\n"

// Menu options
void displayMenuMessage();

// Game rules
void displayGameRulesMessage();

// Game intro
void displayStartGameMessage();

// Game scoreboard
void displayScoreboardMessage(YahtzeeGame *game, int player);

// Roll dice
// [firstRoll] if not on first roll, display a slightly different message
void displayRollingDiceMessage(int firstRoll);

// Display the dice values
void displayDiceMessage(YahtzeeGame *game);

// Options after dice roll
void displayRollOptions(int player, int *scoreCardOpt);

// yahtzee dice input should be between 1 and 13
void invalidYahtzeeDiceInput();

// you win!!!
void displayPlayerWonMessage(int player);

void displayClearAndTitleMessage();

// Y or N response
// Return 1 if y 0 if n
int awaitYorNInput(char *message);

// user input selecting one of the roll options
void awaitYahtzeeRollOptionInput(int *input);

// get a number 1-5 for the dice, 0 to exit
void awaitNumberInput(int *input);

void awaitInput();