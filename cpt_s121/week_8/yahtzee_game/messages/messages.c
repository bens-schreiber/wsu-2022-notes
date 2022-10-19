#include "messages.h"

// Menu options
void displayMenuMessage()
{
    printf(
        "##################################################\n\n"
        "   Welcome to Yahtzee by Benjamin Schreiber\n"
        "   Enter 1 to view the rules\n"
        "   Enter 2 to start the game\n"
        "   Enter 3 to exit\n\n"
        "##################################################\n");
}

// Game rules
void displayGameRulesMessage()
{
    printf(
        "\nthese are the rules of the yacht Z\n"
        "there are 13 rounds (you can change this in game/constants.h\n"
        "there are 2 players (you can change this in game/constants.h)\n"
        "each player has 5 dice (you can change this in dice/dice.h)\n"
        "roll the dice. you may keep any die to remain the same for the remainder of the rolls.\n"
        "each player gets 3 rolls maximum.\n"
        "from the valid score options, choose an option. you may only score in each category once.\n"
        "at the end of the rounds, a winner is determined from the TOTAL section\n"
        "if you win the game you get a yacht for free. now go play lil yachty\n"

    );
    awaitInput();
}

// Game intro
void displayStartGameMessage()
{
    printf("BEGINNING A GAME OF YAHTZEE...\n");
}

// Game scoreboard
void displayScoreboardMessage(YahtzeeGame *game, int player)
{
    int *scoreCard = game->players[player];

    // calculate the total
    int total = 0;
    for (char i = 0; i < 13; i++) {
        total += scoreCard[i];
    }

    printf(
        TITLE
        "### PLAYER %d's SCORE CARD on ROUND %d ###\n"
        "# Ones: %d\n"
        "# Twos: %d\n"
        "# Threes: %d\n"
        "# Fours: %d\n"
        "# Fives: %d\n"
        "# Sixes: %d\n"
        "# Three of a kind: %d\n"
        "# Four of a kind: %d\n"
        "# Full House: %d\n"
        "# Small Straight: %d\n"
        "# Large Straight: %d\n"
        "# Yahtzee: %d\n"
        "# Chance: %d\n"
        "# YOUR TOTAL: %d\n",
        player, game->round, scoreCard[SUM_OF_ONES], scoreCard[SUM_OF_TWOS], scoreCard[SUM_OF_THREES], scoreCard[SUM_OF_FOURS], scoreCard[SUM_OF_FIVES], scoreCard[SUM_OF_SIXES], scoreCard[THREE_OF_A_KIND], scoreCard[FOUR_OF_A_KIND], scoreCard[FULL_HOUSE], scoreCard[SMALL_STRAIGHT], scoreCard[LARGE_STRAIGHT], scoreCard[YAHTZEE], scoreCard[CHANCE], total);
}

// Roll dice
void displayRollingDiceMessage(int round)
{
    printf("Rolling the dice! Round: %d\n", round);
}

// Display the dice values
void displayDiceMessage(YahtzeeGame *game)
{
    printf(
        "\n1. [%d] keep: %s\n"
        "2. [%d] keep: %s\n"
        "3. [%d] keep: %s\n"
        "4. [%d] keep: %s\n"
        "5. [%d] keep: %s\n\n",
        game->dice[0].value, game->dice[0].keepValue ? "YES" : "NO", 
        game->dice[1].value, game->dice[1].keepValue ? "YES" : "NO",  
        game->dice[2].value, game->dice[2].keepValue ? "YES" : "NO", 
        game->dice[3].value, game->dice[3].keepValue ? "YES" : "NO", 
        game->dice[4].value, game->dice[4].keepValue ? "YES" : "NO");
}

// Options after dice roll
void displayRollOptions(YahtzeeGame *game, int player, int *validScoreCard)
{
    int *pScoreCard = game->players[player];
    printf(
        TITLE
        "REMINDER: If no valid roll occured OR the scorecard area is already set, the area will be +0\n\n"
        "### PLAYER %d's VALID SCORE CARD OPTIONS ###\n"
        "# 1. Ones: %d (+%d)\n"
        "# 2. Twos: %d (+%d)\n"
        "# 3. Threes: %d (+%d)\n"
        "# 4. Fours: %d (+%d)\n"
        "# 5. Fives: %d (+%d)\n"
        "# 6. Sixes: %d (+%d)\n"
        "# 7. Three of a kind: %d (+%d)\n"
        "# 8. Four of a kind: %d (+%d)\n"
        "# 9. Full House: %d (+%d)\n"
        "# 10. Small Straight: %d (+%d)\n"
        "# 11. Large Straight: %d (+%d)\n"
        "# 12. Yahtzee: %d (+%d)\n"
        "# 13. Chance: %d (+%d)\n",
        player, 
        pScoreCard[SUM_OF_ONES], !pScoreCard[SUM_OF_ONES] ? validScoreCard[SUM_OF_ONES] : 0, 
        pScoreCard[SUM_OF_TWOS], !pScoreCard[SUM_OF_TWOS] ? validScoreCard[SUM_OF_TWOS] : 0, 
        pScoreCard[SUM_OF_THREES], !pScoreCard[SUM_OF_THREES] ? validScoreCard[SUM_OF_THREES] : 0, 
        pScoreCard[SUM_OF_FOURS], !pScoreCard[SUM_OF_FOURS] ? validScoreCard[SUM_OF_FOURS] : 0, 
        pScoreCard[SUM_OF_FIVES], !pScoreCard[SUM_OF_FIVES] ? validScoreCard[SUM_OF_FIVES] : 0, 
        pScoreCard[SUM_OF_SIXES], !pScoreCard[SUM_OF_SIXES] ? validScoreCard[SUM_OF_SIXES] : 0, 
        pScoreCard[THREE_OF_A_KIND], !pScoreCard[THREE_OF_A_KIND] ? validScoreCard[THREE_OF_A_KIND] : 0, 
        pScoreCard[FOUR_OF_A_KIND], !pScoreCard[FOUR_OF_A_KIND] ? validScoreCard[FOUR_OF_A_KIND] : 0, 
        pScoreCard[FULL_HOUSE], !pScoreCard[FULL_HOUSE] ? validScoreCard[FULL_HOUSE] : 0, 
        pScoreCard[SMALL_STRAIGHT], !pScoreCard[SMALL_STRAIGHT] ? validScoreCard[SMALL_STRAIGHT] : 0, 
        pScoreCard[LARGE_STRAIGHT], !pScoreCard[LARGE_STRAIGHT] ? validScoreCard[LARGE_STRAIGHT] : 0,  
        pScoreCard[YAHTZEE], !pScoreCard[YAHTZEE] ? validScoreCard[YAHTZEE] : 0, 
        pScoreCard[CHANCE], !pScoreCard[CHANCE] ? validScoreCard[CHANCE] : 0
        );
}

// yahtzee dice input should be between 1 and 13
void invalidYahtzeeDiceInput()
{
    printf("Pick something that like you can do man\n");
}

// you win!!!
void displayPlayerWonMessage(int player)
{
    printf("player numba %d!!! you win a yacht! (zee)", player);
}

void displayClearAndTitleMessage() {
    system("clear");
    printf(TITLE);
}

// Y or N response
// Return 1 if y 0 if n
int awaitYorNInput(char *message)
{
    printf("%s\n", message);
    char c = '\0';
    do
    {
        printf("Enter Y or N\n");
        fflush(stdin);
        scanf("%c", &c);
    } while (c != 'Y' && c != 'N' && c != 'y' && c != 'n');

    if (c == 'Y' || c == 'y')
    {
        return 1;
    }
    return 0;
}

// user input selecting one of the roll options
void awaitYahtzeeRollOptionInput(int *input)
{
    printf("Enter a number 1-13\n");
    scanf("%d", input);
}

// get a number 1-5 for the dice, 0 to exit
void awaitNumberInput(int *input)
{
    printf("Enter a number 1-5\n");
    scanf("%d", input);
}

void awaitInput()
{
    printf("\nPress ENTER to continue!\n");
    char input = 0;
    fflush(stdin);
    getchar();
    system("clear");
}

int awaitMenuInput()
{
    int input = 0;
    scanf("%d", &input);
    return input;
}