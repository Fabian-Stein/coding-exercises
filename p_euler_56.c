/*
Powerful digit sum
Problem 56 
A googol (10e100) is a massive number: one followed by one-hundred zeros; 100e100 is almost unimaginably large: one followed by two-hundred zeros. Despite their size, the sum of the digits in each number is only 1.

Considering natural numbers of the form, aeb, where a, b < 100, what is the maximum digital sum?
*/

#include <stdio.h>

int sum_of_digits(int a, int b)
{
    char digits[200] = {0};
    digits[0] = 1;
    int n_digits = 1;
    
    for (int i = 0; i < b; i++)
    {
        int overhang = 0;
        for (int j = 0; j < n_digits; j++)
        {
            int c = digits[j]*a + overhang;
            digits[j] = c % 10;
            overhang = c/10;
        }
        
        while (overhang > 0)
        {
            digits[n_digits] = overhang % 10;
            overhang /= 10;
            n_digits++;
        }
    }
    
    int result = 0;
    for (int i = 0; i < n_digits; i++)
    {
        result += digits[i];
    }
    
    //printf("%de%d = %d\n", a, b, result);
    
    return result;
}

int main()
{
    int result = 0;
    
    int max_a, max_b;
    
    for (int a = 1; a < 100; a++)
    {
        for (int b = 1; b < 100; b++)
        {
            int s = sum_of_digits(a, b);
            if (s > result)
            {
                max_a = a;
                max_b = b;
                result = s;
            }
        }
    }
    printf("The maximum sum of the digits of aeb is %d (a:%d b:%d)\n", result, max_a, max_b);
    
}