// cs50 pset1 credit
// frank vonk, 2018
#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    // Prompt user input
    long long ccn = 0;

    do
    {
        printf("Please enter Card Number here :");
        ccn = get_long_long();
    }
    while (ccn<0);
//    while (ccn < 3999999999999 || ccn > 5600000000000000);

    // Set the counter
    int counter = 0;
    long long digits = ccn;
    while (digits > 0)
    {
        digits = digits / 10;
        counter++;
    }
    if ((counter != 13) && (counter != 15) && (counter != 16))
    {
        printf("INVALID CODE\n");
    }
    int number[counter];

    // Implement algorithm
    for (int i = 0; i < counter; i++)
    {
        number[i] = ccn % 10;
        ccn = ccn / 10;
    }

    int firstnum[counter];
    for (int i = 1; i < counter; i++)
    {
        firstnum[i] = number[i];
    }

    for (int i = 1; i < counter; i += 2)
    {
        number[i] = number[i] * 2;
    }

    int v = 0;
    int temp;

    if (counter == 13)
    {
        for (int i = 0; i < counter; i++)
        {
            temp = (number[i] % 10) + (number[i] / 10 % 10);
            v = v + temp;
        }
        if (firstnum[12] == 4 && v % 10 == 0)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    if (counter == 15)
    {
        for (int i = 0; i < counter; i++)
        {
            temp = (number[i] % 10) + (number[i] / 10 % 10);
            v = v + temp;
        }
        if (firstnum[14] == 3 && v % 10 == 0 && (firstnum[13] == 4 || firstnum[13] == 7))
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    if (counter == 16)
    {
        for (int i = 0; i < counter; i++)
        {
            temp = (number[i] % 10) + (number[i] / 10 % 10);
            v = v + temp;
        }
        if (firstnum[15] == 4 && v % 10 == 0)
        {
            printf("VISA\n");
        }
      else if (firstnum[15] == 5 && v % 10 == 0 && (firstnum[14] == 1 || firstnum[14] == 2 || firstnum[14] == 3 || firstnum[14] == 4 || firstnum[14] == 5))
        {
            printf("MASTERCARD\n");
        }
        // print invalid if code is wrong
        else
        {
            printf("INVALID CODE\n");
        }
    }
    return 0;
}