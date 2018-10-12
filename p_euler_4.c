/*
Project Euler 

Problem 4

Largest palindrome product
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

*/

#include <stdio.h>


void print_arr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d: %d\n", i, arr[i]);
}

int is_palindrom(int x)
{
    int digits[6] = {0};
    int n_digits = 0;
    
    for (int i = 0; i < 6; i++)
    {
        int p = 10;
        digits[i] = x % p;
        
        if (p > x)
        {
            n_digits = i;
            break;
        }
        x /= 10;
    }
    
    for (int i = 0; i < (n_digits+1)/2; i++)
    {
        int first = digits[n_digits - i];
        int last = digits[i];
        
        if (last != first)
            return 0;
    }
    
    return 1;
}



int main()
{
    int largest = 0;
    
    for (int i = 999; i >= 0; i--)
    {
        for (int j = 999; j >= 0; j--)
        {
            int res = i*j;
            if (is_palindrom(res))
            {
                //printf("%d\n", res);
                
                if (res > largest)
                {
                    largest = res;
                    break;
                }
            }
        }
    }
    
    printf("Largest palindrom is %d\n", largest);
}


