#pragma once
#include "../dice/dice.h"
#include "constants.h"

// Main struct for storing game values.
typedef struct
{

    // A set of 5 dice
    YahtzeeDie dice[5];

    // Array of players
    int players[YAHTZEE_PLAYERS][13];

    // Round of the game
    int round;

} YahtzeeGame;

// Stores index positions of the YahtzeeScoreCard
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