/*
 Coin sums
Problem 31 
In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:

1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
It is possible to make £2 in the following way:

1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
How many different ways can £2 be made using any number of coins?
*/

#import <stdio.h>

int ways_for(int x, int n)
{
    int res = 0;
    
    if (x == 0)
    {
        return 1;
    }
    
    if (n == 0)
    {
        res += ways_for(x-200, 0);
        res += ways_for(x, 1);
    }
    else if (n == 1)
    {
        while (x >= 0)
        {
            res += ways_for(x, 2);
            x -= 100;
        }
    }
    else if (n == 2)
    {
        while (x >= 0)
        {
            res += ways_for(x, 3);
            x -= 50;
        }
    }
    else if (n == 3)
    {
        while (x >= 0)
        {
            res += ways_for(x, 4);
            x -= 20;
        }
    }
    else if (n == 4)
    {
        while(x >= 0)
        {
            res += ways_for(x, 5);
            x -= 10;
        }
    }
    else if (n == 5)
    {
        while(x >= 0)
        {
            res += ways_for(x, 6);
            x -= 5;
        }
    }
    else if (n == 6)
    {
        while(x >= 0)
        {
            res += ways_for(x, 7);
            x -= 2;
        }
    }
    else if (n == 7)
    {
        return 1;
    }
    
    return res;
}

int main()
{
    int ways = 0;
    
    ways = ways_for(200, 0);
    
    printf("There are %d different ways of getting 2 pound\n", ways);
}
