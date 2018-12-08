/*
Pandigital multiples
Problem 38 
Take the number 192 and multiply it by each of 1, 2, and 3:

192 × 1 = 192
192 × 2 = 384
192 × 3 = 576
By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3)

The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).

What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, ... , n) where n > 1?
*/

#import <stdio.h>

int is_pandigital(int x)
{
    if ((x < 123456789) || (x > 987654321))
        return 0;
    
    int digits[9] = {0};
    
    while (x > 0)
    {
        int m = x % 10;
        
        if (m == 0 || digits[m-1] == 1)
            return 0;
        
        digits[m-1] = 1;
        
        x /= 10;
    }
    
    for (int i = 0; i < 9; i++)
    {
        if (digits[i] == 0)
            return 0;
    }
    
    return 1;
}

int n_digits(int x)
{
    int res = 0;
    
    while (x > 0)
    {
        res += 1;
        x /= 10;
    }
    
    return res;
}

int ten_exp(int n)
{
    int res = 1;
    
    for (int i = 0; i < n; i++)
    {
        res *= 10;
    }
    
    return res;
}

int concatenated_product(int x, int n)
{
    int res = 0;
    int offset = 1;
    
    for (int i = n; i > 0; i--)
    {
        res += offset * (x * i);
        
        int d = n_digits(res);
        
        if (d > 9)
            return -1;
        else 
            offset = ten_exp(d);
    }
    
    return res;
}

int main()
{
    int res = 0;
    
    //get limit via small gauss
    // sum = (limit+1)*limit /2
    // sqrt(sum/2) < limit
    
    
    int test = concatenated_product(192, 3);
    
    if (is_pandigital(test))
        printf("%d\n", test);
    else
        printf("bla: %d\n", test);
    
    
    int LIMIT = 32000;
    for (int n = 2; n < LIMIT; n++)
    {
        for (int i = 1; ; i++)
        {
            int c = concatenated_product(i, n);
            
            
            if (c == -1)
                break;
            
            if (is_pandigital(c) && (c > res))
            {
                res = c;
                printf("%d\n", c);
            }
        }
    }
    
    printf("The largest 1 to 9 pandigital formed by a concatenated product is %d\n", res);
    
}