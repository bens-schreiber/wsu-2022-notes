#pragma once
#include "./player/player_types.h"

// [player] - The main player of the game
// [computer] - The enemy. Has a blank gameBoard that is the board the player sees.
// [round] - Keeps track of how many rounds the game has gone through
typedef struct
{
    BattleShipPlayer *player;
    BattleShipPlayer *computer;
    unsigned char round;
} BattleShipGame;

// Outcomes of an attack
typedef enum
{
    MISS,
    HIT,
    SANK
} AttackResult;