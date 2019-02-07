/*
Permuted multiples
Problem 52 
It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.

Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.
*/

#include <stdio.h>

int multiplier_have_same_digits(int x)
{
    int digits[20] = {0};
    int n_digits = 0;
    
    int copy_x = x;
    while (copy_x > 0)
    {
        digits[n_digits] = copy_x % 10;
        n_digits++;
        copy_x /= 10;
    }
    
    for (int multiplier = 2; multiplier < 7; multiplier++)
    {
        int product = multiplier*x;
        
        int product_digits[20] = {0};
        int n_product_digits = 0;
        while (product > 0)
        {
            product_digits[n_product_digits] = product % 10;
            n_product_digits++;
            product /= 10;
        }
        
        int digits_already_used[20] = {0};
        for (int i = 0; i < n_digits; i++)
        {
            int j;
            for (j = 0; j < n_product_digits; j++)
            {
                if (digits[i] == product_digits[j] && digits_already_used[j] == 0)
                {
                    digits_already_used[j] = 1;
                    break;
                }
            }
            if (j == n_product_digits)
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int result;
    for (int i = 100000; ;i++)
    {
        if (multiplier_have_same_digits(i))
        {
            result = i;
            break;
        }
    }
    
    printf("The smallest integer, which multipliers contain the same digits is %d\n", result);
}

