#ifndef CRAPS_MESSAGES
#define CRAPS_MESSAGES

#include <stdio.h>
#include <stdlib.h>

void gameRulesMessage();

void houseBalanceMessage(int balance);

void confirmMessage();

void placeWagerMessage(int *wager);

void wagerPlacedMessage(int wager);

void rollDiceMessage();

void showDiceMessage(int diceSum);

void youLoseGameMessage();

void pointMessage(int point);

void addToWagerMessage(int wager);

void youWinGameMessage();

void exitMessage();

#endif