#include <stdlib.h>

// Roll a die and return the value it rolled
int droll()
{
    return rand() % 6 + 1;
}

// Roll two dice, return sum
int dsroll()
{
    return droll() + droll();
}