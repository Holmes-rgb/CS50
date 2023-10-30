#include <cs50.h>
#include <stdio.h>

int main(void)
{
    typedef struct
    {
        string name;
        int year;
        float gpa;
    }
    student;

    student s1 = {"Nicky", 2016, 4.0};
    student s2 = {"Adam", 2019, 4.0};
    printf("%s graduated in %i\n", (s1. name), (s1. year));
}