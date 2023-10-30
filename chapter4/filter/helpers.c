// Luke Holmes
/*
sources used:
https://beginnersbook.com/2014/01/c-continue-statement/


*/


#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int y = 0; y < height; y++)
    {
        for (int i = 0; i < width; i++)
        {
            //Average the rgb values and write that average to each pixle
            int avg = (int) round(((float)image[y][i].rgbtRed + (float)image[y][i].rgbtGreen + (float)image[y][i].rgbtBlue) / 3);



            image[y][i].rgbtRed = avg;
            image[y][i].rgbtGreen = avg;
            image[y][i].rgbtBlue = avg;
        }

    }


    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int y = 0; y < height; y++)
    {
        for (int i = 0; i < width; i++)
        {
            int sepiaRed = (int) round((0.393 * image[y][i].rgbtRed) + (0.769 *  image[y][i].rgbtGreen) + (0.189 * image[y][i].rgbtBlue));

            int sepiaGreen = (int) round((0.349 * image[y][i].rgbtRed) + (0.686 * image[y][i].rgbtGreen) + (0.168 * image[y][i].rgbtBlue));

            int sepiaBlue = (int) round((0.272 * image[y][i].rgbtRed) + (0.534 * image[y][i].rgbtGreen) + (0.131 * image[y][i].rgbtBlue));







            if (sepiaRed > 255)
            {
                image[y][i].rgbtRed = 255;
            }
            else
            {
                image[y][i].rgbtRed = sepiaRed;
            }

            if (sepiaGreen > 255)
            {
                image[y][i].rgbtGreen = 255;
            }
            else
            {
                image[y][i].rgbtGreen = sepiaGreen;
            }


            if (sepiaBlue > 255)
            {
                image[y][i].rgbtBlue = 255;
            }
            else
            {
                image[y][i].rgbtBlue = sepiaBlue;
            }

        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int y = 0; y < height; y++)
    {
        for (int i = 0; i < (width / 2); i++)
        {
            // go through the left hand side of the image and store them in a temporary variable and write right half on left half then put temporary stored in on right


            //store left pixle
            RGBTRIPLE temp = image[y][i];

            //set pixle to the values of mirror right pixle
            image[y][i] = image[y][width - (i + 1)];

            //get temporarly stored pixle and set it to the value of the right pixle
            image[y][width - (i + 1)] = temp;
        }
    }


    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int Red_sum;
    int Green_sum;
    int Blue_sum;

    //number of pixels actualy surrounding the pixle that we are concerned with.
    float counter;

    //copy of image to avoid compounding the blur
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j].rgbtRed = image[i][j].rgbtRed;
            temp[i][j].rgbtGreen = image[i][j].rgbtGreen;
            temp[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //resets the sums and counter
            Red_sum = 0;
            Green_sum = 0;
            Blue_sum = 0;
            counter = 0.0;



            for (int k = -1; k < 2; k++)
            {

                for (int l = -1; l < 2; l++)
                {
                    if (j + l < 0 || j + l > width - 1)
                    {
                        continue;
                    }

                    //only continue if the pixle is in the picture height
                    if (i + k < 0 || i + k > height - 1)
                    {
                        continue;
                    }





                    //need all the sums to devide by counter at the end of 3 x 3
                    Red_sum =  Red_sum + temp[i + k][j + l].rgbtRed;
                    Green_sum = Green_sum + temp[i + k][j + l].rgbtGreen;
                    Blue_sum = Blue_sum + temp[i + k][j + l].rgbtBlue;
                    counter++;
                }
            }

            // this will compound my blur needs to be fixed. edit the origonal and take original values from the the picture from a copy.
            image[i][j].rgbtRed = (int) round((float) Red_sum / counter);
            image[i][j].rgbtGreen = (int) round((float) Green_sum / counter);
            image[i][j].rgbtBlue = (int) round((float) Blue_sum / counter);

        }
    }

    return;
}
