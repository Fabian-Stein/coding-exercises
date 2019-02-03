/*
 Goldbach's other conjecture
Problem 46 
It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.

9  = 7  + 2×1e2
15 = 7  + 2×2e2
21 = 3  + 2×3e2
25 = 7  + 2×3e2
27 = 19 + 2×2e2
33 = 31 + 2×1e2

It turns out that the conjecture was false.

What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?
*/

#include <stdio.h>

#define MAX_PRIMES 20000
int primes[MAX_PRIMES];
int n_primes = 0;

void construct_primes()
{
    primes[0] = 2;
    
    for (n_primes = 1; n_primes < MAX_PRIMES; n_primes++)
    {
        int new_prime = primes[n_primes-1] + 1;
        
        for (;;new_prime++)
        {
            int i;
            for (i = 0; i < n_primes; i++)
            {
                if (new_prime % primes[i] == 0)
                {
                    break;
                }
            }
            if (i == n_primes)
            {
                primes[n_primes] = new_prime;
                break;
            }
        }
    }
}

int is_composite(int x)
{
    for (int i = 0; i < n_primes; i++)
    {
        if (x <= primes[i])
            return 0;
        if (x % primes[i] == 0)
            return 1;
    }
    
    return 0;
}

int has_goldbach_construction(int x)
{
    for (int i = 0; primes[i] < x; i++)
    {
        int j;
        for (int j = 1; primes[i] + 2*j*j <= x; j++)
        {
            if (x == primes[i] + 2*j*j)
                return 1;
        }
    }
    return 0;
}

int main()
{
    construct_primes();
    
    int result;
    for (result = 9;; result += 2)
    {
        if (is_composite(result))
        {
            if (!has_goldbach_construction(result))
            {
                break;
            }
        }
    }
    
    printf("The smallest odd composite which can not be written as the sum of a prime and twice a square is %d\n", result);
}