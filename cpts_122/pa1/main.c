#include "./data_reader/data_reader.h"
#include "consts.h"
#include <stdio.h>

#define INDEX 2

int main(int argc, char const *argv[])
{
    FILE *f = fopen(CSV_LOCATION, "rw");
    FitbitResult *result = readAndComputeData(f);

    // TESTS
    printf("target: %s\n", result->data[INDEX].patient);
    printf("minute: %s\n", result->data[INDEX].minute);
    printf("calories: %lf\n", result->data[INDEX].calories);
    printf("distance: %lf\n", result->data[INDEX].distance);
    printf("floors: %d\n", result->data[INDEX].floors);
    printf("heart: %d\n", result->data[INDEX].heartRate);
    printf("steps: %d\n", result->data[INDEX].steps);
    printf("sleep: %d\n", result->data[INDEX].sleepLevel);

    free(result);
    return 0;
}
