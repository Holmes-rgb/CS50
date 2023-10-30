// Luke Holmes

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // check if player 1 won and print if so
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    // check if player 2 won and print if so
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    // check if it was a tie and print if so
    else if (score1 == score2)
    {
        printf("Tie!\n");
    }

}

int compute_score(string word)
{
    // declare variables
    int lscore;
    int fscore = 0;

    // check each letter in the string find the score of the letter and add it to the final score
    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] >= 'a' && word[i] <= 'z')
        {
            lscore = POINTS[(word[i] - 'a')];
            fscore = lscore + fscore;
        }

        if (word[i] >= 'A' && word[i] <= 'Z')
        {
            lscore = POINTS[(word[i] - 'A')];
            fscore = lscore + fscore;
        }
    }
    // return the final score
    return fscore;
}

