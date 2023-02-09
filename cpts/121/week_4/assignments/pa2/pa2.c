#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tools.h"

/*
    Name: Benjamin Schreiber
    Date: 9/13/22
    Class: CPTS 121

    Description: pa2 homework problems
*/

typedef struct Point
{
    double X;
    double Y;
} Point;

int totalSeriesResistance(int R1, int R2, int R3); /*  Calculates the total series resistance of 3 resistors, all ints   */

double calculateTotalSalesTax(double salesTaxRate, double itemCost);

double calculateVolumePyramid(double l, double w, double h);

double totalParallelResistance(int R1, int R2, int R3);

double calculateDistance(Point *p1, Point *p2);

int main(int argc, char const *argv[])
{

    printf("Q1 Total Series Resistance\n");
    int R1, R2, R3;
    setIntValue("R1", &R1);
    setIntValue("R2", &R2);
    setIntValue("R3", &R3);
    printf("Resistance: %d\n", totalSeriesResistance(R1, R2, R3));

    startProblem("Q2 Total salex tax");
    double salesTaxRate;
    double itemCost;
    setDoubleValue("Sales Tax Rate", &salesTaxRate);
    setDoubleValue("Item Cost", &itemCost);
    printf("Total Sales: %f\n", calculateTotalSalesTax(salesTaxRate, itemCost));

    startProblem("Q3 Volume of a right rectangular pyramid ");
    double L;
    double W;
    double H;
    setDoubleValue("Length", &L);
    setDoubleValue("Width", &W);
    setDoubleValue("Height", &H);
    printf("Volume: %f\n", calculateVolumePyramid(L, W, H));

    startProblem("Q4 Total Parrallel Resistance");
    R1 = 0;
    R2 = 0;
    R3 = 0;
    setIntValue("R1", &R1);
    setIntValue("R2", &R2);
    setIntValue("R3", &R3);
    printf("Total Parallel Resistance: %f\n", totalParallelResistance(R1, R2, R3));

    startProblem("Q6 Distance between two points");
    double x1;
    double x2;
    double y1;
    double y2;
    setDoubleValue("x1", &x1);
    setDoubleValue("x2", &x2);
    setDoubleValue("y1", &y1);
    setDoubleValue("y2", &y2);
    Point p1 = {.X = x1, .Y = y1};
    Point p2 = {.X = x2, .Y = y2};
    printf("Distance: %f\n", calculateDistance(&p1, &p2));

    return 0;
}

int totalSeriesResistance(int R1, int R2, int R3)
{
    return R1 + R2 + R3;
}

double calculateTotalSalesTax(double salesTaxRate, double itemCost)
{
    return salesTaxRate * itemCost;
}

double calculateVolumePyramid(double l, double w, double h)
{
    return l * w * h;
}

double totalParallelResistance(int R1, int R2, int R3)
{
    return 1 /
               (1 / (double)R1) +
           (1 / (double)R2) + (1 / (double)R3);
}

double calculateDistance(Point *p1, Point *p2)
{
    return sqrt(pow((*p1).X - (*p2).X, 2) + pow((*p1).Y - (*p2).Y, 2));
}