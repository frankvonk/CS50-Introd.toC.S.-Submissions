#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do
    {
        //asks for height
        n = get_int("Height: ");
    }
    while (n < 0 || n > 23);
    for (int i = 0; i < n; i++)
    {
        //increases spaces
        for (int j = 0; j < n - 1 - i; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < i + 2; j++)
            //decreases #'s'
        {
            printf("#");
        }
        printf("\n");
    }
}
