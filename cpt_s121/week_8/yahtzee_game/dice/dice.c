# include "./dice.h"

void _yahtzeeDieRoll(YahtzeeDie *die) {
    if (die->rollAgain) {
        die->roll = rand() % 6 + 1;
    }
}

// Roll 5 yahtzee dice
void yahtzeeDiceRoll(YahtzeeDie dice[5]) {
    for (int i = 0; i < 5; i++) {
        _yahtzeeDieRoll(&dice[i]);
    }
}