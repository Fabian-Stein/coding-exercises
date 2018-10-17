/*
Project Euler

Problem 10

 Summation of primes
  The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
  
Find the sum of all the primes below two million.
*/

#include <stdio.h>

//quadratic scaling
void primes_under(int max, int *arr, int *n)
{
    arr[0] = 2;
    
    int last = 3;
    
    int is_prime = 0;
    
    while (last < max)
    {
        for (int i = 0; i <= (*n); i++)
        {
            is_prime = 0;
            
            if (last % arr[i] == 0)
                break;
            is_prime = 1;
        }
        
        if (is_prime)
        {
            (*n)++;
            arr[*n] = last;
        }
        
        last++;
    }
}

void print_arr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d: %d\n", i, arr[i]);
}

int arr_sum(int *arr, int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
        res += arr[i];
    return res;
}

int main()
{
    int primes[500000];
    int n = 0;
    
    primes_under(2000000, primes, &n);
    
    //print_arr(primes + 10000, 10);
    
    printf("There are %d primes under 2000000\n", n);
    
    int res = arr_sum(primes, n);
    printf("The sum of all primes below is %d\n", res);
}
