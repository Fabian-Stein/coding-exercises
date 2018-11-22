/*
 Digit factorials
Problem 34 
145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

Find the sum of all numbers which are equal to the sum of the factorial of their digits.

Note: as 1! = 1 and 2! = 2 are not sums they are not included.
*/
#import <stdio.h>

int factorial(int x)
{
    int res = 1;
    
    for (; x > 0; x--)
    {
        res *= x;
    }
    
    return res;
}

int main()
{
    int sum = 0;
    
    
    /*
maximum sum of the factorials of the digits of a n-digit number

d1en + d2en-1 + ... + dn  >  d1! + d2! + ... + dn!
                       9en                       >  n * 9!
9en                       >  n * 362880
-> obviously true for n = 10
*/
    
    for (int i = 3; i < 100000; i++)
    {
        int c = i;
        int sum_of_fac = 0;
        
        while (c > 0)
        {
            sum_of_fac += factorial(c % 10);
            c /= 10;
            
            if (sum_of_fac > i)
                break;
        }
        
        if (sum_of_fac == i)
        {
            sum += sum_of_fac;
            printf("%d\n", sum_of_fac);
        }
        
    }
    
    printf("the sum of the numbers which are equal to the sum of there digits factorials is %d\n", sum);
}

