#include <stdio.h>
#include <cs50.h>

int main(void)
{
   int number;
    do
    {
        number = get_int ("How many question marks do you want? \n"); // repeat the question until valid input
    }
    while (number <= 0 || number > 50);




    for (int i = 0; i < number; i++)
    {
        printf ("?");
    }

    printf("\n");

}