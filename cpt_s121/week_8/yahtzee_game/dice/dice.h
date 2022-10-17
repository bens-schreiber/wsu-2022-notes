# pragma once
# include <stdlib.h>
#define YAHTZEE_DIE_COUNT 5

typedef struct {
    unsigned char value;
    unsigned char keepValue;
} YahtzeeDie;

// Roll a singular yahtzee die.
void _yahtzeeDieRoll(YahtzeeDie *die);

// Roll 5 yahtzee dice
void yahtzeeDiceRoll(YahtzeeDie dice[YAHTZEE_DIE_COUNT]);
