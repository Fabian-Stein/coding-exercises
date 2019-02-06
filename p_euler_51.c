/*
Prime digit replacements
Problem 51 
By replacing the 1st digit of the 2-digit number *3, it turns out that six of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.

By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number is the first example having seven primes among the ten generated numbers, yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993. Consequently 56003, being the first member of this family, is the smallest prime with this property.

Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits) with the same digit, is part of an eight prime value family.
*/

#include <stdio.h>

#define MAX_PRIMES 2000
int primes[MAX_PRIMES];
int n_primes;

void construct_primes()
{
    primes[0] = 2;
    for (n_primes = 1; n_primes < MAX_PRIMES; n_primes++)
    {
        int new_prime = primes[n_primes] + 2;
        for (;;new_prime++)
        {
            int i;
            for (i = 0; i < n_primes; i++)
            {
                if (new_prime % primes[i] == 0)
                    break;
            }
            if (i == n_primes)
            {
                primes[i] = new_prime;
                break;
            }
        }
    }
}

int is_prime(int x)
{
    for (int i = 0; i < n_primes; i++)
    {
        if (x % primes[i] == 0)
            return 0;
        if (x < primes[i])
            return 1;
    }
    return 1;
}

int replace_primes(int x)
{
    int digits[100] = {0};
    int n_digits = 0;
    
    while (x > 0)
    {
        digits[n_digits] = x % 10;
        x /= 10;
        n_digits++;
    }
    
    int result = 0;
    
    int digits_tested[100] = {0};
    for (int i = 0; i < n_digits; i++)
    {
        if (digits_tested[i] == 0)
        {
            int current_digits[100] = {0};
            int n_current_digits = 0;
            for (int j = i; j < n_digits; j++)
            {
                if (digits[j] == digits[i])
                {
                    digits_tested[j] = 1;
                    current_digits[j] = 1;
                    n_current_digits++;
                }
            }
            
            int primes_permutation = 0;
            for (int new_value = 0; new_value < 10; new_value++)
            {
                int permutation = 0;
                int factor = 1;
                for (int j = 0; j < n_digits; j++)
                {
                    if (current_digits[j])
                    {
                        permutation += new_value * factor;
                    }
                    else
                    {
                        permutation += digits[j] * factor;
                    }
                    factor *= 10;
                }
                
                //printf("%d\n", permutation);
                if (is_prime(permutation))
                {
                    //printf("%d\n", permutation);
                    primes_permutation++;
                }
            }
            
            if (primes_permutation > result)
                result = primes_permutation;
        }
    }
    return result;
}

int main()
{
    construct_primes();
    
    replace_primes(121313);
    
    int result;
    for (result = 2;; result++)
    {
        if (is_prime(result))
        {
            if (replace_primes(result) > 7)
            {
                break;
            }
        }
    }
    
    printf("The smallest prime, where replacing the digits with the same value yields 7 other primes is %d\n", result);
}