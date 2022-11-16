#include "game.h"

void startPokerGame() {

    // malloc this
    PokerGame game = {
        .player = (PokerPlayer) {.money = POKER_STARTING_MONEY_AMOUNT},
        .dealer = (PokerPlayer) {.money = POKER_STARTING_MONEY_AMOUNT},
        .deck = {0}
    };

    initDeck(&game);
    return;

}
