#include "../game/game.h"
#include <stdio.h>

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
void displayRollOptions(YahtzeeGame *game);

// Y or N response
// Return 1 if y 0 if n
int awaitYorNInput(char *message);

// user input selecting one of the roll options
int awaitYahtzeeRollOptionInput();