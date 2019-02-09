/*
Lychrel numbers
Problem 55 
If we take 47, reverse and add, 47 + 74 = 121, which is palindromic.

Not all numbers produce palindromes so quickly. For example,

349 + 943 = 1292,
1292 + 2921 = 4213
4213 + 3124 = 7337

That is, 349 took three iterations to arrive at a palindrome.

Although no one has proved it yet, it is thought that some numbers, like 196, never produce a palindrome. A number that never forms a palindrome through the reverse and add process is called a Lychrel number. Due to the theoretical nature of these numbers, and for the purpose of this problem, we shall assume that a number is Lychrel until proven otherwise. In addition you are given that for every number below ten-thousand, it will either (i) become a palindrome in less than fifty iterations, or, (ii) no one, with all the computing power that exists, has managed so far to map it to a palindrome. In fact, 10677 is the first number to be shown to require over fifty iterations before producing a palindrome: 4668731596684224866951378664 (53 iterations, 28-digits).

Surprisingly, there are palindromic numbers that are themselves Lychrel numbers; the first example is 4994.

How many Lychrel numbers are there below ten-thousand?

NOTE: Wording was modified slightly on 24 April 2007 to emphasise the theoretical nature of Lychrel numbers.
*/

#include <stdio.h>

int is_palindrom(char x[100], int n)
{
    for (int i = 0; i < n/2; i++)
    {
        if (x[i] != x[n-i-1])
            return 0;
    }
    return 1;
}

void add_with_reverse(char x[100], int *n)
{
    /*
    printf("x: ");
    for (int i = 0; i < *n; i++)
        printf("%d", x[i]);
    printf("\n");
    printf("r: ");
    for (int i = 0; i < *n; i++)
        printf("%d", x[*n - i - 1]);
    printf("\n");
    */
    
    char copy[100] = {0};
    for (int i = 0; i < *n; i++)
    {
        copy[i] = x[*n-i-1];
    }
    
    char overhang = 0;
    int i;
    for (i = 0; i < *n; i++)
    {
        char sum = overhang + x[i] + copy[i];
        x[i] = sum % 10;
        overhang = sum/10;
    }
    
    while (overhang > 0)
    {
        x[i] = overhang % 10;
        overhang /= 10;
        i++;
        (*n)++;
    }
}

int main()
{
    int result = 0;
    
    char number[100] = {0};
    int n_number = 0;
    
    for (int i = 1; i < 10000; i++)
    {
        n_number = 0;
        for (int j = 0; j < 100; j++)
            number[j] = 0;
        
        int copy_i = i;
        while (copy_i > 0)
        {
            number[n_number] = (char)(copy_i % 10);
            n_number++;
            copy_i /= 10;
        }
        
        int it;
        for (it = 0; it < 50; it++)
        {
            add_with_reverse(number, &n_number);
            if (is_palindrom(number, n_number))
            {
                break;
            }
        }
        if (it == 50)
            result++;
    }
    
    printf("There are %d Lychrel numbers\n", result);
}