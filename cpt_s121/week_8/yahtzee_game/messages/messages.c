#include "messages.h"

// Menu options
void displayMenuMessage()
{
    printf(
        "########################################\n"
        "Welcome to Yahtzee by Benjamin Schreiber\n"
        "Enter 1 to view the rules\n"
        "Enter 2 to start the game\n"
        "Enter 3 to exit\n"
        "########################################\n");
}

// Game rules
void displayGameRulesMessage()
{
    printf("the rules are simple: YACHT-ZIE!\n");
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
    printf(
        "YAHTZEE By Benjamin Schreiber\n\n"
        "### YOUR SCORE CARD ###\n"
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
        "# Chance: %d\n",
        scoreCard[SUM_OF_ONES], scoreCard[SUM_OF_TWOS], scoreCard[SUM_OF_THREES], scoreCard[SUM_OF_FOURS], scoreCard[SUM_OF_FIVES], scoreCard[SUM_OF_SIXES], scoreCard[THREE_OF_A_KIND], scoreCard[FOUR_OF_A_KIND], scoreCard[FULL_HOUSE], scoreCard[SMALL_STRAIGHT], scoreCard[LARGE_STRAIGHT], scoreCard[YAHTZEE], scoreCard[CHANCE]);
}

// Roll dice
// [firstRoll] if not on first roll, display a slightly different message
void displayRollingDiceMessage(int firstRoll)
{
    if (firstRoll)
    {
        printf("Rolling the dice!\n");
        return;
    }
    printf("Rolling the dice again!\n");
}

// Display the dice values
void displayDiceMessage(YahtzeeGame *game)
{
    printf(
        "YOUR ROLL!\n"
        " _\n"
        "[%d] - 1\n"
        " _\n\n"
        " _\n"
        "[%d] - 2\n"
        " _\n\n"
        " _\n"
        "[%d] - 3\n"
        " _\n\n"
        " _\n"
        "[%d] - 4\n"
        " _\n\n"
        " _\n"
        "[%d] - 5\n"
        " _\n\n",
        game->dice[0].value, game->dice[1].value, game->dice[2].value, game->dice[3].value, game->dice[4].value);
}

// Options after dice roll
void displayRollOptions(YahtzeeGame *game, int player, int *scoreCardOpt)
{
    int *scoreCard = game->players[player];
    printf(
        "YAHTZEE By Benjamin Schreiber\n\n"
        "### YOUR VALID OPTIONS CARD ###\n"
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
        "# Chance: %d\n",
        scoreCard[SUM_OF_ONES], scoreCard[SUM_OF_TWOS], scoreCard[SUM_OF_THREES], scoreCard[SUM_OF_FOURS], scoreCard[SUM_OF_FIVES], scoreCard[SUM_OF_SIXES], scoreCard[THREE_OF_A_KIND], scoreCard[FOUR_OF_A_KIND], scoreCard[FULL_HOUSE], scoreCard[SMALL_STRAIGHT], scoreCard[LARGE_STRAIGHT], scoreCard[YAHTZEE], scoreCard[CHANCE]);
}

// yahtzee dice input should be between 1 and 13
void invalidYahtzeeDiceInput() 
{
    printf("Pick something that like you can do man\n");
}

// you win!!!
void displayPlayerWonMessage(int player)
{
    printf("you win a yacht! (zee)");
}

// Y or N response
// Return 1 if y 0 if n
int awaitYorNInput(char *message)
{
    char c = '\0';
    do {
        printf("%s\n\n Enter Y or N\n", message);
        scanf("%c", &c);
    } while (c != 'Y' || c != 'N' || c != 'y' || c != 'n');
    if (c == 'Y' || c == 'y') {
        return 1;
    }
    return 0;
}

// user input selecting one of the roll options
int awaitYahtzeeRollOptionInput()
{
    int input = 0;
    printf("Enter a number 1-13\n");
    scanf("%d", &input);
    return input;
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