// Check whether or not a user agrees

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char c = get_char("Do you agree? (y/n) ");

    // There's room for design improvement on lines 11-39
    if (c == 'y' || 'Y')
    {
        printf("Agreed.\n");
    }

    else if (c == 'n'||'N')
    {
        printf("Disagreed.\n");

    else if
    {
        printf("Unsure.\n");
    }

    }
}