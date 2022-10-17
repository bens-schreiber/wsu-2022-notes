#include "./dice.h"

void _yahtzeeDieRoll(YahtzeeDie *die)
{
    if (!die->keepValue)
    {
        die->value = rand() % 6 + 1;
    }
}

void yahtzeeDiceRoll(YahtzeeDie dice[5])
{
    for (int i = 0; i < YAHTZEE_DIE_COUNT; i++)
    {
        _yahtzeeDieRoll(&dice[i]);
    }

    // RIG DICE VALUES HERE!!!
    // dice[0].value = 1;
    // dice[1].value = 2;
    // dice[2].value = 3;
    // dice[3].value = 4;
    // dice[4].value = 5;

}

void yahtzeeDiceReset(YahtzeeDie dice[YAHTZEE_DIE_COUNT])
{
    for (int i = 0; i < YAHTZEE_DIE_COUNT - 1; i++)
    {
        dice[i].keepValue = 0;
        dice->value = 0;
    }
}