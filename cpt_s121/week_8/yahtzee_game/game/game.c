#include "game.h"

void startYahtzeeGame() {
    YahtzeeGame game = {
        .playerOneScoreCard = {0},
        .playerTwoScoreCard = {0},
        .dice = {0}
    };

    for (int i = 0; i < YAHTZEE_ROUNDS; i++) {
        yahtzeeRound(&game, 1);
        yahtzeeRound(&game, 2);
    }
}
