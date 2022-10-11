#include <stdio.h>
#include <stdlib.h>

int dispense_bills(double balance,
                   double withdrawal_amount,
                   int *hundreds_ptr,
                   int *fifties_ptr,
                   int *twenties_ptr,
                   int *tens_ptr)
{
    if (withdrawal_amount > balance)
    {
        *hundreds_ptr = 0;
        *fifties_ptr = 0;
        *twenties_ptr = 0;
        *tens_ptr = 0;
        return 0;
    }

    // Truncate the double since they aren't neccesary here
    unsigned int i_withdrawl = (unsigned int)withdrawal_amount;

    // iterate using the i_withdrawl value
    // Go through the cases to gather the 
    // 100s, 50s, 20s and 10s that the i_withdrawl is made of.
    while (i_withdrawl >= 10)
    {

        if (i_withdrawl >= 100)
        {
            *hundreds_ptr += i_withdrawl / 100;
            i_withdrawl -= *hundreds_ptr * 100;
        }

        else if (i_withdrawl >= 50)
        {
            *fifties_ptr += i_withdrawl / 50;
            i_withdrawl -= *fifties_ptr * 50;
        }

        else if (i_withdrawl >= 20)
        {
            *twenties_ptr += i_withdrawl / 20;
            i_withdrawl -= *twenties_ptr * 20;
        }

        else if (i_withdrawl >= 10)
        {
            *tens_ptr += i_withdrawl / 10;
            i_withdrawl -= *tens_ptr * 10;
        }
    }

    return 1;
}

int main(int argc, char const *argv[])
{

    int h = 0;
    int f = 0;
    int t = 0;
    int tens = 0;
    dispense_bills(1630, 1630, &h, &f, &t, &tens);
    printf("100: %d\n 50: %d\n 20: %d\n 10: %d", h, f, t, tens);
    return 0;
}

