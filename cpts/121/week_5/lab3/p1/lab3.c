#include <stdio.h>

double bmi(double weight, int height);

int main(int argc, char const *argv[])
{
    int weight;
    double height;
    printf("Enter your weight in pounds and height in feet\n");
    scanf("%d %lf", &weight, &height);
    printf("Your bmi is: %lf", bmi(weight, height));
    return 0;
}

double bmi(double weight, int height) {
    return ((weight) / ((height * 12) * (height*12))) * 703;
}
