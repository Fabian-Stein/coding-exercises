/*
 Project Euler 
 
Problem 6

Sum square difference
The sum of the squares of the first ten natural numbers is,

12 + 22 + ... + 102 = 385
The square of the sum of the first ten natural numbers is,

(1 + 2 + ... + 10)2 = 552 = 3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

*/

#include <stdio.h>

int sum_of_squares(int n)
{
    int res = 0;
    
    for (int i = 1; i <= n; i++)
        res += i*i;
    
    return res;
}

int square_of_sum(int n)
{
    int res = 0;
    
    for (int i = 1; i <= n; i++)
        res += i;
    
    res *= res;
    
    return res;
}

int main()
{
    int s1 = sum_of_squares(100);
    int s2 = square_of_sum(100);
    
    printf("The difference is %d\n", s2-s1);
}


