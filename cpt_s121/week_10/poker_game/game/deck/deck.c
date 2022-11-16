#include "deck-type.h"

void deckInit(Deck *deck)
{
    int index = 0;
    for (int value = 0; value < CARD_VALUE_AMOUNT; ++value) {
        for (int face = 0; face < CARD_FACE_AMOUNT; ++face) {
             deck->deck[index] = (Card) {.value = value, .face = face};
             ++index;
        }
    }
}

void deckShuffle(Deck *deck)
{
	
}