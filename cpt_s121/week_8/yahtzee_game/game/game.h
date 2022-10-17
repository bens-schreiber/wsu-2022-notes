#pragma once
#include "../dice/dice.h"
#include "../messages/messages.h"
#define YAHTZEE_ROUNDS 13
#define YAHTZEE_MAX_ROLLS 3

typedef struct
{
    YahtzeeDie dice[5];
    int playerOneScoreCard[13];
    int playerTwoScoreCard[13];
    int round;

} YahtzeeGame;

typedef enum
{
    SUM_OF_ONES,
    SUM_OF_TWOS,
    SUM_OF_THREES,
    SUM_OF_FOURS,
    SUM_OF_FIVES,
    SUM_OF_SIXES,
    THREE_OF_A_KIND,
    FOUR_OF_A_KIND,
    FULL_HOUSE,
    SMALL_STRAIGHT,
    LARGE_STRAIGHT,
    YAHTZEE,
    CHANCE
} YahtzeeScore;

// starts a game of yahtzee
void yahtzeeGameStart();

// Does a single round of yahtzee
// [player] is 1 for player 1, or 2 for player 2.
void yahtzeeGameRound(YahtzeeGame *game, int player);

int *_yahtzeeScoreFillOptions(YahtzeeDie dice[YAHTZEE_DIE_COUNT]);


