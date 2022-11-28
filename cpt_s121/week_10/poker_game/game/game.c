#include "game.h"

void startPokerGame() {

    logClear();

    PokerGame *game = malloc(sizeof(PokerGame));
    *game = (PokerGame) {
        .dealer = (PokerPlayer) {.money = POKER_STARTING_MONEY_AMOUNT, .bet = 0},
        .deck = {0}
    };

    // Prepare the deck and deal
    deckInit(&game->deck);
    deckShuffle(&game->deck);
    pokerGameDeal(game);

    // place bets
    int input = 0;
    for (int i = 0; i < POKER_PLAYER_AMOUNT; ++i) {
        game->player[i].money = POKER_STARTING_MONEY_AMOUNT;
        while (1) {
            logAskBet(i, game->player[i].money);
            input = getIntInput();
            if (input <= game->player[i].money) {
                game->player[i].bet = input;
                break;
            }
        }
        logClear();
    }

    free(game);
    return;
}

static void dealPlayer(PokerPlayer *player, Deck *deck, int *deckIndex) {
    for (int i = 0; i < POKER_CARD_AMOUNT; i++) {
        player->hand[i] = deck->deck[*deckIndex];
        (*deckIndex)++;
    }
}

void pokerGameDeal(PokerGame *game) {
    int deckIndex = 0;

    // deal to the dealer
    dealPlayer(&game->dealer, &game->deck, &deckIndex);

    // deal to each player
    for (int i = 0; i < POKER_PLAYER_AMOUNT; ++i) {
        dealPlayer(&game->player[i], &game->deck, &deckIndex);
    }
}
