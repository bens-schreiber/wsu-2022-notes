#pragma once
#include "../messages/messages.h"
#include "yahtzeegamestruct.h"
#include "constants.h"


// Begins the game of yahtzee. Main loop of YAHTZEE_ROUNDS here.
void yahtzeeGameStart();

// Does a single round of yahtzee
// [game] holds the current games values
// [player] determines the index of the game->players array to modify the scorecard at.
void yahtzeeGameRound(YahtzeeGame *game, int player);

// Determines who won the game based off the highest sum.
// [game] holds the current games values
void yahtzeeGameDetermineWinner(YahtzeeGame *game);

// Awaits player input to chose what points from the generated valid scorecard.
// [game] holds the current games values
// [player] determines the index of the game->players array to modify the scorecard at.
void _yahtzeeGameChoosePoints(YahtzeeGame *game, int player);

// Assemble a score card with all valid options given the dice roll.
// This is done in linear time, O(2n) where n is the number of dice
// Return a pointer to the score card array. Indexes should be accessed using the
// ScoreCard enum values.
int *_yahtzeeScoreValidOptions(YahtzeeDie dice[YAHTZEE_DIE_COUNT]);

// Check a scoreCard for 3 of a kind, 4 of a kind, and yahtzee.
// Switch case won't work here as we need to use the greater than operator
void _yahtzeeScoreDetermineFrequencyScore(int frequency, int score, int diceSum, int scoreCard[13]);