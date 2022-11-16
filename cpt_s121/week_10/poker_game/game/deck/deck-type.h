#include "../utils/constants.h"
#include "../card/card-type.h"

typedef struct {
    Card deck[POKER_DECK_AMOUNT];
} Deck;

void deckInit(Deck *deck);
