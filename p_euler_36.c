/*
 Double-base palindromes
Problem 36 
The decimal number, 585 = 1001001001 (binary), is palindromic in both bases.

Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

(Please note that the palindromic number, in either base, may not include leading zeros.)
*/

#import <stdio.h>

int is_palindrom(int x)
{
    int digits[7];
    int n_digits = 0;
    
    while (x > 0)
    {
        digits[n_digits] = x % 10;
        n_digits++;
        x /= 10;
    }
    
    for (int i = 0; i < n_digits/2; i++)
    {
        if (digits[i] != digits[n_digits-i-1])
            return 0;
    }
    
    return 1;
}

int is_base2_palindrom(int x)
{
    int digits[20];
    int n_digits = 0;
    
    while (x > 0)
    {
        digits[n_digits] = x % 2;
        n_digits++;
        x /= 2;
    }
    
    for (int i = 0; i < n_digits/2; i++)
    {
        if (digits[i] != digits[n_digits-i-1])
            return 0;
    }
    
    for (int i = 0; i < n_digits; i++)
        printf("%d", digits[i]);
    
    return 1;
}

int main()
{
    int sum = 0;
    
    for (int i = 1; i < 1000000; i++)
    {
        if (is_palindrom(i))
        {
            if (is_base2_palindrom(i))
            {
                printf(" = %d\n", i);
                sum += i;
            }
        }
    }
    
    
    printf("The sum of all palindroms in base 10 and 2 (under a million) is %d\n", sum);
}