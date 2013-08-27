#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int my_atoi(int *ptr_err_code, char **argv);

int main(int argc, char **argv)
{
    int err_code = 0;
    int *ptr_err_code = &err_code;
    int converted_int = my_atoi(ptr_err_code,argv);
    if(!(err_code))
        printf("\nConverted String: %d\n", converted_int);
    else
        printf("\nError Flag Set, conversion did not complete\n");
    return 0;
}


int my_atoi(int *ptr_err_code, char **argv) //my_atoi takes the pointer to the error code and the char * to elements passed to main. Returns converted int
{
    int index=0;
    int count = 0;
    int is_neg = 0;
    int position=0;
    int converted_int=0;
    while(argv[1][index] != '\0') //Count how many chars we're dealing with and check for valid input
    {
        if(argv[1][index] == '-')
        {
            is_neg = 1;
            index++;
        }
        else
        {
            if(isdigit(argv[1][index])) //Check chars. If char is not a digit, set error code to 1
            {
            index++;
            count++;
            }
            else
            {
                *ptr_err_code = 1;
                return 0;
            }

        }

    }
    index = 0;
    int int_array[count];
    while(argv[1][index] != '\0')
    {
        if(argv[1][index]=='-')
        {

            index++;
        }
        else
        {
            int_array[position] = (argv[1][index] - 48);
            index++;
            position++;
        }
    }
    int power = count;
    for(index=0;index<=count;index++,power--)
    {
        converted_int += int_array[index]*pow(10,(power-1));
    }

    if(is_neg)
        converted_int *= -1.0;
    printf("%d", converted_int);
    return converted_int;
}
