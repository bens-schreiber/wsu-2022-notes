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
void displayScoreboardMessage(YahtzeeGame *game);

// Roll dice
// [firstRoll] if not on first roll, display a slightly different message
void displayRollingDiceMessage(int firstRoll);

// Display the dice values
void displayDiceMessage(YahtzeeGame *game);

// Options after dice roll
void displayRollOptions(YahtzeeGame *game, int *validScoreCard);

// yahtzee dice input should be between 1 and 13
void invalidYahtzeeDiceInput();

// you win!!!
void displayPlayerWonMessage(int player);

// clears the screen and then displays the TITLE
void displayClearAndTitleMessage();

// Y or N response
// Return 1 if y 0 if n
int awaitYorNInput(char *message);

// user input selecting one of the roll options
void awaitYahtzeeRollOptionInput(int *input);

// get a number 1-5 for the dice, 0 to exit
void awaitNumberInput(int *input);

// press any key to continue
void awaitInput();

// Waits for menu option input
// 1 - print rules
// 2 - start game
// 3 - exit
int awaitMenuInput();