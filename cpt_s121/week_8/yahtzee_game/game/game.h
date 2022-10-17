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

int *_yahtzeeScoreValidOptions(YahtzeeDie dice[YAHTZEE_DIE_COUNT]);

void _yahtzeeScoreDetermineFrequencyScore(int frequency, int score, int diceSum, int scoreCard[13]);