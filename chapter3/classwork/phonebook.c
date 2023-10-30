 // Implements a phone book without structs

#include <cs50.h>
#include <stdio.h>
#include <string.h>


    typedef struct
    {
        string names;
        string numbers;
    }
    person;

int main(void)
{

    person people[4];

    people[0].names = "EMMA";
    people[0].numbers = "617-555-0100";

    people[1].names = "RODRIGO";
    people[1].numbers = "617-555-0101";

    people[2].names = "BRIAN";
    people[2].numbers = "617-555-0102";

    people[3].names = "DAVID";
    people[3].numbers = "617-555-0103";

    for (int i = 0; i < 4; i++)
    {
        if (strcmp(people[i].names, "EMMA") == 0)
        {
            printf("Name %s\n Number %s\n", people[i].names , people[i].numbers);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}