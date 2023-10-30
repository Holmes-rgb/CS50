#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int item_price = get_int("what's the price of your item?\n");
    float price = item_price * 1.0625;

    printf("Your new price is %f\n", price);

}