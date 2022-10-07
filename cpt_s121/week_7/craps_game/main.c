#include "./utils/game/craps_game.h"

int main(int argc, char const *argv[])
{
    CrapsGame game = {
        .houseBalance = 10000,
        .playerBalance = 1000,
        .round = 0,
        .wager = 0,
        .diceSum = 0,
        .crapsPoint = 0
    };

    while(crapsGame(&game));
    return 0;
}
