/*
Truncatable primes
Problem 37 
The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.

Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
*/

#import <stdio.h>

int is_prime(int x)
{
    if (x < 2)
    {
        return 0;
    }
    
    for (int i = 2; i < x; i++)
    {
        if (x % i == 0)
            return 0;
    }
    
    return 1;
}

int truncations_are_prime(int x)
{
    int whole_x = x;
    int div = 10;
    
    x /= 10;
    int reverse_x = whole_x % div; 
    
    while (x > 0)
    {
        if (!(is_prime(reverse_x) && is_prime(x)))
            return 0;
        
        x /= 10;
        div *= 10;
        reverse_x = whole_x % div;
    }
    
    printf("%d\n", whole_x);
    
    return 1;
}

int main()
{
    int sum = 0;
    int n_truncables = 0;
    
    for (int i = 10; n_truncables < 11; i++)
    {
        if (is_prime(i))
        {
            if (truncations_are_prime(i))
            {
                sum += i;
                n_truncables++;
            }
        }
    }
    
    printf("The sum of the 11 truncable primes is %d\n", sum);
}