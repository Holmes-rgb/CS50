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
        if ((text[i] >= 1 && text[i] <= '@') || (text[i] >= '[' && text[i] <= '`') || (text[i] >= 123 && text[i] <= 127))
        {
            numchar --;
        }
    }



    int numword = 1;

    for (int j = 0; j < strlength; j++)
    {
        if (text[j] == ' ')
        {
            numword++;
        }
    }


    int num_sent = 0;
    for (int k = 0; k < strlength; k++)
    {
        if ((text[k] == '.') || (text[k] == '?') || (text[k] == '!'))
        {
            num_sent++;
        }

    }

    float grade = 0.0588 * (100 * (float) numchar / (float) numword) - 0.296 * (100 * (float) num_sent / (float) numword) - 15.8;
    // L = average number of letters per 100 words
    // S is the average number of sentences per 100 words in the text



    int grade_level = round(grade);

    if (grade_level >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade_level < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade_level);
    }


}