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
	srand(time(NULL));
    int iterations = POKER_SHUFFLE_AMOUNT;
    int index1 = 0;
    int index2 = 0;
    while (--iterations) {

        // generate indexes
        index1 = rand() % POKER_DECK_AMOUNT;
        index2 = rand() % POKER_DECK_AMOUNT;

        // swap index 1 with index 2
        Card tmp = deck->deck[index1];
        deck->deck[index1] = deck->deck[index2];
        deck->deck[index2] = tmp;
    }
}