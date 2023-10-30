# include <stdio.h>
# include <cs50.h>
# include <string.h>
# include <ctype.h>
# include <math.h>


int main(void)
{
    string text = get_string("text: ");
    const int strlength = strlen(text);


    int numchar = strlength;
    for (int i = 0; i < strlength; i++)
    {
        if (text[i] == ' ')
        {
            numchar --;
        }
    }

int rem = numchar % 8;

 for (int i = 0; strlength > i; i++)
        {
            // checking if it is lowercase
            if (text[i] >= 'a' && text[i] <= 'z')
            {
                printf("%c", (((text[i] - 'a') + rem) % 26) + 'a'); // using the function provided
            }

            // checking if it is uppercase
            else if (text[i] >= 'A' && text[i] <= 'Z')
            {
                printf("%c", (((text[i] - 'A') + rem) % 26) + 'A'); //  using the function provided
            }

             // default to print out the char un-ciphered
            else
            {
                printf ("%c", (text[i]));
            }


        }

}


