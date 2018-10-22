/*
 Project Euler
 
 Problem 14
 
 Longest Collatz sequence
The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
*/

#include <stdio.h>

void collatz_sequence(int x, int *sequence, int *n)
{
    int i = 0;
    
    while (x != 1)
    {
        sequence[i] = x;
        
        if (x % 2 == 0)
        {
            x /= 2;
        } 
        else
        {
            x = 3*x + 1;
        }
        
        i++;
    }
    
    sequence[i] = x;
    i++;
    printf("%d\n", i);
    
    *n = i;
}

int main()
{
    int sequence[1000000];
    int n_sequence = 0;
    
    int c_sequence[1000000];
    int c_n_sequence = 0;
    
    for (int i = 1; i < 200000; i++)
    {
        
        collatz_sequence(i, c_sequence, &c_n_sequence);
        
        if (c_n_sequence > n_sequence)
        {
            for (int j = 0; j < c_n_sequence; j++)
            {
                sequence[j] = c_sequence[j];
            }
            n_sequence = c_n_sequence;
        }
    }
    
    for (int i = 0; i < n_sequence; i++)
        printf("%d: %d\n", i, sequence[i]);
}