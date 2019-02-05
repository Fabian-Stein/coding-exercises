/*
 Prime permutations
Problem 49 
The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways: (i) each of the three terms are prime, and, (ii) each of the 4-digit numbers are permutations of one another.

There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit increasing sequence.

What 12-digit number do you form by concatenating the three terms in this sequence?
*/

#include <stdio.h>

#define MAX_PRIME 1500
int primes[MAX_PRIME];
int n_primes = 0;


void construct_primes()
{
    primes[n_primes] = 2;
    
    for (n_primes = 1; n_primes < MAX_PRIME; n_primes++)
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
    //can be inproved to log(n) complexity (binary search)
    for (int i = 0; i < n_primes; i++)
    {
        if (x == primes[i])
            return 1;
        else if (x < primes[i])
            return 0;
    }
}

int are_permutations(int x, int y, int z)
{
    int digits[4];
    int digits_y[4];
    int digits_z[4];
    
    for (int i = 0; i < 4; i++)
    {
        digits[i] = x % 10;
        x /= 10;
        digits_y[i] = y % 10;
        y /= 10;
        digits_z[i] = z % 10;
        z /= 10;
    }
    
    int digits_y_test[4] = {0};
    int digits_z_test[4] = {0};
    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (digits[i] == digits_y[j])
                digits_y_test[j] = 1;
            if (digits[i] == digits_z[j])
                digits_z_test[j] = 1;
        }
    }
    
    for (int i = 0; i < 4; i++)
    {
        if (!digits_z_test[i])
            return 0;
        if (!digits_y_test[i])
            return 0;
    }
    
    return 1;
}

int main()
{
    construct_primes();
    
    for (int i = 1000; i < 10000 - (2*3330); i++)
    {
        //2*dif + i < 10000
        if (is_prime(i) && is_prime(i + 3330) && is_prime(i + 2*3330))
        {
            if (are_permutations(i, i + 3330, i + 2*3330))
                printf("The three primes are %d %d %d \n", i, i + 3330, i + 2*3330);
        }
    }
}


