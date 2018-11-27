/*
  Permutational primes
  
The number, 13 is called permutable prime because a permutation of the digits: 31, is a prime.

There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

How many permutational primes are there below one million?
*/

#import <stdio.h>

int primes_under_million[100000];
int n_primes = 0;


int is_prime(int x)
{
    for (int i = 2; i < x; i++)
    {
        if (x % i == 0)
            return 0;
    }
    
    return 1;
}

void construct_primes()
{
    for (int i = 2; i < 1000000; i++)
    {
        if (is_prime(i))
        {
            primes_under_million[n_primes] = i;
            n_primes++;
        }
    }
}

int is_prime_fast(int x)
{
    
    for (int i = 0; i < n_primes; i++)
    {
        if (x < primes_under_million[i])
            return 0;
        
        if (x == primes_under_million[i])
            return 1;
        
        if (x % primes_under_million[i] == 0)
            return 0;
    }
}

void make_digits(int x, int *arr, int *n)
{
    int i;
    
    for (i = 0; x > 0; i++)
    {
        arr[i] = x % 10;
        x /= 10;
    }
    
    *n = 0;
}

int power(int base, int exp)
{
    int res = 1;
    
    for (int i = 0; i < exp; i++)
        res *= base;
    
    return res;
}

int check_permutations(int *arr, int n, int *set_digits, int was_changed)
{
    int permutable_elem = -1;
    int digits_to_set = 0;
    for (int j = 0; j < n; j++)
    {
        if (!set_digits[j])
            digits_to_set++;
        
        if (permutable_elem == -1 && set_digits[j] == 0)
            permutable_elem = j;
    }
    
    if (digits_to_set != 0)
    {
        //printf("Here\n");
        for (int i = 0; i < n; i++)
        {
            if (set_digits[i] == 0)
            {
                int temp = arr[i];
                arr[i] = arr[permutable_elem];
                arr[permutable_elem] = temp;
                
                set_digits[i] = 1;
                
                int d = 0;
                
                if (i != permutable_elem)
                {
                    d = 1;
                }
                
                int is_pr = check_permutations(arr, n, set_digits, was_changed + d);
                
                if (is_pr)
                    return 1;
                
                //reverse permutation
                set_digits[i] = 0;
                arr[permutable_elem] = arr[i];
                arr[i] = temp;
            }
        }
        return 0;
    }
    else 
    {
        if (was_changed)
        {
            int number = 0;
            
            for (int i = 0; i < n; i++)
            {
                number += arr[i] * power(10, i);
            }
            
            if (is_prime_fast(number))
            {
                printf("%d\n", number);
                return 1;
            }
            else 
                return 0;
        }
        else
        {
            return 0;
        }
    }
}

int permutation_is_prime(int x)
{
    int digits[6];
    int n_digits = 0;
    
    while (x > 0)
    {
        digits[n_digits] = x % 10;
        x /= 10;
        n_digits++;
    }
    
    int set_digits[6] = { 0 };
    
    return check_permutations(digits, n_digits, set_digits, 0);
}

int main()
{
    int n_permutational_primes = 0;
    
    construct_primes();
    
    for (int i = 2; i < 200; i++)
    {
        if (is_prime_fast(i))
        {
            if (i < 10)
                n_permutational_primes++;
            else if (permutation_is_prime(i))
                n_permutational_primes++;
        }
    }
    
    printf("There are %d permutational primes below 1000000\n", n_permutational_primes);
}


