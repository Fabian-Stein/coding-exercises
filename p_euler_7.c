/*

 Project Euler 
 
Problem 7

10001st prime
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10,001 st prime number?
*/

#include <stdio.h>

void primes(int *arr, int n)
{
    int n_primes = 1;
    arr[0] = 2;
    
    for (int i = 1; i < n;i++)
    {
        int p = arr[i-1] + 1;
        
        for (int j = 0; j <= i; j++)
        {
            if (j == i)
            {
                break;
            }
            
            if (p % arr[j] == 0)
            {
                p++;
                j = -1;
            }
        }
        arr[i] = p;
    }
}

void print_arr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d: %d\n", i, arr[i]);
}

int main()
{
    int first_primes[10001];
    
    primes(first_primes, 10001);
    
    //print_arr(first_primes, 10);
    int i = 10000;
    
    printf("the %d prime is %d\n", i+1, first_primes[i]);
}
