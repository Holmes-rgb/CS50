#include <stdio.h>
#include <cs50.h>
#include <string.h>

int length(string p);

int main(void)
{
    string s = get_string("What's your name? ");
    int x = length(5);
    printf("Your name is %i characters long!\n", x);
}

int length(string p)
{
    int len = strlen(p);
    return len;
}