/*
Pandigital prime
Problem 41 
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.

What is the largest n-digit pandigital prime that exists?
*/

#import <stdio.h>

int is_pandigital(int x)
{
    int digits[9] = {0};
    int n_digits = 0;
    
    
    
    while (x > 0)
    {
        int rest = x % 10;
        
        if (rest == 0)
        {
            return 0;
        }
        else if (digits[rest-1] == 1)
        {
            return 0;
        }
        else
        {
            //printf("%d\n", rest);
            digits[rest-1] = 1;
            n_digits++;
            x /= 10;
        }
    }
    
    for (int i = 0; i < n_digits; i++)
    {
        if (digits[i] == 0)
            return 0;
    }
    
    return 1;
}

int is_prime(int x)
{
    //brute force --> bad results if it is a prime, but this has to happen only once
    for (int i = 2; i < x; i++)
    {
        if (x % i == 0)
            return 0;
    }
    
    return 1;
}

int main()
{
    int res = 0;
    
    for (int i = 987654321; i > 2; i--)
    {
        if (is_pandigital(i))
        {
            //printf("%d\n", i);
            
            if (is_prime(i))
            {
                res = i;
                break;
            }
        }
    }
    
    printf("The largest pandigital that is also a prime is %d\n", res);
}