/*
Spiral primes
Problem 58 
Starting with 1 and spiralling anticlockwise in the following way, a square spiral with side length 7 is formed.

37 36 35 34 33 32 31
38 17 16 15 14 13 30
39 18  5  4  3 12 29
40 19  6  1  2 11 28
41 20  7  8  9 10 27
42 21 22 23 24 25 26
43 44 45 46 47 48 49

It is interesting to note that the odd squares lie along the bottom right diagonal, but what is more interesting is that 8 out of the 13 numbers lying along both diagonals are prime; that is, a ratio of 8/13 ≈ 62%.

If one complete new layer is wrapped around the spiral above, a square spiral with side length 9 will be formed. If this process is continued, what is the side length of the square spiral for which the ratio of primes along both diagonals first falls below 10%?
*/

#include <stdio.h>

#define MAX_PRIMES 10000
int primes[MAX_PRIMES];

void construct_primes()
{
    primes[0] = 2;
    for (int i = 1; i < MAX_PRIMES; i++)
    {
        int new_prime = primes[i-1] + 1;
        for (;;new_prime++)
        {
            int is_prime = 0;
            for (int j = 0; j < i; j++)
            {
                if (new_prime % primes[j] == 0)
                {
                    break;
                }
                
                if (new_prime < primes[j] * primes[j])
                {
                    is_prime = 1;
                    //printf("%d\n", new_prime);
                    break;
                }
            }
            if (is_prime)
            {
                break;
            }
        }
        primes[i] = new_prime;
    }
}

int is_prime(int x)
{
    for (int i = 0; i < MAX_PRIMES; i++)
    {
        if (x % primes[i] == 0)
            return 0;
        if (x < primes[i]*primes[i])
            return 1;
    }
    return 1;
}

int main()
{
    construct_primes();
    
    int n_primes = 0;
    int n_diagonals = 0;
    
    int n_sides;
    int i = 2;
    for (n_sides = 3;; n_sides += 2)
    {
        int c = i;
        for (; i <= n_sides*n_sides; i++)
        {
            if ((i - c + 1) % (n_sides - 1) == 0) // is diagonal
            {
                n_diagonals++;
                //printf("%d \n", i);
                if (is_prime(i))
                {
                    n_primes++;
                }
            }
        }
        if (10 * n_primes < n_diagonals)
        {
            break;
        }
    }
    printf("The side length of the spiral, where the number of primes on the diagonals is less than 10 percent of the number of  numbers on the diagonals %d\n", n_sides - 2);
}