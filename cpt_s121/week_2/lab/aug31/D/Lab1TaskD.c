/* 
    Name: Benjamin Schreiber
    Date: 8/29/22
    Class: CPTS 121

    Description: 
*/
 
#define _CRT_SECURE_NO_WARNINGS // necessary to ignore scanf_s () warnings
 
#include <stdio.h>
#include <math.h>

void setValue(char valueName, float *value) {
    printf("Enter the value for %c \n", valueName);
    scanf("%f", value);
}

int main(int argc, char const *argv[])
{
    float a;
    float b;
    float c;
    float d;
    float x;

    setValue('a', &a);
    setValue('b', &b);
    setValue('c', &c);
    setValue('d', &d);
    setValue('x', &x);

    printf(
        "%f",
        pow(3 * a, 3) 
        + pow((0.25)*b, 2) 
        + (10 * c * x)
        + ((-5) * d)
    );

    return 0;
}
