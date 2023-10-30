#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{


    if (argc == 2)
    {
        for (int j = 0; j < strlen(argv[1]); j++)
        {
            if (!(isdigit(argv[1][j])))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        // get text to encrypt
        string text = get_string("text: ");

        const int strlength = strlen(text);

        // get key to int fron argv
        int key = atoi(argv[1]);


        // print the heading
        printf("ciphertext: ");

        //ci = (pi + k) % 26 encrypting
        for (int i = 0; strlength > i; i++)
        {
            // checking if it is lowercase
            if (text[i] >= 'a' && text[i] <= 'z')
            {
                printf("%c", (((text[i] - 'a') + key) % 26) + 'a'); // using the function provided
            }

            // checking if it is uppercase
            else if (text[i] >= 'A' && text[i] <= 'Z')
            {
                printf("%c", (((text[i] - 'A') + key) % 26) + 'A'); //  using the function provided
            }

            // default to print out the char un-ciphered
            else
            {
                printf("%c", text[i]);
            }

        }

        printf("\n");
    }


    // error if bad key is entered
    else
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }

}