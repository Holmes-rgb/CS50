//Luke Holmes

#include <stdio.h>
#include <cs50.h>

// Max number of papers
#define MAX 20

// A paper has a title and an amount of citations
typedef struct
{
    string title;
    int citations;
}
paper;

// Array of papers
paper papers[MAX];


int main(void)
{
    
    int n;
    do
    {
        n = get_int("Number of papers: ");
    }
    while (n < 0 || n > MAX);
    
    

    //enter title and number of citations
    for (int i = 0; i < n; i++)
    {
        papers[i].title = get_string("Title of paper %i: ", i + 1);
        papers[i].citations = get_int("Amount of citations for paper %i: ", i + 1);
    }
    
    
    
    //find the paper with the highest number of citations
    int max_cite = 0;
    
    for (int l = 0; l < n; l++)
    {
        if (papers[l].citations > max_cite)
        {
            max_cite = papers[l].citations;
        }
    }
    

    //find the 
    int cite_count;
    // j = H-index that we are checking for
    for (int j = 1; j < max_cite + 1; j++)
    {
        cite_count = 0;
        
        for (int k = 0; k < n; k++)
        {
            if (papers[k].citations >= j)
            {
                // the amount of papers with grater than or equal citations j
                cite_count++;
            }
            
            
            // print the h-index if there are more citations or equal than the number of papers
            if (cite_count >= j)
            {
                printf("H-index: %i\n", cite_count);
            }
        }
    }
    
  

    
    
    
    
  
    return 0;
}

