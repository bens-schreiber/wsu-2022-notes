# pragma once
# include <stdlib.h>

// love saving me bits and bytes :)
typedef union {
    unsigned char roll;
    unsigned char rollAgain;
} YahtzeeDie;

// Roll a singular yahtzee die.
void _yahtzeeDieRoll(YahtzeeDie *die);

// Roll 5 yahtzee dice
void yahtzeeDiceRoll(YahtzeeDie dice[5]);
