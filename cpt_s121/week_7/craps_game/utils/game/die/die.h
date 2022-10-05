#include <stdlib.h>

// A set of die
typedef struct
{
    int die1;
    int die2;
} DieSet;

// Roll a die and set its side value; return the value it rolled
int droll()
{
    return rand() % 6 + 1;
}

// Roll two dice and set both of their side values; return sum
int dsroll(DieSet dieSet)
{
    dieSet.die1 = droll();
    dieSet.die2 = droll();
    return dieSet.die1 + dieSet.die2;
}