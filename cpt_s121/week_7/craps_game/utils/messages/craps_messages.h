#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../game/craps_struct.h"

void titleMessage(CrapsGame *game);

void _loadPrintf(char *loadingText, CrapsGame *game);

void gameRulesMessage();

void houseBalanceMessage(int balance);

void confirmMessage();

void confirmMessageTitle(CrapsGame *game);

void placeWagerMessage(int *wager);

void wagerPlacedMessage(int wager);

void rollDiceMessage(CrapsGame *game);

void showDiceMessage(int diceSum);

void youLoseGameMessage();

void pointMessage(int point);

void addToWagerMessage(int wager);

void youWinGameMessage();

void exitMessage();

void resetWagerMessage();

void anotherGameMessage();