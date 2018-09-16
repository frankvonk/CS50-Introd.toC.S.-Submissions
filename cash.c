// 'cash' from problem set 1 for cs50. By Frank Vonk.
// September 2018
#include <math.h>
#include <stdio.h>
#include <cs50.h>

int main()
{
    float ammount;
    do
    {
        // Asks user input for the ammount
        ammount = get_float("What is the ammount?");
    }
    while (ammount < 0);

    // Convert ammount to cents
    int cents;
    cents = round(ammount * 100);

    // Shave off coin by coin, starting at the biggest (25ct)
    int coins = 0;
    while (cents > 24)
    {
        coins ++ ;
        cents -= 25 ;
    }
    while (cents > 9)
    {
        coins ++ ;
        cents -= 10 ;
    }
    while (cents > 4)
    {
        coins ++ ;
        cents -= 5 ;
    }
    while (cents > 0)
    {
        coins ++ ;
        cents -= 1 ;
    }
    // Print total
    printf("I have %i coins.\n", coins);
}