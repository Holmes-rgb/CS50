// Add four numbers entered by the user at the command line

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 5)
    {
        printf("Usage: ./design2 <int> <int> <int> <int>\n");
        return 1;
    }

    int first = atoi(argv[1]);
    int second = atoi(argv[2]);
    int third = atoi(argv[3]);
    int fourth = atoi(argv[4]);

    // There's room for design improvement on lines 21-25
    int first_two_sum = first + second;
    int first_three_sum = first_two_sum + third;
    int all_four_sum = first_three_sum + fourth;

    printf("The sum is %i.\n", all_four_sum);
}