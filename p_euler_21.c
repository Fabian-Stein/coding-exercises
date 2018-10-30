/*
Project Euler

Problem 21

 Amicable numbers
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.
*/

#import <stdio.h>

int devisors(int x, int arr[])
{
    //Brute force
    
    int n = 0;
    
    for (int i = 1; i < x; i++)
    {
        if (x % i == 0)
        {
            arr[n] = i;
            n++;
        }
    }
    
    return n;
}

int arr_sum(int arr[], int n)
{
    int res = 0;
    
    for (int i = 0; i < n; i++)
        res += arr[i];
    
    return res;
}

int main()
{
    int dev_arr[9999][30];
    int n_dev[9999]; 
    
    for (int i = 0; i < 9999; i++)
        n_dev[i] = devisors(i+1, dev_arr[i]);
    
    int sum = 0;
    
    int sum_devisors[9999];
    
    for (int i = 0; i < 9999; i++)
        sum_devisors[i] = arr_sum(dev_arr[i], n_dev[i]);
    /*
    test
    for (int i = 0; i < n_dev[219]; i++)
        printf("%d: %d\n", i, dev_arr[219][i]);
    */
    
    int amicable_numbers[1000];
    int n_amicable = 0;
    
    for (int i = 0; i < 9999; i++)
    {
        for (int j = 0; j < 9999; j++)
        {
            if (sum_devisors[i] == j+1 && sum_devisors[j] == i+1 && i != j)
            {
                amicable_numbers[n_amicable] = i+1;
                n_amicable++;
                sum += i+1;
                break;
            }
        }
    }
    
    for (int i = 0; i < n_amicable; i++)
        printf("%d: %d\n", i, amicable_numbers[i]);
    
    printf("The sum of all amicable numbers is %d\n", sum);
}
