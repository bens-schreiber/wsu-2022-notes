#include <stdio.h>
#include <stdlib.h>

void setIntValue(const char *print, int *value)
{
    printf("%s: ", print);
    scanf("%d", value);
}

void setDoubleValue(const char *print, double *value)
{
    printf("%s: ", print);
    scanf("%lf", value);
}

void startProblem(const char* problem) {
    char a;
    printf("\nPress ENTER for the next problem");
    scanf("%c%*c", &a);
    system("clear");

    printf("%s\n", problem);
}
