#define G 32.17
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct Projectile {
    double theta;
    double distance;
    double velocity;
} Projectile;

void outInstructions();

static double inputDouble(char *label);

void getInput(Projectile *projectile);

double calculateTime(Projectile *projectile);

double calculateHeight(Projectile *projectile, double time);

void outResults(double time, double height);

