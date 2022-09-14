#include "lab3p3-defs.h"

int main(int argc, char const *argv[])
{
    outResults(calculateAverage(
        promptScore("First exam score: ") * 1.3,
        promptScore("Second exam score: ") * 1.3,
        promptScore("First lab score: ") * 1.05,
        promptScore("Second lab score: ") * 1.05,
        promptScore("First project score: ") * 1.15,
        promptScore("Second project score: ") * 1.15));
    return 0;
}