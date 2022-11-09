#include "log.h"

static FILE *_getLogFile()
{
    static FILE *file;
    if (file == NULL)
    {
        file = fopen("../log.txt", "rw");
    }
    return file;
}

void logAttack(Coordinate coordinate, AttackResult attackResult)
{
    FILE *file = _getLogFile();

    switch (attackResult)
    {
    case HIT:
        fprintf(file, "%d %d HIT\n", coordinate.X, coordinate.Y);
        break;
    case MISS:
        fprintf(file, "%d %d MISS\n", coordinate.X, coordinate.Y);
        break;
    case SANK:
        fprintf(file, "%d %d SANK\n", coordinate.X, coordinate.Y);
        break;
    }
}

void logStats(BattleShipGame *game)
{
    FILE *file = _getLogFile();

    // are you happy Andy!!!! useless struct >:(
    Stats playerStats = {.hits = game->player->score, .misses = game->round - game->player->score, .sinks = game->player->score / SHIPS_PER_PLAYER};
    Stats computerStats = {.hits = game->computer->score, .misses = game->round - game->computer->score, .sinks = game->computer->score / SHIPS_PER_PLAYER};

    fprintf(file, "PLAYER: hits - %d, misses - %d, sinks %d, ratio %lf\n", playerStats.hits, playerStats.misses, playerStats.sinks, (float)playerStats.hits / (float)playerStats.misses);
    fprintf(file, "COMPUTER: hits - %d, misses - %d, sinks %d, ratio %lf\n", computerStats.hits, computerStats.misses, computerStats.sinks, (float)computerStats.hits / (float)computerStats.misses);
    fclose(file);
}