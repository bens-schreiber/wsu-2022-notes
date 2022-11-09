#pragma once
#include "../utils.h"
#include "../game/game_types.h"
#include "../messages/messages.h"

typedef struct {
    unsigned char hits, misses, sinks;
} Stats;

void logAttack(Coordinate coordinate, AttackResult attackResult);

static FILE* _getLogFile();

void logStats(BattleShipGame *game);