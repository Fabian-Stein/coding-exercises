/*
Square root convergents
Problem 57 
It is possible to show that the square root of two can be expressed as an infinite continued fraction.

√ 2 = 1 + 1/(2 + 1/(2 + 1/(2 + ... ))) = 1.414213...
    
By expanding this for the first four iterations, we get:

1 + 1/2 = 3/2 = 1.5
1 + 1/(2 + 1/2) = 7/5 = 1.4
1 + 1/(2 + 1/(2 + 1/2)) = 17/12 = 1.41666...
1 + 1/(2 + 1/(2 + 1/(2 + 1/2))) = 41/29 = 1.41379...

The next three expansions are 99/70, 239/169, and 577/408, but the eighth expansion, 1393/985, is the first example where the number of digits in the numerator exceeds the number of digits in the denominator.

In the first one-thousand expansions, how many fractions contain a numerator with more digits than denominator?
*/

#include <stdio.h>

void add_to_first(char first[], char second[], int *n_first, int n_second)
{
    int max;
    
    if (*n_first > n_second)
    {
        max = *n_first;
    }
    else
    {
        max = n_second;
    }
    
    int overhang = 0;
    for (int i = 0; i < max; i++)
    {
        int sum = first[i] + second[i] + overhang;
        first[i] = sum % 10;
        overhang = sum/10;
    }
    *n_first = max;
    
    while (overhang > 0)
    {
        first[*n_first] = overhang;
        overhang /= 10;
        (*n_first)++;
    }
}

void copy_arr(char from[], char to[], int n)
{
    for (int i = 0; i < n; i++)
        to[i] = from[i];
}

int main()
{
    int result = 0;
    
    //digits: 1000/3 = 333
    char numerator[500] = {0};
    numerator[0] = 1;
    int n_numerator = 1;
    char denominator[500] = {0};
    denominator[0] = 2;
    int n_denominator = 1;
    char temp[500] = {0};
    int n_temp;
    
    for (int i = 0; i < 1000; i++)
    {
        
        copy_arr(denominator, temp, n_denominator);
        n_temp = n_denominator;
        add_to_first(denominator, denominator, &n_denominator, n_denominator);
        add_to_first(denominator, numerator, &n_denominator, n_numerator);
        copy_arr(temp, numerator, n_temp);
        n_numerator = n_temp;
        
        
        char c[500] = {0};
        int n_c = n_numerator;
        copy_arr(numerator, c, n_numerator);
        add_to_first(c, denominator, &n_c, n_denominator);
        
        if (n_c > n_denominator)
            result++;
        
        
        for (int i = 0; i < n_c; i++)
            printf("%d", c[n_c - i - 1]);
        
        printf("/");
        
        for (int i = 0; i < n_denominator; i++)
            printf("%d", denominator[n_denominator - i - 1]);
        printf("\n");
        /*
        printf("%d: %lld/%lld\n", i, c_n, c_d);
        
        while (c_d > 0)
        {
            c_d /= 10;
            c_n /= 10;
        }
        
        if (c_n > 0)
        {
            result++;
        }
    }
    
    */
    }
    printf("In the first thousand expansions of the square root convergence there are %d expansions with more digits in the numerator than in the denominator\n", result);
}