/*
 Project Euler
 
 Problem 20
 
 Factorial digit sum
n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
*/

#include <stdio.h>

int main()
{
    int digits[1000];
    digits[0] = 1;
    int n_digits = 1;
    
    for (int factor = 2; factor < 101; factor++)
    {
        int overhang = 0;
        
        int i;
        for (i = 0; i < 1000; i++)
        {
            int res = 0;
            
            if (n_digits >= i)
            {
                res = digits[i] * factor;
            }
            
            res += overhang;
            
            if (overhang == 0 && n_digits < i)
                break;
            
            overhang = res/10;
            digits[i] = res % 10;
        }
        
        n_digits = i;
    }
    
    int sum = 0;
    
    for (int i = 0; i < n_digits; i++)
        sum += digits[i];
    
    printf("the sum of the digits of 100! is %d\n", sum);
}
