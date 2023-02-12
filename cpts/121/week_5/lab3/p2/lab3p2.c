#include "lab3p2-defs.h"

int main(int argc, char const *argv[])
{
    

    // Display prompt
    outInstructions();

    // Init projectile
    Projectile *projectile = malloc(sizeof(struct Projectile));
    getInput(projectile);

    // Run calculations
    double time = calculateTime(projectile);
    double height = calculateHeight(projectile, time);

    // Return results.
    outResults(time, height);
    return 0;
}
