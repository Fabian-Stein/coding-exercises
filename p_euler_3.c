/*
Project Euler

Problem 3

Largest prime factor

The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?

quick and dirty
*/

#import <stdio.h>

//Very inefficient naive implentation
int primes[1000];
int n_primes = 0;

void setup_primes(int number)
{
    int c = 2;
    primes[0] = c;
    
    
    for (int i = 1; i < number; i++)
    {
        int is_devisable = 1;
        
        while (is_devisable)
        {
            c++;
            for (int j = 0; j <= i; j++){
                if (j == i)
                {
                    is_devisable = 0;
                    break;
                }
                
                if (c % primes[j] == 0)
                    break;
            }
        }
        primes[i] = c;
    }
    n_primes = number-1;
}

void print_arr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d: %d \n", i, arr[i]);
}

int find_largest_prime(long int x)
{
    for (int i = n_primes; i >= 0; i--)
    {
        if (x % primes[i] == 0)
        {
            return primes[i];
        }
    }
    
    return 0;
}

int main()
{
    setup_primes(1000);
    //print_arr(primes, n_primes);
    
    printf("largest prime: %d \n", find_largest_prime(600851475143));
}


