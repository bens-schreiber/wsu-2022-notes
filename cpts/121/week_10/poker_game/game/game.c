#include "game.h"

PokerGame *pokerGame() {
    PokerGame *game = malloc(sizeof(PokerGame));
     *game = (PokerGame) {
        .dealer = (PokerPlayer) {.money = POKER_STARTING_MONEY_AMOUNT, .bet = 0},
        .deck = {0}
    };
    for (int i = 0; i < POKER_PLAYER_AMOUNT; ++i) {
        game->player[i].money = POKER_STARTING_MONEY_AMOUNT;
    }
    return game;
}

void startPokerGame(PokerGame *game) {

    logClear();

    pokerGamePlaceBets(game);

    // Prepare the deck and deal
    deckInit(&game->deck);
    deckShuffle(&game->deck);
    pokerGameDeal(game);

    if (DEBUG_SHOW_DEALER) {
        logPlayerHand(&game->dealer);
    }

    pokerGameFindWinner(game);
    getInput();
}

void pokerGamePlaceBets(PokerGame *game) {
    // place bets
    int input = 0;
    for (int i = 0; i < POKER_PLAYER_AMOUNT; ++i) {
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
}

void pokerGameDeal(PokerGame *game) {
    int deckIndex = 0;

    // deal to the dealer
    dealPlayer(&game->dealer, &game->deck, &deckIndex);

    // // deal to each player
    for (int i = 0; i < POKER_PLAYER_AMOUNT; ++i) {
        dealPlayer(&game->player[i], &game->deck, &deckIndex);
        pokerGameReplacePlayerCards(game, i, &deckIndex);
        getInput();
    }
}

PokerEvalHand pokerPlayerEvaluateHand(PokerPlayer *player) {

    // Frequency table / hash map of values
    CardValue valueMap[CARD_VALUE_AMOUNT] = {0};
    int handSum = 0;
    int flushCounter = 0;
    for (int i = 0; i < POKER_HAND_AMOUNT; ++i) {
        handSum += player->hand[i].value;
        valueMap[player->hand[i].value]++;

        if (i == 0 || player->hand[i].face == player->hand[i - 1].face) {
            ++flushCounter;
        }
    }

    PokerEvalHand highest = {.hand = 0, .value = 0};
    int straightCounter = 0;
    for (int i = 0; i < CARD_VALUE_AMOUNT; ++i) {
        
        CardValue value = i;
        int frequency = valueMap[i];

        // Skip 0 frequencies
        if (frequency == 0) {
            straightCounter = 0;
            continue;
        }

        // check for straight
        if (++straightCounter == POKER_HAND_AMOUNT) {
            return (PokerEvalHand) {.hand = STRAIGHT, .value = value};
        }

        // Only a straight is higher than a flush
        // Only check for straights if we know there is a flush.
        if (flushCounter == POKER_HAND_AMOUNT) {
            highest = (PokerEvalHand) {.hand = FLUSH, .value = value};
            continue;
        }

        // Check for full house
        if (frequency == 3 && valueMap[(handSum - 3 * value) / 2] == 2) {
            return (PokerEvalHand) {.hand = FULL_HOUSE, .value = value};
        }

        // set the working highest as a high card, and increment the straight counter
        PokerEvalHand workingHighest = (PokerEvalHand) {.hand = HIGH_CARD, .value = value };

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

void pokerGameFindWinner(PokerGame *game) {
    PokerEvalHand dealer = pokerPlayerEvaluateHand(&game->dealer);
    PokerEvalHand comparator;
    char noWinners = 1;
    for (int i = 0; i < POKER_PLAYER_AMOUNT; ++i) {
        comparator = pokerPlayerEvaluateHand(&game->player[i]);
        if (comparator.hand > dealer.hand || (comparator.hand == dealer.hand) && comparator.value > dealer.value ) {
            logPlayerWins(i, game->player[i].bet);
            game->player[i].money += game->player[i].bet;
            game->dealer.money -= game->player[i].bet;
            noWinners = 0;
        } else {
            logPlayerLost(i, game->player[i].bet);
            game->player[i].money -= game->player[i].bet;
            game->dealer.money += game->player[i].bet;
        }
    }

    if (noWinners) {
        logDealerWins();
    }
}