#pragma once
#include "./game/battleship_struct.h"

#define BOARD_ROWS 10
#define BOARD_COLUMNS 10
#define SHIPS_PER_PLAYER 5

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

typedef struct
{
    const unsigned int X;
    const unsigned int Y;
} Coordinate;

typedef enum
{
    UP,
    DOWN,
    LEFT,
    RIGHT
} Direction;