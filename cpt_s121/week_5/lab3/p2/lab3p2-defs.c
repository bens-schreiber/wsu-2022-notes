#include "lab3p2-defs.h"

void outInstructions()
{
    printf("Enter the values for the projectile (theta, distance, velocity)\n");
}

static double inputDouble(char *label)
{
    double d;
    printf("%s: ", label);
    scanf("%lf", &d);
    return d;
}

void getInput(Projectile *projectile)
{
    projectile->theta = inputDouble("Theta");
    projectile->distance = inputDouble("Distance");
    projectile->velocity = inputDouble("Velocity");
}

double calculateTime(Projectile *projectile)
{
    Projectile p = *projectile;
    return (p.distance) / (p.velocity * cos(p.theta));
}

double calculateHeight(Projectile *projectile, double time)
{
    Projectile p = *projectile;
    return p.velocity * sin(p.theta) * time - ((G * time * time) / 2);
}

void outResults(double time, double height)
{
    printf("Time: %lf \nHeight: %lf", time, height);
}