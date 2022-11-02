#pragma once

typedef struct
{
    unsigned int hitPoints;
    const char graphic;
    const char *name;
} BattleShip;

// Different battleship possibilities
#define BATTLE_SHIP_CARRIER \
    (BattleShip)            \
    {                       \
        .hitPoints = 5,     \
        .graphic = '#',     \
        .name = "CARRIER",  \
    }

#define BATTLE_SHIP_BATTLESHIP \
    (BattleShip)               \
    {                          \
        .hitPoints = 4,        \
        .graphic = '@',        \
        .name = "BATTLESHIP",  \
    }

#define BATTLE_SHIP_CRUISER \
    (BattleShip)            \
    {                       \
        .hitPoints = 3,     \
        .graphic = '%',     \
        .name = "CRUISER",  \
    }

#define BATTLE_SHIP_SUBMARINE \
    (BattleShip)              \
    {                         \
        .hitPoints = 3,       \
        .graphic = '$',       \
        .name = "SUBMARINE",  \
    }

#define BATTLE_SHIP_DESTROYER \
    (BattleShip)              \
    {                         \
        .hitPoints = 2,       \
        .graphic = '#',       \
        .name = "DESTROYER",  \
    }