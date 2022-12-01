#pragma once
#include "../utils/constants.h"
#include "./card/card-type.h"
#include "./deck/deck-type.h"

typedef struct {
    Card hand[POKER_HAND_AMOUNT];
    unsigned int money;
    unsigned int bet;
} PokerPlayer;

typedef struct {
    PokerPlayer player[POKER_PLAYER_AMOUNT];
    PokerPlayer dealer;
    Deck deck;
} PokerGame;

typedef enum {
    HIGH_CARD,
    PAIR,
    TWO_PAIR,
    THREE_OF_A_KIND,
    FOUR_OF_A_KIND,
    FULL_HOUSE,
    FLUSH,
    STRAIGHT,
} PokerHand;

typedef struct {
    PokerHand hand;
    int value;
} PokerEvalHand;