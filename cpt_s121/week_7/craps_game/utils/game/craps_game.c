#include "./craps_game.h"

void loseGame(CrapsGame *game)
{
    // Give the money to the house.
    game->playerBalance -= game->wager;
    game->houseBalance += game->wager;
    game->wager = 0;
    youLoseGameMessage();
}

void winGame(CrapsGame *game)
{
    // Give the money to the player.
    game->playerBalance += game->wager;
    game->houseBalance -= game->wager;
    game->wager = 0;
    youWinGameMessage();
}

void placeWager(CrapsGame *game)
{
    placeWagerMessage(&game->wager);
    wagerPlacedMessage(game->wager);
    game->playerBalance -= game->wager;
}

int doRound(CrapsGame *game)
{

    // Add to the wager if we aren't on the first round
    if (game->round)
    {
        placeWager(game);
        confirmMessageTitle(game);
    }

    // Roll the dice and display the result
    rollDiceMessage(game);
    game->diceSum = dsroll();
    showDiceMessage(game->diceSum);

    // If we are on round 1
    // Roll a 7 or 11, lose the game.
    // Roll a 2, 3, or 12, win the game.
    // Any other roll, proceed to the next round.
    if (!game->round)
    {
        switch (game->diceSum)
        {
        case 7:
        case 11:
            loseGame(game);
            return EXIT_GAME;

        case 2:
        case 3:
        case 12:
            winGame(game);
            return CONTINUE_GAME;

        default:
            pointMessage(game->diceSum);

            // Set the point, AKA the goal of the next round of rolls.
            game->crapsPoint = game->diceSum;

            // Reset the wager
            game->playerBalance += game->wager;
            game->wager = 0;

            return CONTINUE_GAME;
        }
    }

    // Normal round
    if (game->diceSum == game->crapsPoint)
    {
        winGame(game);
        return EXIT_GAME;
    }

    if (game->diceSum == 7)
    {
        loseGame(game);
        return EXIT_GAME;
    }

    // Reset the wager
    game->playerBalance += game->wager;
    game->wager = 0;
    resetWagerMessage();

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
    confirmMessage();

    // Begin the game.
    while (doRound(&game))
    {
        game.round++;
        confirmMessageTitle(&game);
    }

    exitMessage();

    // TODO: play again
    return 0;
}