#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

// Define a macro for the dimensions of the board
// Everywhere 'DIMENSION' appears, it'll be replaced by a 3
// This is similar to using a constant global variable
#define DIMENSION 3

// Create a 3x3 tic-tac-toe board
int board[DIMENSION][DIMENSION];

// Define constant global variables for the game
const int BLANK = 0;
const int X = 1;
const int O = 2;

// Function prototypes
void print_board(void);
bool full_board(void);

int main(void)
{
    // Initalize the board with blanks
    for (int row = 0; row < DIMENSION; row++)
    {
        for (int col = 0; col < DIMENSION; col++)
        {
            board[row][col] = BLANK;
        }
    }

    // Keep track of whose move it is
    bool xmove = true;

    // Keep track of the current move
    int move;

    // Play the game
    while (true)
    {
        // Get the player's move via a number
        // Each number will map to a spot in the tic-tac-toe board
        // Here's the mapping of numbers to spots
        /*
         * 0 1 2
         * 3 4 5
         * 6 7 8
         */
        if (xmove)
        {
            move = get_int("Where do you want to place an X? (0-8) ");
        }
        else
        {
            move = get_int("Where do you want to place an O? (0-8) ");
        }

        // do not allow moves under 0
        if (move < 0)
        {
            printf("Goodbye!\n");
            return 0;
        }

        // check to see if the move is outside grid
        else if (move >= DIMENSION * DIMENSION)
        {
            printf("Invalid move.\n");
            continue;
        }

        // calculate row and col
        int moverow = move / DIMENSION;
        int movecol = move % DIMENSION;

        // check to see if the blank is empty
        if (board[moverow][movecol] != BLANK)
        {
            printf("Invalid move.\n");
            continue;
        }

        // if its x's turn then it will put an x
        else if (xmove)
        {
            board[moverow][movecol] = X;
        }

        // if its O's turn it will put an O
        else
        {
            board[moverow][movecol] = O;
        }

        // Print the full tic-tac-toe board
        // With a blank space before and after to make it clearer
        printf("\n");
        print_board();
        printf("\n");

        // Check if the tic-tac-toe board is full
        if (full_board())
        {
            // If so, quit the game
            printf("Goodbye!\n");
            return 0;
        }

        // switching whose turn it is
        else
        {
            xmove = !xmove;
        }
    }
}

// Function to print the tic-tac-toe board
void print_board(void)
{
    for (int i = 0; i < DIMENTION; i++)
    {
        for (int j = 0; j < DIMENTION; j++ )
        {
            int board[DIMENSION + i][DIMENSION + j];
        }



    }




}

// Function to check if the tic-tac-toe board is full
bool full_board(void)
{
    return false;
}