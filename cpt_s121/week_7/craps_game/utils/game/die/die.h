#include <stdlib.h>

// A single die
typedef struct
{
    int side;
} Die;

typedef struct
{
    Die *die1;
    Die *die2;
} Die_Set;

// Roll a die and set its side value
void droll(Die *die)
{
    die->side = rand() % 6 + 1;
}

// Roll two dice and set both of their side values
void droll_two(Die_Set *die_set)
{
    droll(die_set->die1);
    droll(die_set->die2);
}