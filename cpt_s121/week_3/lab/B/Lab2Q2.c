#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{

    double weight;
    printf("Enter your weight: ");
    scanf("%lf", &weight);

    int feet;
    int inches;
    printf("Enter your height (feet [SPACE] inches): ");
    scanf("%d %d", &feet, &inches);

    printf("%lf", (weight) / pow((feet * 12) + inches, 2) * 703);

    return 0;
}
