/*
Integer right triangles
Problem 39 
If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.

{20,48,52}, {24,45,51}, {30,40,50}

For which value of p ≤ 1000, is the number of solutions maximised?
*/

#import <stdio.h>

int sqrt_int(int x)
{
    //only works for ints, where a solution exists
    
    for (int i = 1; i <= x; i++)
    {
        if (i * i == x)
            return i;
        
        if (i * i > x)
            break;
    }
    
    return -1;
}

int main()
{
    int n_solutions[1001] = {0};
    
    int a,b,c;
    
    for (a = 1; a < 1000; a++)
    {
        for (b = 1; b < 1000; b++)
        {
            //printf("%de2 + %de2 = %d\n",a,b, a*a+b*b);
            c = sqrt_int(a*a + b*b);
            
            if (c == -1)
                continue;
            
            if (c + a + b > 1000)
                break;
            
            if (c + a + b <= 1000)
            {
                n_solutions[a+b+c] += 1;
            }
        }
    }
    
    int max_index = 0;
    
    for (int i = 1; i < 1001; i++)
    {
        if (n_solutions[max_index] < n_solutions[i])
            max_index = i;
    }
    
    printf("There are %d solutions for the triangle with the perimeter %d\n", n_solutions[max_index], max_index);
}
