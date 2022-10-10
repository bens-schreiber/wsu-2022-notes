#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../game/craps_struct.h"

// Displays a scoreboard of the game, showing all the properites of the CrapsGame struct.
void scoreboardMessage(CrapsGame *game);

// Loads a statement with ellipsis
void _loadPrintf(char *loadingText, CrapsGame *game);

// Displays the game rules.
void gameRulesMessage();

// Displays the house balance.
void houseBalanceMessage(int balance);

// Press ENTER key to continue
void awaitInput();

// Press ENTER key to continue then display scoreboard.
void awaitScoreboard(CrapsGame *game);

// Place a wager
void placeWagerMessage(CrapsGame *game);

// Display the placed wager
void wagerPlacedMessage(int wager);

// Make a climatic "Rolling Dice" statement
void rollDiceMessage(CrapsGame *game);

// Display the value of diceSum
void showDiceMessage(int diceSum);

// Display that the game is over
void youLoseGameMessage();

// Display the point of the game.
void pointMessage(int point);

// Display the game has been won
void youWinGameMessage();

// Display the game is over
void exitMessage();

// Display the wager has been lost
void wagerLostMessage();

// Display the game is moving on to another game
void nextGameMessage();

// Display the user lost because they are out of money
void youLoseBecauseBrokeMessage();