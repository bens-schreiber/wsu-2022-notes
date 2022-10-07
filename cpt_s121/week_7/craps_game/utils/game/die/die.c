#include "die.h"

int droll()
{
    return rand() % 6 + 1;
}

int dsroll()
{
    return droll() + droll();
}