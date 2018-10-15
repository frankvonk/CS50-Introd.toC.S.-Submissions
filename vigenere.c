/*
Project Vigenere for CS50, problem Set 2.
By Frank Vonk, 2018
*/
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main(int argc, string argv[])
{
    int j, k;
    int l = 0;
    // Check to see if key is given, else return 1
    if (argc != 2)
    {
        printf("ERROR: SELF DESTRUCTION IN 5 4 3 2 1 \n");
        return 1;
    }
    string s = (argv[1]);
    // Check to see if key is alphabetical
    for (int i = 0; i < strlen(s); i++)
    {
        if (isalpha(s[i]) == false)
        {
            printf("ERROR: SELF DESTRUCTION IN 5 4 3 2 1 \n");
            return 1;
        }
    }

    // Get Plaintext
    string p = get_string("plaintext: ");
    printf("ciphertext: ");
    // Iterate over plaintext
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        // create iteration to filter upper and lower / special signs
        if (isupper(p[i]))          // If upper, add key - print
        {
            j = (l % strlen(s));
            k = (tolower(s[j]) - 97);
            printf("%c", (((p[i] + k) - 65) % 26) + 65);
            l += 1;
        }
        else if (islower(p[i]))     // If lower, add key - print
        {
            j = (l % strlen(s));
            k = (tolower(s[j]) - 97);
            printf("%c", (((p[i] + k) - 97) % 26) + 97);
            l += 1;
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