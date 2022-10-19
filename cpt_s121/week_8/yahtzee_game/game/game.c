#include "game.h"

void yahtzeeGameStart()
{
    system("clear");
    displayStartGameMessage();

    // Initialize a new game
    YahtzeeGame game = {};

    // Play YAHTZEE_ROUNDS amount of rounds
    while (game.round++ < YAHTZEE_ROUNDS)
    {

        // For each player, do a turn.
        for (char i = 0; i < YAHTZEE_PLAYERS; i++) {
            yahtzeeGameRound(&game, i);
        }
    }

    // Output the game winner
    yahtzeeGameDetermineWinner(&game);
}

void yahtzeeGameDetermineWinner(YahtzeeGame *game)
{

    // A struct to make determining the winner easier
    typedef struct
    {
        int sum;
        char player;
    } Winner;

    // Assume the winner is player 0
    Winner highest = {.sum = 0, .player = 0};

    // Compare the sum of each player to the highesst
    int sum = 0;
    for (char player = 0; player < YAHTZEE_PLAYERS; player++)
    {
        
        // Tally the total for the player
        for (char score = 0; score < YAHTZEE_SCORECARD; score++)
        {
            sum += game->players[player][score];
        }

        // If the sum is larger than the highest, this player is the highest
        if (sum > highest.sum)
        {
            highest.sum = sum;
            highest.player = player;
        }

        // Reset sum
        sum = 0;
    }

    // Output who won
    displayPlayerWonMessage(highest.player);
    awaitInput();
}

void yahtzeeGameRound(YahtzeeGame *game, int player)
{
    // Reset the dice "keepValue" values from the previous round.
    yahtzeeDiceReset(game->dice);

    // Display the scoreboard
    displayScoreboardMessage(game, player);
    awaitInput();

    // Do YAHTZEE_MAX_ROLLS amount of rolls (at maximum)
    for (char i = 0; i < YAHTZEE_MAX_ROLLS; i++)
    {

        // Title message
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

        // Break out of loop if user doesn't want to roll again
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

    game->round++;
}

void _yahtzeeGameChoosePoints(YahtzeeGame *game, int player)
{

    // Generate a valid score card
    int *scoreCardOpt = _yahtzeeScoreValidOptions(game->dice);

    // Get player input. Loop incase the input is invalid
    int input = 0;
    displayRollOptions(game, player, scoreCardOpt);
    do
    {
        awaitYahtzeeRollOptionInput(&input);
    } while (input < 1 || input > YAHTZEE_SCORECARD || game->players[player][input - 1] > 0);

    // Set the scorecard value
    game->players[player][input - 1] = scoreCardOpt[input - 1];
    free(scoreCardOpt);
}

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

    // Chance section is just the sum
    scoreCardOpt[CHANCE] = diceSum;

    return scoreCardOpt;
}

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
