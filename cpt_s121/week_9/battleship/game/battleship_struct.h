#pragma once

typedef struct
{
    unsigned int hitPoints;
    const unsigned int player;
    const char graphic;
    const char *name;
} BattleShip;


// Different battleship possibilities
#define BATTLE_SHIP_CARRIER(player) \
    (BattleShip)                    \
    {                               \
        .hitPoints = 5,             \
        .graphic = '#',             \
        .name = "CARRIER",          \
        .player = player            \
    }

#define BATTLE_SHIP_BATTLESHIP(player) \
    (BattleShip)                       \
    {                                  \
        .hitPoints = 4,                \
        .graphic = '@',                \
        .name = "BATTLESHIP",          \
        .player = player               \
    }

#define BATTLE_SHIP_CRUISER(player) \
    (BattleShip)                    \
    {                               \
        .hitPoints = 3,             \
        .graphic = '%',             \
        .name = "CRUISER",          \
        .player = player            \
    }

#define BATTLE_SHIP_SUBMARINE(player) \
    (BattleShip)                      \
    {                                 \
        .hitPoints = 3,               \
        .graphic = '$',               \
        .name = "SUBMARINE",          \
        .player = player              \
    }

#define BATTLE_SHIP_DESTROYER(player) \
    (BattleShip)                      \
    {                                 \
        .hitPoints = 2,               \
        .graphic = '#',               \
        .name = "DESTROYER",          \
        .player = player              \
    }