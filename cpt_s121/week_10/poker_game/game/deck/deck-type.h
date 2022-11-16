#pragma once
#include "../../utils/constants.h"
#include "../card/card-type.h"
#include <stdlib.h>
#include <time.h>

typedef struct {
    Card deck[POKER_DECK_AMOUNT];
} Deck;

void deckInit(Deck *deck);

void deckShuffle(Deck *deck);
