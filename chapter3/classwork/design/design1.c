// Square a number entered by the user

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int i;
    do
    {
        i = get_int("Pick a number between 0 and 12, and I'll square it for you: ");
    }
    while (i < 0 || i > 12);

    // There's room for design improvement on lines 16-67
    if (isdigit(i))
    {
        printf("%c * %c = %c\n",i ,i ,i * i);
    }

}