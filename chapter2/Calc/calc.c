#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    float output;

    if (argc == 4)
    {
        // convert strings in argv to floats
        float a = atof(argv[1]);
        float c = atof(argv[3]);



        //check if it is a /
        if (argv[2][0] == '/')
        {
            output = (a / c);
            printf("%f\n", output);
        }
        //check if it is a x
        else if (argv[2][0] == 'x')
        {
            output = (a * c);
            printf("%f\n", output);
        }
        //check if it is a +
        else if (argv[2][0] == '+')
        {
            output = (a + c);
            printf("%f\n", output);
        }
        //chech if it is a -
        else if (argv[2][0] == '-')
        {
            output = (a - c);
            printf("%f\n", output);
        }
        //check if it is a modle
        else if (argv[2][0] == '%')
        {
            int q = (int)(a / c);
            output = a - (c * q);
            printf("%f\n", output);
        }
        // error if not operation
        else
        {
            return 1;
        }
        
        
        

    }
    
    // error if not 4
    else
    {
        return 1;
    }


}