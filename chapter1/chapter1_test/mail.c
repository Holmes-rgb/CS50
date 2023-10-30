#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float weight;
    do
    {
        weight = get_float("How many ounces is your package \n"); // repeat the question until valid input

    }
    while (weight < 1);// only alow numbers over 1

    int mass = ceil(weight); // round weight up to nearest whole number

    if (mass <= 13)
    {
        float price = (((mass - 1) * 2) * 0.1) + 1; // math to get the price in terms of the weight
        printf("$%.2f\n", price);// print the price formated
    }
    else
    {
        printf("Over allowed weight.");// printed if the weight rounded up is over 13oz
    }
}