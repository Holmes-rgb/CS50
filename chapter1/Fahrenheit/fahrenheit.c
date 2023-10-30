#include <stdio.h>
#include <cs50.h> // cs50 library
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {

    float temp_C = atof (argv[1]);
    printf("%f\n!", (temp_C * 1.8) + 32);//print the temperature
    }
}