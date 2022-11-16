#include "../utils/constants.h"
#include "./card/card-type.h"

typedef struct {
    Card hand[POKER_CARD_AMOUNT];
    unsigned int money;
} PokerPlayer;

typedef struct {
    PokerPlayer player[POKER_PLAYER_AMOUNT];
    PokerPlayer dealer;
    Card deck[POKER_DECK_AMOUNT];
} PokerGame;

void pokerGameInitDeck(PokerGame *game);