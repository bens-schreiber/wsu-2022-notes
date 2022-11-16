#include "game.h"
void pokerGameInitDeck(PokerGame *game)
{
    int index = 0;
    for (int value = 0; value < CARD_VALUE_AMOUNT; ++value) {
        for (int face = 0; face < CARD_FACE_AMOUNT; ++face) {
             game->deck[index] = (Card) {.value = index, .face = face};
             ++index;
        }
    }
}