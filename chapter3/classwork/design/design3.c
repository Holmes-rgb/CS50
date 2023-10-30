// Check to see whether or not an argument entered at the command-line has a capital letter in it

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./design3 <argument>\n");
        return 1;
    }

    // There's room for design improvement on lines 17-30
    bool capital = false;

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (isupper(argv[1][i]))
        {
            capital = true;
        }
    }

    if (capital)
    {
        printf("There's a capital letter.\n");
    }
}