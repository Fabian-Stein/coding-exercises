/*
Combinatoric selections
Problem 53 
There are exactly ten ways of selecting three from five, 12345:

123, 124, 125, 134, 135, 145, 234, 235, 245, and 345

In combinatorics, we use the notation, 5C3 = 10.

In general,

nCr = n!/r!(n−r)! ,where r ≤ n, n! = n×(n−1)×...×3×2×1, and 0! = 1.
It is not until n = 23, that a value exceeds one-million: 23C10 = 1144066.

How many, not necessarily distinct, values of  nCr, for 1 ≤ n ≤ 100, are greater than one-million?
*/

#include <stdio.h>

int fac(int x)
{
    int result = 1;
    while (x > 0)
    {
        result *= x;
        x--;
    }
    return result;
}

int nCr(int n, int r)
{
    float res = 1.0;
    if (r > n-r)
    {
        int div = n-r;
        int i;
        for(i = n; i > r; i--)
        {
            res *= i;
            if (div > 0)
            {
                res /= (float)div;
                div--;
            }
        }
    }
    else 
    {
        int div = r;
        int i;
        for(i = n; i > n-r; i--)
        {
            res *= i;
            if (div > 0)
            {
                res /= (float)div;
                div--;
            }
        }
    }
    
    return (int)res;
}

int main()
{
    int count = 0;
    for (int n = 1; n < 101; n++)
    {
        for (int r = 1; r < n+1; r++)
        {
            int c = nCr(n,r);
            printf("%dC%d: %d\n", n, r, c);
            if (c > 1000000)
            {
                count += n - 1 - 2*(r - 1);
                break;
            }
        }
    }
    printf("There are %d nCr greater than one million\n", count);
}