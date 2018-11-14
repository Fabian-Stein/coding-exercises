/*
Quadratic primes
Problem 27 
Euler discovered the remarkable quadratic formula:

n2+n+41

It turns out that the formula will produce 40 primes for the consecutive integer values 0≤n≤39. However, when n=40,402+40+41=40(40+1)+41 is divisible by 41, and certainly when n=41,412+41+41 is clearly divisible by 41.

The incredible formula n2−79n+1601 was discovered, which produces 80 primes for the consecutive values 0≤n≤79. The product of the coefficients, −79 and 1601, is −126479.

Considering quadratics of the form:

n2+an+b, where |a|<1000 and |b|≤1000 
where |n| is the modulus/absolute value of n, e.g. |11|=11 and |−4|=4

Find the product of the coefficients  a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n=0.
*/

#import <stdio.h>


//ugly brute force
int is_prime(int x)
{
    if (x < 2)
        return 0;
    
    for (int i = 2; i < x; i++)
    {
        if (x % i == 0)
            return 0;
    }
    
    //printf("%d\n", x);
    return 1;
    
}

int main()
{
    int max_n = 0;
    int max_a = 0;
    int max_b = 0;
    int max_res = 0;
    
    for (int a = -999; a < 1000; a++)
    {
        for (int b = -1000; b < 1001; b++)
        {
            for (int n = 0;;n++)
            {
                int res = n*n + a*n + b;
                
                if (!is_prime(res))
                {
                    if (n >= max_n)
                    {
                        max_a = a;
                        max_b = b;
                        max_n = n;
                    }
                    
                    //printf("res: %d, a:%d, b:%d, n:%d, product:%d\n", res, a,b,n, a*b);
                    break;
                }
            }
        }
    }
    
    printf("The product of the coefficients a = %d and b = %d is %d \n it produces %d primes with res %d\n", max_a, max_b, max_b*max_a, max_n, max_res);
}
