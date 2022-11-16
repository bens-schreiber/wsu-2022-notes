#include "game.h"

void startPokerGame() {

    // malloc this
    PokerGame game = {
        .player = (PokerPlayer) {.money = POKER_STARTING_MONEY_AMOUNT},
        .dealer = (PokerPlayer) {.money = POKER_STARTING_MONEY_AMOUNT},
        .deck = {0}
    };

    deckInit(&game.deck);
    deckShuffle(&game.deck);
    pokerGameDeal(&game);
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
        dealPlayer(&game->player[i], &game->deck, deckIndex);
    }
}
