/*
Project Ceasar for CS50, problem Set 2.
By Frank Vonk, 2018
*/
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main(int argc, string argv[])
{
    // Check to see if key is given, else return 1
    if (argc != 2)
    {
        printf("Usage: ");
        return 1;
    }
// TESTED OK

    // Turn command line string into "int k"
    string key = argv[1];
    int k = atoi(argv[1]);
// TESTED OK

    // check key for modulo % 26 and call it int code
    int code = k % 26;
// TESTED OK

    // Get Plaintext
    string p = get_string("plaintext: ");
// TESTED OK
    printf("ciphertext: ");
// TESTED OK
    // Iterate over plaintext
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        // create iteration to filter upper and lower / special signs
        if (isalpha(p[i]))
        {
            if (isupper(p[i]))          // If upper, add key - print
            {
                char a = p[i];
                int b = a + code;   // Get int of ascii and add the cipher key
                if (b > 90)         // Turnaround upon Z
                {
                    b -= 26;
                }
                char c = b;         // Turn encrypted int to char
                printf("%c", c);
            }
            else if (islower(p[i]))     // If lower, add key - print
            {
                char a = p[i];
                int b = a + code;   // Get int of ascii and add the cipher key
                if (b > 122)         // Turnaround upon z
                {
                    b -= 26;
                }
                char c = b;     // turn encrypted int to char
                printf("%c", c);
            }
        }
        else                            // If non-alphabetical char print unchanged
        {
            printf("%c", p[i]);
        }
    }
    // print new line, and return 0
    printf("\n");
    return 0;
}