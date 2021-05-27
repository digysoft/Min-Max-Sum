/******************************************************************************

                            DigySoft E.I.R.L
                              C++ Compiler

Program: Mini-Max Sum
Author: Jose Vidal
E-mail: jvidalsm@gmail.com
Date: 27/05/2021
Version: 1.0.0

Description:
Given five positive integers, find the minimum and maximum values that can be
calculated by summing exactly four of the five integers.
Then print the respective minimum and maximum values as a single line of two
space-separated long integers.
*******************************************************************************/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

enum{MAX_NUMBERS=5};

int main()
{
    std::string input_int;
    long int digitos[MAX_NUMBERS];
    char* digit_str;
    long int sum_min=0;
    long int sum_max=0;
    long int sum=0;

    getline (std::cin, input_int);

    int j=0;
    int isDigit = 0;
    int z=0;
    digit_str = (char*) malloc (strlen(input_int.c_str()));
    memset(digit_str,0,strlen(input_int.c_str()));
    for (int i=0; i<(int)strlen(input_int.c_str()); i++)
    {
        if (input_int.at(i) >= 48 && input_int.at(i) <= 57)
        {
            digit_str[z] = input_int.at(i);
            digitos[j] = atoi(digit_str);
            isDigit = 1;
            z++;
        }
        else if (input_int.at(i) == 32 && isDigit == 1)
        {
            memset(digit_str,0,strlen(input_int.c_str()));
            isDigit = 0;
            z = 0;
            j++;
            if (j == MAX_NUMBERS) break;
        }
    }

    for (int i=0; i<MAX_NUMBERS; i++)
    {
        sum = 0;
        for (int x=0; x<MAX_NUMBERS; x++)
        {
            if (i != x)
            {
                sum += digitos[x];
            }
        }
        if (i == 0)
        {
            sum_min = sum;
            sum_max = sum;
        }
        if (sum > sum_max) sum_max = sum;
        if (sum < sum_min) sum_min = sum;
    }

    std::cout<<sum_min<<" "<<sum_max;

    free(digit_str);
    return 0;
}
