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

// void pokerGameShuffleDeck(int wDeck[][13])
// {
// 	int row = 0;    /* row number */
// 	int column = 0; /*column number */
// 	int card = 0;   /* card counter */

// 	/* for each of the 52 cards, choose slot of deck randomly */
// 	for (card = 1; card <= 52; card++)
// 	{
// 		/* choose new random location until unoccupied slot found */
// 		do
// 		{
// 			row = rand () % 4;
// 			column = rand () % 13;
// 		} while (wDeck[row][column] != 0);

// 		/* place card number in chosen slot of deck */
// 		wDeck[row][column] = card;
// 	}
// }