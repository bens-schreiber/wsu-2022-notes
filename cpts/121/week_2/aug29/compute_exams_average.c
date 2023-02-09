/* 
    Name: Benjamin Schreiber
    Date: 8/29/22
    Class: CPTS 121

    Description: Prompts the user for three exam scores,
    computes the average of the three exam scores
*/

#include <stdio.h>

void addScore(const char *print, int *score)
{
    printf("%s", print);
    scanf("%d", score);
}

int main(int argc, char const *argv[])
{
    int first = 0, second = 0, third = 0;

    addScore("First score ", &first);
    addScore("Second score ", &second);
    addScore("Third score ", &third);
    
    printf("%d", (first + second + third)/3);
    return 0;
}
