#include "./craps_game.h"

void placeWager(CrapsGame *game)
{
    placeWagerMessage(&game->wager);
    wagerPlacedMessage(game->wager);
}

void addToWager(CrapsGame *game)
{
    int add;
    addToWagerMessage(add);
    if (add != 0) {
        game->wager += add;
        wagerPlacedMessage(game->wager);
    }
}

int doRound(CrapsGame *game)
{

    // Add to the wager if we aren't on the first round
    if (game->round) {
        addToWager(game);
    }

    // Roll the dice and display the result
    rollDiceMessage();
    game->diceSum = dsroll();
    showDiceMessage(game->diceSum);

    // If we are on round 1
    if (!game->round)
    {
        switch (game->diceSum)
        {
        case 7:
        case 11:
            youWinGameMessage();
            game->playerBalance += game->wager;
            return EXIT_GAME;

        case 2:
        case 3:
        case 12:
            youLoseGameMessage();
            game->playerBalance -= game->wager;
            game->houseBalance += game->wager;
            return CONTINUE_GAME;

        default:
            pointMessage(game->diceSum);
            game->crapsPoint = game->diceSum;
            return CONTINUE_GAME;
        }
    }

    // Normal round
    if (game->diceSum == game->crapsPoint)
    {
        youWinGameMessage();
        return EXIT_GAME;
    }

    if (game->diceSum == 7)
    {
        youLoseGameMessage();
        return EXIT_GAME;
    }

    return CONTINUE_GAME;
}

int crapsGame()
{

    // Display the rules of how the game is played.
    gameRulesMessage();

    // Initialize balance as an arbitrary large number, and display that balance.
    houseBalanceMessage(INT16_MAX);

    // Wait for confirmation (user input) to continue
    confirmMessage();

    CrapsGame game = {
        .wager = 0,
        .diceSum = 0,
        .houseBalance = INT16_MAX,
        .round = 0,
        .playerBalance = 1000,
        .crapsPoint = 0};


    // Ask to place a initial wager.
    placeWager(&game);

    // Begin the game.
    int round = 0;
    while (doRound(&game));

    exitMessage();

    // TODO: play again
    return 0;
}