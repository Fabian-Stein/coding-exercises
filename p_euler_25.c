/*
Project Euler

Problem 25

1000-digit Fibonacci number
The Fibonacci sequence is defined by the recurrence relation:

Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
Hence the first 12 terms will be:

F1 = 1
F2 = 1
F3 = 2
F4 = 3
F5 = 5
F6 = 8
F7 = 13
F8 = 21
F9 = 34
F10 = 55
F11 = 89
F12 = 144
The 12th term, F12, is the first term to contain three digits.

What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
*/

#import <stdio.h>

void next_fib(int *first, int *second)
{
    int overhead = 0;
    
    for (int i = 999; i >= 0; i--)
    {
        int temp = second[i];
        
        int sum = overhead + first[i] + second[i];
        
        second[i] = sum % 10;
        overhead = sum / 10;
        
        first[i] = temp;
        
        printf("%d", second[i]);
        
        //if (overhead == 0 && second[i] == 0 && first[i] == 0)
        //break;
    }
    
    printf("\n");
}

int main()
{
    int first_fib[1000] = {0};
    int second_fib[1000] = {0};
    
    first_fib[999] = 1;
    second_fib[999] = 1;
    
    int index = 2;
    for (;;)
    {
        index++;
        next_fib(first_fib, second_fib);
        
        if (second_fib[0] > 0)
            break;
    }
    
    printf("The index of the first fibonacci number with a 1000 digits is %d\n", index);
}
