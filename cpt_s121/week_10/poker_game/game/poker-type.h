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

typedef struct {
    PokerHand hand;
    int value;
} PokerEvalHand;