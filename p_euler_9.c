/*
Project Euler

Problem 9

 Special Pythagorean triplet
 
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a2 + b2 = c2
For example, 32 + 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/
#include <stdio.h>

int main()
{
    int a = 0, b = 0, c = 0;
    
    for (a=0; a<500; a++)
    {
        for (b=a; b<500; b++)
        {
            if (a + b + c > 1000)
                break;
            
            
            for (c=b; c<1000; c++)
            {
                if (a + b + c > 1000)
                    break;
                
                if (a + b + c == 1000 && a*a + b*b == c*c)
                    goto res;
            }
            c = 0;
        }
        b = 0;
    }
    
    res:
    printf("a: %d, b: %d, c: %d\n", a, b, c);
}