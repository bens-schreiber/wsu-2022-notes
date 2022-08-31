/* 
    Name: Benjamin Schreiber
    Date: 8/29/22
    Class: CPTS 121

    Description: 
*/
 
#define _CRT_SECURE_NO_WARNINGS // necessary to ignore scanf_s () warnings
 
#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int i = 0;
    int r = 0;

    printf("Enter the current (I) \n");
    scanf("%d", &i);

    printf("Enter the resistance (R) \n");
    scanf("%d", &r);

    printf("%d", i * r);

    return 0;
}
