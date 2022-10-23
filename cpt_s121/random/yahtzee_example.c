#define DICE_AMOUNT 5
#define PLAYER_AMOUNT 2
#define SCORECARD_AMOUNT 13
#define GAME_ROUNDS 13
#define MAX_ROLLS 3

// Core mechanics of the game
int main(int argc, char const *argv[])
{

    // Initialize dice
    int dice[DICE_AMOUNT] = {0};

    // We will use this in tandem with [dice] to see if we are keeping a dice value or not.
    int keepDice[DICE_AMOUNT] = {0};

    // Initialize players
    int players[PLAYER_AMOUNT][SCORECARD_AMOUNT] = {{-1}, {-1}}; // Player mapped to their scorecard

    // For counting down the rounds
    int round = GAME_ROUNDS;

    // We will switch players each round
    int player;

    do {
        
        // We need this because there are X amount of players (2 unless it is changed)
        // Each round we need to select a different player. This is a clever little way to get the player based off the round.
        player = round % PLAYER_AMOUNT;

        // Roll the dice as many times as the player wants
        int rolls = MAX_ROLLS;
        do {

            // This function should take each value of dice, and roll it if keepDice != -1.
            // EX: for (int i = 0; i < DICE_AMOUNT; i++) { if (keepDice[i] != -1) dice[i] = random number 1-6 }
            rollDice(dice, keepDice);

            // Make a function to get the input Y/y or N/n. If the user enters Y, return 1. If N, return 0.
            // In this case, if they enter Y, we will keep some dice.
            // Can while loop this if you want them to select as many dice as they want.
            if (enterYorN("Do you want to keep any dice?")) {
                int die = getDiceInput(); // Get a dice 1-5
                keepDice[die - 1] = 1; // Keep the dice.
            }

            
            // In this case, if they enter N, they want to stop rolling. 
            // We will use the break statement to stop the loop at this point.
            if (!enterYorN("Do you want to keep rolling?")) {
                break;  // Break means stop the entire while loop
            }

            rolls--;
            
        } while (rolls); // same as rolls != 0

        // At this point, the player has completed their round.
        // You have options for how you want to continue.
        // Option 1 (easier one): Show the player their score card.
        // Let the player select whichever scorecard value they want, EX: Yahtzee.
        // Then, have a specific function called checkYahtzee(int dice[DICE_AMOUNT]) that looks for a yahtzee.
        // Option 2 (harder, the one I did): Calculate every possible outcome of the dice rolled in linear time (1 loop through)
        // then, display the possible outcomes. 
        // I have listed the function i used to do option 2. I am not going to modify it from how I initially had it, but you can look through it.
        // It isnt super complicated

        // Get the possible scorecard
        int *possibleScoreCard = _yahtzeeScoreValidOptions(dice);

        // Loop until we have a valid input
        while (1) {
            int userInput = getUserInput("Enter a value 1-13 for the yahtzee scorecard");
            if (players[player][userInput] != -1) {
                players[player][userInput] = possibleScoreCard[userInput];
            }
        }
        
        // Signify we are on the next round
        round--;
    } while (round); // same as round != 0

    // Now we just have to loop through the players to see who has the largest sum of dice, and display that as the winner.
    
    return 0;
}

// Stores index positions of the YahtzeeScoreCard
// This is a little fancy, but think of it as a bunch of definitons.
// It basically turns into this:
// #define SUM_OF_ONES 0
// #define SUM_OF_TWOS 1
// ...
// It is just useful to keep the indexes.
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

