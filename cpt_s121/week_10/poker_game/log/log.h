#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "../game/poker-type.h"
#include "../game/card/card-type.h"
#include <string.h>

// clears the output
void logClear();

// returns integer input
int getIntInput();

int *getIntInputs(int size, int *actualSize);

void getInput();

void logMenu();

// prints out the game rules
void logRules();

// ask the player to input a bet
void logAskBet(int player, int balance);

void logPlayerHand(PokerPlayer *player);

void logAskDiscardAmount(int player);

void logPlayerWins(int player, int bet);

void logPlayerLost(int player, int bet);

void logDealerWins();

void logPlayAgain();