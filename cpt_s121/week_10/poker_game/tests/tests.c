#include "tests.h"

void runTests() {
    PokerPlayer testPlayer = {
        .bet = 0, 
        .money = INT32_MAX,
        .hand = {
            (Card) {.face = HEART, .value = 0},
            (Card) {.face = HEART, .value = 0},
            (Card) {.face = HEART, .value = 0},
            (Card) {.face = HEART, .value = 0},
            (Card) {.face = HEART, .value = 0},
        }
        };
    
    PokerEvalHand result = pokerPlayerEvaluateHand(&testPlayer);
    printf("hand: %d \n value %d", result.hand, result.value);
}