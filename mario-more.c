#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do
    {
        //asks for height
        height = get_int("Height: ");
    }
    while (height < 0 || height > 23);

    for (int i = 0; i < height; i++)
    {
        //increases spaces left piramid
        for (int space = 0; space < height - i; space++)
        {
            printf(" ");
        }

        //decreases #'s left piramid
        for (int hasht = 0; hasht < i + 1; hasht++)
        {
            printf("#");
        }
        printf("  ");
        //increases #'s right piramid
        for (int hasht = 0; hasht < i + 1; hasht++)
        {
            printf("#");
        }

        printf("\n");
    }
}
