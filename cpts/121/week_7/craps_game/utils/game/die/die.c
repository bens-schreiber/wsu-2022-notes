#include "die.h"

int _droll()
{
    return rand() % 6 + 1;
}

int dsroll()
{
    return _droll() + _droll();
}