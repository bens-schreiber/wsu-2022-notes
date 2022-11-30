#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "../game/poker-type.h"
#include "../game/card/card-type.h"

// clears the output
void logClear();

// returns integer input
int getIntInput();

void getInput();

void logMenu();

// prints out the game rules
void logRules();

// ask the player to input a bet
void logAskBet(int player, int balance);

void logPlayerHand(PokerPlayer *player);

void logAskDiscardAmount(int player);