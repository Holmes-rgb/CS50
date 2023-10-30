#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constant
#define ALPHABET 26

// Hash function prototype
int hash(char *word);

int main(void)
{
    
    char *copy;
    
    // Create a hashtable called "letters"
    char *hashtable[ALPHABET];

    // Initialize all pointers to NULL
    for (int i = 0; i < ALPHABET; i++)
    {
        hashtable[i] = NULL;
    }

    // Forever loop
    while (true)
    {
        // Get a word from the user
        char *word = get_string("Enter a word: ");
        
        // If the user enters "QUIT", break out of the forever loop
        if (strcmp(word, "QUIT") == 0)
        {
            break;
        }
        
        // Run the hash function with the word to get a key
        int key = hash(word);
        
        // Put the word in the location specified by the key
        if (key != -1)
        {
            // Allocate (new) space for the word
            copy = malloc(strlen(word) + 1);
            
            // Copy the word into the new space
            strcpy(copy, word);
            
            // Store the word in the hashtable using the key
            hashtable[key] = copy;
        }
    }

    // Print the contents of the hashtable...
    for (int i = 0; i < ALPHABET; i++)
    {
        // ...if there's something there to print
        if (hashtable[i] != NULL)
        {
            printf("Key %i: %s\n", i, hashtable[i]);
        }
    }
    
    free(copy);
}

int hash(char *word)
{
    // Base the hash function off of the first character of the word
    char c = word[0];

    // Check if the first character is a letter
    if (isalpha(c))
    {
        // Shift the value to between 0 and 25 to get a valid key
        char key = tolower(c) - 'a';
        return key;
    }
    // If the first character is NOT a letter, return an error
    else
    {
        printf("Error: String doesn't start with a letter\n");
        return -1;
    }
    
    
}