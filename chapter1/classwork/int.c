#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int year_age = get_int("How old are you?\n");
    int day_age =year_age * 365;

    printf("you are %i days old and %i years old!\n", day_age, year_age);

}