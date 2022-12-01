#include "tests.h"

void runTests() {
    PokerPlayer testPlayer = {
        .bet = 0, 
        .money = INT32_MAX,
        .hand = {
            (Card) {.face = HEART, .value = TWO},
            (Card) {.face = HEART, .value = THREE},
            (Card) {.face = HEART, .value = FOUR},
            (Card) {.face = HEART, .value = FIVE},
            (Card) {.face = HEART, .value = SIX},
        }
        };
    
    PokerEvalHand result = pokerPlayerEvaluateHand(&testPlayer);
    switch (result.hand) {
        case HIGH_CARD:
            printf("HIGH CARD");
            break;
        case PAIR:
            printf("PAIR");
            break;
        case TWO_PAIR:
            printf("TWO PAIR");
            break;
        case THREE_OF_A_KIND:
            printf("THREE OF A KIND");
            break;
        case FOUR_OF_A_KIND:
            printf("FOUR OF A KIND");
            break;
        case STRAIGHT:
            printf("STRAIGHT");
            break;
        case FLUSH:
            printf("FLUSH");
            break;
        default:
            printf("unsupported");
    }
    printf(" %d", result.value + 2);
    printf("\n");



    getInput();
}