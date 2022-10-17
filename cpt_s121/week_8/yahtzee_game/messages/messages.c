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
    printf("\nthe rules are simple: YACHT-ZIE!\n");
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
        "### PLAYER %d's SCORE CARD ###\n"
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
        player, scoreCard[SUM_OF_ONES], scoreCard[SUM_OF_TWOS], scoreCard[SUM_OF_THREES], scoreCard[SUM_OF_FOURS], scoreCard[SUM_OF_FIVES], scoreCard[SUM_OF_SIXES], scoreCard[THREE_OF_A_KIND], scoreCard[FOUR_OF_A_KIND], scoreCard[FULL_HOUSE], scoreCard[SMALL_STRAIGHT], scoreCard[LARGE_STRAIGHT], scoreCard[YAHTZEE], scoreCard[CHANCE], total);
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
        "\n1. [%d]\n"
        "2. [%d]\n"
        "3. [%d]\n"
        "4. [%d]\n"
        "5. [%d]\n\n",
        game->dice[0].value, game->dice[1].value, game->dice[2].value, game->dice[3].value, game->dice[4].value);
}

// Options after dice roll
void displayRollOptions(int player, int *scoreCard)
{
    printf(
        "YAHTZEE By Benjamin Schreiber\n\n"
        "### YOUR VALID OPTIONS CARD ###\n"
        "# 1. Ones: %d\n"
        "# 2. Twos: %d\n"
        "# 3. Threes: %d\n"
        "# 4. Fours: %d\n"
        "# 5. Fives: %d\n"
        "# 6. Sixes: %d\n"
        "# 7. Three of a kind: %d\n"
        "# 8. Four of a kind: %d\n"
        "# 9. Full House: %d\n"
        "# 10. Small Straight: %d\n"
        "# 11. Large Straight: %d\n"
        "# 12. Yahtzee: %d\n"
        "# 13. Chance: %d\n",
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