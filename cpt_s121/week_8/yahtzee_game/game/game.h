#pragma once
#include "../messages/messages.h"
#include "yahtzeegamestruct.h"
#define YAHTZEE_ROUNDS 13
#define YAHTZEE_MAX_ROLLS 3
#define YAHTZEE_PLAYERS 2
#define YAHTZEE_SCORECARD 13

// starts a game of yahtzee
void yahtzeeGameStart();

// Does a single round of yahtzee
// [player] is 1 for player 1, or 2 for player 2.
void yahtzeeGameRound(YahtzeeGame *game, int player);

void yahtzeeGameDetermineWinner(YahtzeeGame *game);

void _yahtzeeGameChoosePoints(YahtzeeGame *game, int player);

// Assemble a score card with all valid options given the dice roll.
// This is done in linear time, O(2n) where n is the number of dice
// Return a pointer to the score card array. Indexes should be accessed using the
// ScoreCard enum values.
int *_yahtzeeScoreValidOptions(YahtzeeDie dice[YAHTZEE_DIE_COUNT]);

// Check a scoreCard for 3 of a kind, 4 of a kind, and yahtzee.
// Switch case won't work here as we need to use the greater than operator
void _yahtzeeScoreDetermineFrequencyScore(int frequency, int score, int diceSum, int scoreCard[13]);