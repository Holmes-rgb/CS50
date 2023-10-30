#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float dollars;
    do
    {
        dollars = get_float("How much change is owed? \n"); // repeat the question until valid input
    }
    while (dollars <= 0); // only alow numbers over 0

    int cents = round(dollars * 100);
    int quarters = cents / 25; // find how many quarters
    int quartersr = cents % 25; // find remainder 
    int dimes = quartersr / 10; // find how many dimes
    int dimesr = quartersr % 10; // find remainder
    int nickles = dimesr / 5; // find how many nickles
    int nicklesr = dimesr % 5; // find remainder
    int pennies = nicklesr; // make the pennies variable equal to the remainder.
    int total = quarters + dimes + nickles + pennies;
    printf("%i quarters, %i dimes, %i nickles, and %i pennies", quarters, dimes, nickles, pennies);
    printf("%i /n", total);


}