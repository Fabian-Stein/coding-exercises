/*
Project Euler

Problem 23

Non-abundant sums
A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
*/

#include <stdio.h>

int sum_of_devisors(int x)
{
    int sum = 0;
    
    for (int i = 1; i < x; i++)
    {
        if (x % i == 0)
            sum += i;
    }
    return sum;
}

int main()
{
    int abundant_numbers[28123];
    int n_abundant_numbers = 0;
    
    for (int i = 1; i < 28123; i++)
    {
        int temp = sum_of_devisors(i);
        
        if (temp > i)
        {
            abundant_numbers[n_abundant_numbers] = i;
            n_abundant_numbers++;
        }
    }
    
    for (int i = 0; i < n_abundant_numbers; i++)
        printf("%d: %d\n", i, abundant_numbers[i]);
    
    int sum = 0;
    
    for (int i = 1; i < 28123; i++)
    {
        int is_sum = 0;
        
        for (int j = 0; j < n_abundant_numbers; j++)
        {
            int first = abundant_numbers[j];
            
            for (int k = j; k < n_abundant_numbers; k++)
            {
                if (first + abundant_numbers[k] == i)
                {
                    is_sum = 1;
                    break;
                }
                
                if (first + abundant_numbers[k] > i)
                    break; //optimization
            }
            
            if (is_sum)
                break;
        }
        
        if (!is_sum)
            sum += i;
    }
    
    printf("The sum is %d\n", sum);
}