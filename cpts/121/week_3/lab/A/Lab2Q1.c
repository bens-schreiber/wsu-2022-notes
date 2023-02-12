#include <stdio.h>

int main(int argc, char const *argv[])
{
    double x1, y1, x2, y2;
    printf("Enter the values for x1 and y1: ");
    scanf("%lf, %lf", &x1, &x2);

    printf("Enter the value for x2 and y2: ");
    scanf("%lf, %lf", &x2, &y2);

    double slope = (x1 - x2) / (y1 - y2);
    printf("slope: %lf\n", slope);

    double midpointX = (x1 + x2) / 2;
    double midpointY = (y1 + y2) / 2;
    printf("midpoint: ( %lf, %lf )\n", midpointX, midpointY);

    double perpandicularBisectorSlope = 1/slope;
    printf("slope of the perp bisector: %lf\n", perpandicularBisectorSlope);

    double perpendicularBisectorY = midpointY - midpointX;
    printf("Y intercept of the perp bisector: %lf\n", perpendicularBisectorY);

    // slope form of perp bisector
    printf("x1, y1: (%lf, %lf)\n x2,y2:(%lf, %lf)\n y = %lfx + %lf\n", x1, y1, x2, y2, perpandicularBisectorSlope, perpendicularBisectorY);

    return 0;
}

