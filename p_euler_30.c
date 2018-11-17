/*
 Digit fifth powers
Problem 30 
Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

1634 = 1e4 + 6e4 + 3e4 + 4e4
8208 = 8e4 + 2e4 + 0e4 + 8e4
9474 = 9e4 + 4e4 + 7e4 + 4e4
As 1 = 1e4 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
*/

#import <stdio.h>

int power_of_five(int x)
{
    return x * x * x * x * x;
}

int main()
{
    int sum = 0;
    
    /*
How to find a min limit, where the equation doesnt work:

    Normal number              nn  = d1 * 10eN + d2* 10eN-1  + ... + dN
    max constructed number     mcn = d1e5 + d2e5 + ... + dNe5
    
when is                        d1 * 10eN > mcn
     d1 > 1, di < 10 -->                 10eN > N * 10e5
     try N == 6                          10e6 > 6 * 10e5 
     
q.e.d
    */
    
    for (int i = 2; i < 1000000;i++)
    {
        int c = i;
        int res = 0;
        
        while (c > 0)
        {
            res += power_of_five(c % 10);
            c /= 10;
            
            if (res > i)
                break; 
        }
        
        if (res == i)
        {
            sum += res;
            printf("%d\n", res);
        }
    }
    
    printf("The sum of the numbers that can be written as the fifth powers of their digits is %d\n", sum);
}
