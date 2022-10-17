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
}

void yahtzeeDiceReset(YahtzeeDie dice[YAHTZEE_DIE_COUNT])
{
    for (int i = 0; i < YAHTZEE_DIE_COUNT - 1; i++)
    {
        dice[i].keepValue = 0;
        dice->value = 0;
    }
}