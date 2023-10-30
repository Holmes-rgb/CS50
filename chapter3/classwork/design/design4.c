// Turn a full name (first, middle, last) entered at the command-line into title case

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc < 2 || argc > 4)
    {
        printf("Usage: ./design4 <first> <middle> <last>\n");
        return 1;
    }

    // There's room for design improvement on lines 19-77
    // Hint: Use a function to run code that needs to be repeated

    // Print the first name in title case
    if (argc >= 2)
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            // Make the first letter uppercase
            if (i == 0)
            {
                printf("%c", toupper(argv[1][i]));
            }
            // Make all other letters lowercase
            else
            {
                printf("%c", tolower(argv[1][i]));
            }
        }
    }

    // Print the second name in title case
    if (argc >= 3)
    {
        // Print a space between this name and the previous one
        printf(" ");

        for (int i = 0, n = strlen(argv[2]); i < n; i++)
        {
            // Make the first letter uppercase
            if (i == 0)
            {
                printf("%c", toupper(argv[2][i]));
            }
            // Make all other letters lowercase
            else
            {
                printf("%c", tolower(argv[2][i]));
            }
        }
    }

    // Print the third name in title case
    if (argc == 4)
    {
        // Print a space between this name and the previous one
        printf(" ");

        for (int i = 0, n = strlen(argv[3]); i < n; i++)
        {
            // Make the first letter uppercase
            if (i == 0)
            {
                printf("%c", toupper(argv[3][i]));
            }
            // Make all other letters lowercase
            else
            {
                printf("%c", tolower(argv[3][i]));
            }
        }
    }

    // Print a new line at the end
    printf("\n");
}