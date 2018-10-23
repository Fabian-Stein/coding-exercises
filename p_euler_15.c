/*
Project Euler

Problem 15

 Lattice paths
Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
How many such routes are there through a 20×20 grid?
*/

#import <stdio.h>

//same question: how many different 40 letter words consisting of 20 0s and 20 1s are there? -> non iterative solution
long long ways()
{
    //permutaions of 0 and 1s
    long long res = 1;
    int size = 40;
    
    while (size > 20)
    {
        res *= size/2;
        size--;
    }
    
    return res;
}


//iterative solution
long long ways_in_grid(int x, int y)
{
    if (x == 0 || y == 0)
    {
        return 1;
    }
    else 
    {
        long long down = ways_in_grid(x, y-1);
        long long right = ways_in_grid(x-1, y);
        
        return down + right;
    }
}

int main()
{
    int size = 20;
    long long a = ways();
    
    printf("There are %lld routes in a %d sized grid\n", a, size);
}

