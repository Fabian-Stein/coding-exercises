/*
 Distinct primes factors
Problem 47 
The first two consecutive numbers to have two distinct prime factors are:

14 = 2 × 7
15 = 3 × 5

The first three consecutive numbers to have three distinct prime factors are:

644 = 2² × 7 × 23
645 = 3 × 5 × 43
646 = 2 × 17 × 19.

Find the first four consecutive integers to have four distinct prime factors each. What is the first of these numbers?
*/

#include <stdio.h>

#define MAX_PRIMES 4000
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

int has_four_prime_factors(int x)
{
    int distinct_prime_factors[4] = {0};
    int n_distinct_prime_factors = 0;
    
    int copy = x;
    
    for (int p = 0; x > 1 && p < MAX_PRIMES; p++)
    {
        while (x % primes[p] == 0)
        {
            x /= primes[p];
            distinct_prime_factors[n_distinct_prime_factors] = primes[p];
        }
        
        if (distinct_prime_factors[n_distinct_prime_factors])
            n_distinct_prime_factors++;
        
        if (n_distinct_prime_factors > 4)
            return 0;
    }
    
    if (n_distinct_prime_factors == 4)
    {
        /*
        printf("%d:", copy);
        for (int i = 0; i < 4; i++)
            printf(" %d", distinct_prime_factors[i]);
        printf("\n");
        */
        return 1;
    }
    else 
        return 0;
}

int consecutive_destinct_prime_factors(int x)
{
    for (int i = 0; i < 4; i++)
    {
        if (!has_four_prime_factors(x+i))
            return 0;
    }
    return 1;
}

int main()
{
    construct_primes();
    
    //for (int i = 0; i < n_primes; i++)
    //printf("%d\n", primes[i]);
    
    int result;
    
    for (result = 647;; result++)
    {
        if (consecutive_destinct_prime_factors(result))
        {
            break;
        }
    }
    
    printf("The first four consecutive integers with four destinct prime factors are %d %d %d %d\n", result, result+1, result+2, result+3);
}


