/*
    Name: Benjamin Schreiber
    Date: 9/2/22
    Class: CPTS 121

    Description: 9/2 homework equation problems
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../c_tools/tools.h"

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
    printf("Press ENTER for the next problem");
    scanf("%c%*c", &a);
    system("clear");

    printf("%s\n", problem);
}

int main(int argc, char const *argv[])
{

    /*
    QUESTION 1:
    Total series resistance: series_resistance = R1 + R2 + R3, for 3 resistors. R1, R2, and R3 are integers.
    */
    printf("Q1 Total series resistance\n");
    int R1;
    int R2;
    int R3;
    setIntValue("R1", &R1);
    setIntValue("R2", &R2);
    setIntValue("R3", &R3);
    printf("Resistance: %d\n", R1 + R2 + R3);


    /*
    QUESTION 2:
    Sales tax: total_sales_tax = sales_tax_rate * item_cost (note: it’s OK to show the result beyond the hundredths place, we don’t know how to show to the hundredths place yet)
    */
    startProblem("Q2 Sales tax");
    double sales_tax_rate;
    double item_cost;
    setDoubleValue("Sales tax rate: ", &sales_tax_rate);
    setDoubleValue("Item Cost: ", &item_cost);
    printf("Total Sales: %f\n", sales_tax_rate * item_cost);

    /*
    QUESTION 3:
    Volume of a right rectangular pyramid: volume_pyramid = (l * w * h) / 3, where l and w are the length and width of the base, respectively, and h is the height of the pyramid.
    */
    startProblem("Q3 Volume of a right rectangular pyramid ");
    double L;
    double W;
    double H;
    setDoubleValue("Length", &L);
    setDoubleValue("Width", &W);
    setDoubleValue("Height: ", &H);
    printf("Volume: %f\n", (L * W * H) / 3);

    /*
    QUESTION 4:
    Total parallel resistance: parallel_resistance = 1 / (1 / R1 + 1 / R2 + 1 / R3), for 3 resistors. R1, R2, and R3 are integers.
    */
    startProblem("Q4 Total Parrallel Resistance");
    R1 = 0;
    R2 = 0;
    R3 = 0;
    setIntValue("R1", &R1);
    setIntValue("R2", &R2);
    setIntValue("R3", &R3);
    printf("Total Parallel Resistance: %f\n", 
        1 / 
            (1/(double) R1)
            + (1/(double) R2)
            + (1/(double) R3)
    );

    /*
    QUESTION 5:
    Character encoding: encoded_character = (plaintext_character – 'a') + 'A' – shift_int; shift_int is an integer (note: what happens if plaintext_character is lowercase? What happens with various shift_int values? Please use the ASCII table to help you understand how to interpret the encoded character produced.)
    */
    startProblem("Q5 Character Encoding");
    int shift_int;
    setIntValue("Shift int", &shift_int);
    printf("Character encoding: %c\n", (char) ('a' + 'A' - shift_int));

    /*
    QUESTION 6:
    Distance between two points: distance = square root of ((x1 - x2)2 + (y1 - y2)2) (note: you will need to use sqrt ( ) out of <math.h>)
    */
    startProblem("Q6 Distance between two points");
    double x1;
    double x2;
    double y1;
    double y2;
    setDoubleValue("x1", &x1);
    setDoubleValue("x2", &x2);
    setDoubleValue("y1", &y1);
    setDoubleValue("y2", &y2);
    printf("Distance: %f\n", sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));

    /*
    QUESTION 7:
    General equation: y = y / (3/17) - z + x / (a % 2) + PI (recall: a is an integer; the 3 and 17 constants in the equation should be left as integers initially, but explicitly type-casted as floating-point values)
    */
    startProblem("Q7 General Equation");
    double y;
    double z;
    double x;
    int a;
    setDoubleValue("y", &y);
    setDoubleValue("z", &z);
    setDoubleValue("x", &x);
    setIntValue("a", &a);
    printf("Answer: %f\n", y / (
        (3/(float) 17) - z + x / (a % 2) + 3.14
    ));

    return 0;
}
