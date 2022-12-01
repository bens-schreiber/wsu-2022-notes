#include "log.h"

void logClear() {
    system("clear");
}

int getIntInput() {
    int input = 0;
    printf("\nEnter a value: ");
    scanf("%d", &input);
    return input;
}

int *getIntInputs(int maxSize, int *actualSize) {
    char s[maxSize * 2];
    scanf("%s", s);
    if (!strcasecmp(s, "N")) return NULL;
    int *ret = malloc(sizeof(int) * maxSize);
    char *sp = strtok(s, ",");
    for (int i = 0; i < maxSize; ++i) {
        if (sp == NULL) break;
        ret[i] = atoi(sp);
        sp = strtok(NULL, ",");
        (*actualSize)++;
    }
    return ret;
}

void getInput() {
    printf("\nPress ENTER to continue!\n");
    char input = 0;
    fflush(stdin);
    getchar();
    logClear();
}

void logMenu() {
    logClear();
    printf(
        "Poker by Benjamin Schreiber \n\n"
        "# Press 1 to view the rules \n"
        "# Press 2 to start Poker \n"
        "# Press 3 to run poker hand evaluation tests (set in tests/tests.c) \n"
        "# Press 4 to exit \n"
    );
}

void logRules() {
    printf("these are the roools....\n");
}

void logAskBet(int player, int balance) {
    printf("[Player %d] place your bet! (your balance is %d)", player, balance);
}

void logAskDiscardAmount(int player) {
    printf("\n");
    printf("[Player %d] enter the indexes you want to discard (a,b,c or N): ", player);
}


#define CARD_HEIGHT 7
#define CARD_WIDTH 9
#define DISPLAY_SPACING 2

// A players hand always consists of POKER_CARD_AMOUNT number of cards.
// Cards will always be laid out in this manner (F = face, V = value, I = index):
//  _____   1
// |     |  2
// |  F  |  3
// |  V  |  4
// |     |  5
//  -----   6
//    I     7
// 1234567
// 7x7 in size
// After each card, there will be 2 units of spacing
// 9x7 in size
// Therefore, the final size to display POKER_CARD_AMOUNT of cards is (9*POKER_CARD_AMOUNT)x7
static void placeCardInHand(char handDisplay[][CARD_WIDTH*POKER_HAND_AMOUNT], Card card, int cardNum) {
    char cardDisplay[CARD_HEIGHT][CARD_WIDTH] = {
        {' ', '_', '_', '_', '_', '_', ' ', ' ', ' '},
        {'|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' '},
        {'|', ' ', ' ', 'F', ' ', ' ', '|', ' ', ' '},
        {'|', ' ', ' ', 'V', ' ', ' ', '|', ' ', ' '},
        {'|', '_', '_', '_', '_', '_', '|', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', 'I', ' ', ' ', ' ', ' ', ' '}
    };

    char F;
    switch (card.face) {
        case HEART:
            F = 'H';
            break;
        case DIAMOND:
            F = 'D';
            break;
        case CLUB:
            F = 'C';
            break;
        case SPADE:
            F = 'S';
            break;
    }

    char V;
    switch (card.value) {
        case ACE:
            V = 'A';
            break;
        case TEN:
            V = 'T';
            break;
        case JACK:
            V = 'J';
            break;
        case QUEEN:
            V = 'Q';
            break;
        case KING:
            V = 'K';
            break;
        default:
            V = '\0';
    }

    cardDisplay[2][3] = F;
    cardDisplay[3][3] = V == '\0' ? '0' + (card.value + 1) : V;
    cardDisplay[6][3] = '0' + cardNum;

    for (int row = 0; row < CARD_HEIGHT; ++row) {
        for (int col = 0; col < CARD_WIDTH; ++col) {
            handDisplay[row][col + (cardNum * CARD_WIDTH)] = cardDisplay[row][col];
        }
    }
}

void logPlayerHand(PokerPlayer *player) {
    char handDisplay[CARD_HEIGHT][CARD_WIDTH*POKER_HAND_AMOUNT] = {};
    for (int i = 0; i < POKER_HAND_AMOUNT; ++i) {
        placeCardInHand(handDisplay, player->hand[i], i);
    }

    for (int row = 0; row < CARD_HEIGHT; ++row) {
        for (int col = 0; col < CARD_WIDTH*POKER_HAND_AMOUNT; ++col) {
            printf("%c", handDisplay[row][col]);
        }
        printf("\n");
    }

}

void logPlayerWins(int player) {
    printf("[Player %d] beat the dealer!", player);
}