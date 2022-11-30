#include "game.h"

void startPokerGame() {

    logClear();

    PokerGame *game = malloc(sizeof(PokerGame));
    *game = (PokerGame) {
        .dealer = (PokerPlayer) {.money = POKER_STARTING_MONEY_AMOUNT, .bet = 0},
        .deck = {0}
    };

    // Place bets and deal
    pokerGamePlaceBets(game);

    // Prepare the deck and deal
    deckInit(&game->deck);
    deckShuffle(&game->deck);
    pokerGameDeal(game);

    free(game);
    return;
}

void pokerGamePlaceBets(PokerGame *game) {
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
}

static void dealPlayer(PokerPlayer *player, Deck *deck, int *deckIndex) {
    for (int i = 0; i < POKER_CARD_AMOUNT; i++) {
        player->hand[i] = deck->deck[*deckIndex];
        (*deckIndex)++;
    }
}

void pokerPlayerReplaceCards(PokerPlayer *player, int player, int *deckIndex) {
    // show player their cards
    logPlayerHand(player);

    // let player select cards to discard and draw
    logAskDiscardAmount(player)

    // replace up to 5 cards
}

void pokerGameDeal(PokerGame *game) {
    int deckIndex = 0;

    // deal to the dealer
    dealPlayer(&game->dealer, &game->deck, &deckIndex);

    // deal to each player
    for (int i = 0; i < POKER_PLAYER_AMOUNT; ++i) {
        dealPlayer(&game->player[i], &game->deck, &deckIndex);
        pokerPlayerReplaceCards(&game->player[i], i, &deckIndex);
        getInput();
    }
}
