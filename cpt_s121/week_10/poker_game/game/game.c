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
    for (int i = 0; i < POKER_HAND_AMOUNT; i++) {
        player->hand[i] = deck->deck[*deckIndex];
        (*deckIndex)++;
    }
}

void pokerGameReplacePlayerCards(PokerGame *game, int playerIndex, int *deckIndex) {
    // show player their cards
    logPlayerHand(&game->player[playerIndex]);

    // let player select cards to discard and draw
    logAskDiscardAmount(playerIndex);
    int size = 0;
    int *inputs = getIntInputs(POKER_HAND_AMOUNT, &size);
    if (size == 0) {
        return;
    }
    for (int i = 0; i < size; ++i) {
        game->player[playerIndex].hand[inputs[i]] = game->deck.deck[*deckIndex];
        (*deckIndex)++;
    }

    logPlayerHand(&game->player[playerIndex]);
    

    free(inputs);

    // replace

}

void pokerGameDeal(PokerGame *game) {
    int deckIndex = 0;

    // deal to the dealer
    dealPlayer(&game->dealer, &game->deck, &deckIndex);

    // deal to each player
    for (int i = 0; i < POKER_PLAYER_AMOUNT; ++i) {
        dealPlayer(&game->player[i], &game->deck, &deckIndex);
        pokerGameReplacePlayerCards(game, i, &deckIndex);
        getInput();
    }
}

void pokerPlayerEvaluateHand(PokerPlayer *player) {
    CardValue valueMap[CARD_VALUE_AMOUNT] = {};
    int handSum = 0;
    for (int i = 0; i < POKER_HAND_AMOUNT; ++i) {
        handSum += player->hand->value;
        valueMap[player->hand->value]++;
    }

    PokerEvalHand highest = {.hand = 0, .value = 0};

    // Find straights
    int straightCounter = 0;
    
    for (int i = 0; i < CARD_VALUE_AMOUNT; ++i) {
        CardValue value = i;
        int frequency = valueMap[i];

        // Skip 0 frequencies
        if (frequency == 0) {
            straightCounter = 0;
            continue;
        }

        // set the working highest as a high card, and increment the straight counter
        PokerEvalHand workingHighest = (PokerEvalHand) {.hand = HIGH_CARD, .value = value };

        // check for straight
        if (++straightCounter == 5) {
            workingHighest = (PokerEvalHand) {.hand = STRAIGHT, .value = value};
        }

        // Check for flush. At this time, flush is the highest, so just return the flush.
        if (frequency == 3 && valueMap[(handSum - 3 * value) / 2] == 2) {
            return (PokerEvalHand) {.hand = FLUSH, .value = value};
        }

        // pair, three of a kind, four of a kind
        switch (frequency) {
            case 2:
                workingHighest = (PokerEvalHand) {.hand = PAIR, .value = value};
                break;
            case 3:
                workingHighest = (PokerEvalHand) {.hand = THREE_OF_A_KIND, .value = value};
                break;
            case 4:
                workingHighest = (PokerEvalHand) {.hand = FOUR_OF_A_KIND, .value = value};
                break;
        }

        // Replace highing hand;
        if (workingHighest.hand > highest.hand) {
            highest = workingHighest;
            continue;
        }
        if (workingHighest.hand == highest.hand && workingHighest.value > highest.value) {
            highest = workingHighest;
            continue;
        }
    }
    return highest;
}