#include "tests.h"

static void awaitInput()
{
    printf("\nPress ENTER to continue!\n");
    char input = 0;
    fflush(stdin);
    getchar();
    system("clear");
}

void runTests(const int runTests, FitbitResult *result) {
    if (!runTests) {return;}

    printf("avg heart: %f", result->computations.averageHeartRate);
    printf("max steps: %d", result->computations.maxStepsTaken);
    printf("poor sleep sum: %d", result->computations.poorSleep.sum);
    printf("total calories: %d", result->computations.totalCaloriesBurned);
    printf("total distance: %d", result->computations.totalDistanceWalked);
    printf("total floors: %d", result->computations.totalFloorsWalked);
    printf("avg total steps: %d", result->computations.totalStepsTaken);

    awaitInput();


    // Manual reading
    int index = 0;
    while (index < TARGET_SIZE) {
        printf("minute: %s\n", result->data[index].minute);
        printf("calories: %lf\n", result->data[index].calories);
        printf("distance: %lf\n", result->data[index].distance);
        printf("floors: %d\n", result->data[index].floors);
        printf("heart: %d\n", result->data[index].heartRate);
        printf("steps: %d\n", result->data[index].steps);
        printf("sleep: %d\n", result->data[index].sleepLevel);
        awaitInput();
    ++index;
    }
}