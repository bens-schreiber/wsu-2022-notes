/* 
    Name: Benjamin Schreiber
    Date: 8/29/22
    Class: CPTS 121

    Description: 
*/
 
#define _CRT_SECURE_NO_WARNINGS // necessary to ignore scanf_s () warnings
#define pi 3.14159 

#include <stdio.h>
#include <math.h>

void setValue(char valueName, float *value) {
    printf("Enter the value for %c \n", valueName);
    scanf("%f", value);
}

int main(int argc, char const *argv[])
{
    float radius;
    setValue('r', &radius);
    printf("%f", 2 * pi * radius);
    return 0;
}
