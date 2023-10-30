# include <stdio.h>
# include <cs50.h>
# include <string.h>

int main(void)
{
    string s = get_string("Input: ");

    printf("Output: ");


    char upper;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
    upper = s[i] - 32;

    if (s[i] >= 'A' && s[i] <= 'Z')

    {
        printf("%c", s[i]);

    }
    }

    printf("\n");

}