#include "lab3p3-defs.h"

double promptScore(char *label)
{
    double score;
    printf("\nEnter the score for %s", label);
    scanf("%lf", &score);
    return score;
}

double calculateAverage(double first, double second, double third, double fourth, double fifth, double sixth)
{
    return (first + second + third + fourth + fifth + sixth) / 6;
}

void outResults(double result) {
    printf("\nYour weighted average score is: %lf", result);
}