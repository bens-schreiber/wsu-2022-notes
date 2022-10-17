#include "game.h"

void yahtzeeGameStart()
{
    system("clear");
    displayStartGameMessage();
    YahtzeeGame game = {
        .players = {}
    };
    while (game.round++ < YAHTZEE_ROUNDS)
    {
        for (char i = 0; i < YAHTZEE_PLAYERS; i++) {
            yahtzeeGameRound(&game, i);
        }
    }
    yahtzeeGameDetermineWinner(&game);
}

void yahtzeeGameDetermineWinner(YahtzeeGame *game)
{
    typedef struct
    {
        int sum;
        char player;
    } PlayerSum;

    PlayerSum highest = {.sum = 0, .player = 0};
    int sum = 0;
    for (char player = 0; player < YAHTZEE_PLAYERS; player++)
    {
        for (char score = 0; score < YAHTZEE_SCORECARD; score++)
        {
            sum += game->players[player][score];
        }
        if (sum > highest.sum)
        {
            highest.sum = sum;
            highest.player = player;
        }
        sum = 0;
    }

    displayPlayerWonMessage(highest.player);
    awaitInput();
}

void yahtzeeGameRound(YahtzeeGame *game, int player)
{
    yahtzeeDiceReset(game->dice);
    displayScoreboardMessage(game, player);
    awaitInput();

    for (char i = 0; i < YAHTZEE_MAX_ROLLS; i++)
    {
        displayClearAndTitleMessage();

        // Roll the dice, show player the roll
        displayRollingDiceMessage(i);
        yahtzeeDiceRoll(game->dice);
        displayDiceMessage(game);

        // See which dice the player wants to keep.
        if (awaitYorNInput("Do you want to keep any dice?"))
        {
            int input = 0;
            do
            {
                while (input < 1 || input > 6)
                {
                    awaitNumberInput(&input);
                }

                game->dice[input - 1].keepValue = 1;

                if (!awaitYorNInput("Do you want to keep more dice?"))
                {
                    break;
                }

                input = 0;

            } while (1);
        }

        if (!awaitYorNInput("Roll again?"))
        {
            break;
        }
    }

    // Prompt the player to choose their points
    _yahtzeeGameChoosePoints(game, player);

    // Show the player their score
    displayScoreboardMessage(game, player);
    awaitInput();
}

void _yahtzeeGameChoosePoints(YahtzeeGame *game, int player)
{
    int *scoreCardOpt = _yahtzeeScoreValidOptions(game->dice);
    int input = 0;
    displayRollOptions(player, scoreCardOpt);
    do
    {
        awaitYahtzeeRollOptionInput(&input);
    } while (input < 1 || input > YAHTZEE_SCORECARD || game->players[player][input - 1] > 0);

    printf("%d", scoreCardOpt[input - 1]);
    game->players[player][input - 1] = scoreCardOpt[input - 1];
    free(scoreCardOpt);
}

// Assemble a score card with all valid options given the dice roll.
// This is done in linear time, O(2n) where n is the number of dice
// Return a pointer to the score card array. Indexes should be accessed using the
// ScoreCard enum values.
int *_yahtzeeScoreValidOptions(YahtzeeDie dice[YAHTZEE_DIE_COUNT])
{
    // Initialize a frequency table, and dice sum.
    // Frequency table determines how many times a value appears.
    // Dice sum is used in calculating the score card.
    // Each value will be mapped to dice.value - 1. Account for this in future use.
    int frequencyTable[6] = {};
    int diceSum = 0;
    for (char i = 0; i < YAHTZEE_DIE_COUNT; i++)
    {
        frequencyTable[dice[i].value - 1]++;
        diceSum += dice[i].value;
    }

    // Find the valid options one could choose from the score card.
    // Iterate through the frequencyTable to fill score card values
    // With the frequency table, we don't need to sort to find a straight.
    // Simply increment [straight] each time a frequencyTable value isn't 0
    // consecutively until a straight is found. Reset if it is 0.
    int *scoreCardOpt = malloc(sizeof(int) * YAHTZEE_SCORECARD);
    int straight = 0;
    for (char i = 0; i < 6; i++)
    {
        // if the value is 0 we don't care
        if (!frequencyTable[i])
        {
            // Reset the straight counter
            straight = 0;
            continue;
        }

        // Initialize the 1s through 6s in the scoreCard
        // score = frequency * dice score
        int score = frequencyTable[i] * (i + 1);
        scoreCardOpt[i] = score;

        // Determine 3OAK, 4OAK, Yahtzee
        _yahtzeeScoreDetermineFrequencyScore(
            frequencyTable[i],
            score,
            diceSum,
            scoreCardOpt);

        // Wanted to be able to do this in constant time, found a way. Fun algorithm.
        // Check full house.
        // First, see if we have a frequency at 3.
        // A full house only happens if we have 3 of a die, and 2 of a die.
        // Subtract the score from diceSum.
        // EX: Dice: [3,3,3,2,2]; freqTable: [0,2,3,0,0,0] diceSum: 13; score: 9; diceSum - score = 4.
        // Then, divide this value by two. We are checking to see if two die made up this value.
        // EX: (diceSum - score) / 2 is 2.
        // Then, check the position in the frequency table for that value to see if there is a two.
        // EX: freqTable[(diceSum - score / 2) - 1] == 2
        if (frequencyTable[i] == 3 && (frequencyTable[((diceSum - score) / 2) - 1] == 2))
        {
            scoreCardOpt[FULL_HOUSE] = 25;
        }

        // Check for straights
        if (straight > 2)
        {
            scoreCardOpt[SMALL_STRAIGHT] = 30;
        }

        if (straight > 3)
        {
            scoreCardOpt[LARGE_STRAIGHT] = 40;
        }

        straight++;
    }

    return scoreCardOpt;
}

// Check a scoreCard for 3 of a kind, 4 of a kind, and yahtzee.
// Switch case won't work here as we need to use the greater than operator
void _yahtzeeScoreDetermineFrequencyScore(int frequency, int score, int diceSum, int scoreCard[13])
{
    // Check for three of a kind
    if (frequency > 2)
    {
        scoreCard[THREE_OF_A_KIND] =
            score + diceSum;
    }

    // Check for four of a kind
    if (frequency > 3)
    {
        scoreCard[FOUR_OF_A_KIND] =
            score + diceSum;
    }

    // Check for Yahtzee
    if (frequency > 4)
    {
        scoreCard[YAHTZEE] = 50;
    }
}
