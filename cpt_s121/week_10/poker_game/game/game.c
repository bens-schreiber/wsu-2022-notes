#include "game.h"

void startPokerGame() {

    // malloc this
    PokerGame game = {
        .player = (PokerPlayer) {.money = POKER_STARTING_MONEY_AMOUNT},
        .dealer = (PokerPlayer) {.money = POKER_STARTING_MONEY_AMOUNT},
        .deck = {0}
    };

    pokerGameInitDeck(&game);
    return;

}

void pokerGameInitDeck(PokerGame *game)
{
    int index = 0;
    for (int value = 0; value < CARD_VALUE_AMOUNT; ++value) {
        for (int face = 0; face < CARD_FACE_AMOUNT; ++face) {
             game->deck[index] = (Card) {.value = value, .face = face};
             ++index;
        }
    }
}