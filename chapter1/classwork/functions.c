#include <stdio.h>
#include <cs50.h>

int get_age(void);

int main(void)
{
    int i = get_age();

}

int get_age(void)
{
    int age = get_int("How old are you? ");
    return printf("You are %i years old!\n", i);;
}