/*
Champernowne's constant
Problem 40 
An irrational decimal fraction is created by concatenating the positive integers:

0.123456789101112131415161718192021...

It can be seen that the 12th digit of the fractional part is 1.

If dn represents the nth digit of the fractional part, find the value of the following expression.

d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000
*/

#import <stdio.h>

int main()
{
    int digits[7];
    int n_digits = 0;
    
    int next = 10;
    
    int factor = 1;
    int counter = 1;
    
    for(int i = 1; n_digits < 7; i++)
    {
        int temp = i;
        
        for (int p = 10; p <= next; p *= 10)
        {
            int res = temp / (next/p);
            
            temp %= next/p;
            
            if (i < 105)
                printf("%d\n", res);
            
            
            if (counter == factor)
            {
                //printf("%d\n", res);
                digits[n_digits] = res;
                factor *= 10;
                n_digits++;
            }
            
            counter++;
        }
        
        if (i+1 == next)
            next *= 10;
        
    }
    
    int product = 1;
    
    for (int i = 1; i < 7; i++)
    {
        product *= digits[i];
    }
    
    printf("The product of d1, d10, ... is %d\n", product);
}