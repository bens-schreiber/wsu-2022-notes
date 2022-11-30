#pragma once
#include "poker-type.h"
#include "../log/log.h"
#include "deck/deck-type.h"

void startPokerGame();

void pokerGamePlaceBets(PokerGame *game);

void pokerGameDeal(PokerGame *game);

void pokerPlayerReplaceCards(PokerPlayer *player, int player,  int *deckIndex);

