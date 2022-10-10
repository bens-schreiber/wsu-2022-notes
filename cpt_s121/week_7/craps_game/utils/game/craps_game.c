#include "./craps_game.h"

void wagerWon(CrapsGame *game)
{
    game->playerBalance += game->wager;
    game->houseBalance -= game->wager;
    game->wager = 0;
}

void wagerLost(CrapsGame *game)
{
    game->playerBalance -= game->wager;
    game->houseBalance += game->wager;
    game->wager = 0;
}

int doRoundOne(CrapsGame *game)
{
    switch (game->diceSum)
    {

    // Roll a 7 or 11, lose the game.
    case 7:
    case 11:
        loseGame(game);
        return EXIT_GAME;

    // Roll a 2, 3, or 12, win the game.
    case 2:
    case 3:
    case 12:
        winGame(game);
        return EXIT_GAME;

    // Any other roll, proceed to the next round.
    default:
        pointMessage(game->diceSum);

        // Set the point, AKA the goal of the next round of rolls.
        game->crapsPoint = game->diceSum;

        // reset the wager
        game->wager = 0;

        return CONTINUE_GAME;
    }
}

int doRound(CrapsGame *game)
{

    // Ask for a wager if we aren't on the first round
    if (game->round)
    {
        placeWagerMessage(game);
    }

    // Roll the dice and display the result
    rollDiceMessage(game);
    game->diceSum = dsroll();
    showDiceMessage(game->diceSum);

    // If we are on round 1
    if (!game->round)
    {
        return doRoundOne(game);
    }

    // Normal round
    if (game->diceSum == game->crapsPoint)
    {
        winGame(game);
        return EXIT_GAME;
    }

    // Game is over if you roll a 7
    if (game->diceSum == 7)
    {
        loseGame(game);
        return EXIT_GAME;
    }

    // Wager must have been lost
    wagerLost(game);

    // Check the player balance to see if the game is now over.
    if (game->playerBalance < 1)
    {
        return EXIT_GAME;
    }

    wagerLostMessage();

    // Goto the next round.
    return CONTINUE_GAME;
}

void loseGame(CrapsGame *game)
{
    wagerLost(game);

    // Print to console the player has lost.
    youLoseGameMessage();
}

void winGame(CrapsGame *game)
{
    wagerWon(game);

    // Print to console the player has won
    youWinGameMessage();
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
        nextGameMessage();
    }
    else
    {
        gameRulesMessage();
        // Display the balance
        houseBalanceMessage(game->houseBalance);

        // Wait for confirmation (user input) to continue
        awaitInput();
    }

    // Ask to place a initial wager.
    scoreboardMessage(game);
    placeWagerMessage(game);

    // Begin the game.
    // Do rounds until doRound returns EXIT_GAME,
    while (doRound(game))
    {
        game->round++;

        // At the start of each round, wait for ENTER key and then display
        // scoreboard
        awaitScoreboard(game);
    }

    // Game is over if the player is out of money
    if (game->playerBalance < 1)
    {

        // Display that the player lost because they're broke
        youLoseBecauseBrokeMessage();

        // Display the player has lost the game
        loseGame(game);

        // Exit the game entirely.
        return EXIT_GAME;
    }

    // Display that the current game is over.
    exitMessage();
    awaitInput();

    // The game will continue until the player is broke
    return CONTINUE_GAME;
}