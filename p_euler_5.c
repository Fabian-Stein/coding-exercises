/*
Project Euler 

Problem 5

Smallest multiple
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

#include "stdio.h"

void print_arr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d: %d \n", i, arr[i]);
}

void prime_factors(int x, int *p_factors, int *n)
{
    int i = 2;
    while (x > 1)
    {
        if (x % i == 0)
        {
            p_factors[*n] = i;
            x /= i;
            (*n)++;
        }
        else
        {
            i++;
        }
    }
    print_arr(p_factors, *n);
}

int main()
{
    int res = 1;
    
    for (int i = 1; i <= 20; i++)
    {
        int p_factors[10];
        int n = 0;
        
        prime_factors(i, p_factors, &n);
        
        int temp = res;
        
        for (int j = 0; j < n; j++)
        {
            if (temp % p_factors[j] == 0)
            {
                temp /= p_factors[j];
            }
            else
            {
                res *= p_factors[j];
            }
            
        }
    }
    printf("the smallest number: %d\n", res);
}