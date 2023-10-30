#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int number;
    do
    {
        number = get_int("Height: \n"); // repeat the question until valid input
    }
    while (number <= 0 || number > 8);


    for (int j = 0; j < number; j++) // repeat for the rows
    {


        for (int i = 0; i < number - (j + 1); i++) //print spaces before #
        {

            printf(" ");
        }


        for (int i = 0; i < j + 1; i++) //print #s
        {
            printf("#");
        }



        printf("\n");
    }

    // printf("\n");

}