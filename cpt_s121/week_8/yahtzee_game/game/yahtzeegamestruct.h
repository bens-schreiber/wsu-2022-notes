#pragma once
#include "../dice/dice.h"
typedef struct
{
    YahtzeeDie dice[5];
    int players[2][13];
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