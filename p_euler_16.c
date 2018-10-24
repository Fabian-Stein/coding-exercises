/*
 Project Euler
 
 Problem 16
 
 2e15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 
What is the sum of the digits of the number 2e1000?
*/
#include <stdio.h>
#include <math.h>

void double_number(int *number, int *n)
{
    int overhang = 0;
    int i = 0;
    
    while (i < (*n))
    {
        int r = number[i]*2 + overhang;
        
        if (r > 9)
        {
            overhang = r/10;
            number[i] = r % 10;
            
            if (i == (*n)-1)
            {
                (*n) += 1;
            }
        }
        else
        {
            overhang = 0;
            number[i] = r;
        }
        
        i++;
    }
}

int main()
{
    int number[1000];
    
    for (int i = 1; i < 1000; i++)
        number[i] = 0;
    
    number[0] = 1;
    
    int n_number = 1;
    
    for (int i = 0; i < 1000; i++)
    {
        double_number(number, &n_number);
    }
    
    int sum = 0;
    
    for (int i = 0; i < n_number; i++)
        sum += number[i];
    //printf("%d: %d\n", i, number[i]);
    
    
    printf("The sum of digits of 2e1000 is %d\n", sum);
    
}

