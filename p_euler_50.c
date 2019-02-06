/*
Consecutive prime sum
Problem 50 
The prime 41, can be written as the sum of six consecutive primes:

41 = 2 + 3 + 5 + 7 + 11 + 13
This is the longest sum of consecutive primes that adds to a prime below one-hundred.

The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.

Which prime, below one-million, can be written as the sum of the most consecutive primes?
*/

#include <stdio.h>

#define MAX_PRIMES 10000
int primes[MAX_PRIMES];
int n_primes;

void constuct_primes()
{
    primes[0] = 2;
    
    for (n_primes = 1; n_primes < MAX_PRIMES; n_primes++)
    {
        int new_prime = primes[n_primes] + 2;
        for (;; new_prime++)
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
                //printf("%d\n", new_prime);
                break;
            }
        }
        if (new_prime > 5000)
            break;
    }
}

int is_prime(int x)
{
    for (int i = 0; i < n_primes; i++)
    {
        if (x == primes[i])
            return 1;
        else if (x < primes[i])
            return 0;
    }
}

int is_large_prime(int x)
{
    for (int i = 0; i < n_primes; i++)
    {
        if (x % primes[i] == 0)
            return 0;
    }
    
    return 1;
}

int main()
{
    constuct_primes();
    
    int result = 0;
    
    int start_res = 0, end_res = 0;
    
    int start, end;
    for (start = 0; start < n_primes; start++)
    {
        int sum = 0;
        for (end = start; end < n_primes; end++)
        {
            if (sum + primes[end] > 1000000)
            {
                break;
            }
            sum += primes[end];
            
            if ((end_res - start_res) < (end - start) && 
                is_large_prime(sum))
            {
                start_res = start;
                end_res = end;
                result = sum;
            }
        }
    }
    
    printf("The sum of the %d primes", end_res - start_res + 1);
    for (int i = start_res; i < end_res + 1; i++)
        printf(" %d", primes[i]);
    printf(" is %d\n", result);
}