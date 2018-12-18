/*
Pentagon numbers
Problem 44 
Pentagonal numbers are generated by the formula, Pn=n(3n−1)/2. The first ten pentagonal numbers are:

1, 5, 12, 22, 35, 51, 70, 92, 117, 145, ...

It can be seen that P4 + P7 = 22 + 70 = 92 = P8. However, their difference, 70 − 22 = 48, is not pentagonal.

Find the pair of pentagonal numbers, Pj and Pk, for which their sum and difference are pentagonal and D = |Pk − Pj| is minimised; what is the value of D?
*/

#import <stdio.h>

#define N_ITERATIONS 3000

int pentagonals[N_ITERATIONS];

int is_pentagonal(int x)
{
    // this has O(n) lookup time, can be reduced to O(log n), since the array is sorted
    for (int i = 0; i < N_ITERATIONS; i++)
    {
        if (pentagonals[i] == x)
            return 1;
        else if (pentagonals[i] > x)
            return 0;
    }
    
    return 0;
}

int main()
{
    int min_dif = 100000000;
    
    for (int i = 1; i < N_ITERATIONS+1; i++)
    {
        pentagonals[i-1] = (i*(3*i - 1))/2;
    }
    
    for (int i = 0; i < N_ITERATIONS; i++) 
    {
        for (int j = 0; j < i; j++)
        {
            int dif = pentagonals[i] - pentagonals[j];
            
            if (is_pentagonal(dif))
            {
                int sum = pentagonals[i] + pentagonals[j];
                
                if (is_pentagonal(sum) && dif < min_dif)
                {
                    printf("%d %d\n", dif ,sum);
                    min_dif = dif;
                }
            }
        }
    }
    
    printf("the minimum dif between pentagonal numbers, whose sum and difference ar penatagonal as well is %d\n", min_dif);
}