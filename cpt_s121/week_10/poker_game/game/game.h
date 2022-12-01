#pragma once
#include "poker-type.h"
#include "../log/log.h"
#include "deck/deck-type.h"

PokerGame *pokerGame();

void startPokerGame(PokerGame *game);

void pokerGamePlaceBets(PokerGame *game);

void pokerGameDeal(PokerGame *game);

void pokerGameReplacePlayerCards(PokerGame *game, int playerIndex, int *deckIndex);

void pokerGameFindWinner(PokerGame *game);

PokerEvalHand pokerPlayerEvaluateHand(PokerPlayer *player);

