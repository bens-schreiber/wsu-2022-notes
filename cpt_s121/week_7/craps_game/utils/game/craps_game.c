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
            return EXIT_GAME;

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

    // Wager lost, reset.
    game->houseBalance += game->wager;
    game->wager = 0;
    if (game->playerBalance < 1) {
        return EXIT_GAME;
    }

    resetWagerMessage();

    return CONTINUE_GAME;
}

int crapsGame(CrapsGame *game)
{
    // Since the CrapsGame struct is maintained in memory throughout programs life,
    // this may or may not be the first time the user is playing the game.
    // Check the round to see if it is the first time. Reset values if it isn't,
    // display rules if it is.
    if (game->round > 0)
    {
        game->round = 0;
        game->crapsPoint = 0;
        anotherGameMessage();
    }
    else
    {
        gameRulesMessage();
        // Display the balance
        houseBalanceMessage(game->houseBalance);

        // Wait for confirmation (user input) to continue
        confirmMessage();
    }

    // Ask to place a initial wager.
    titleMessage(game);
    placeWager(game);
    confirmMessage();

    // Begin the game.
    while (doRound(game))
    {
        game->round++;
        confirmMessageTitle(game);
    }

    // Game is over if the player is out of money
    if (game->playerBalance < 1) {
        youLoseBecauseBrokeMessage();
        loseGame(game);
        return EXIT_GAME;
    }

    exitMessage();
    confirmMessage();

    // TODO: exit
    return CONTINUE_GAME;
}