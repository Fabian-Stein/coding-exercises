/*
 Pandigital products
Problem 32 
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.

The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.

HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.
*/

#import <stdio.h>

int sum(int *arr, int n)
{
    int res = 0;
    
    for (int i = 0; i < n; i++)
    {
        res *= 10;
        res += arr[i];
    }
    
    return res;
}

int get_n_free(int *arr, int n)
{
    int i;
    int free_indexes = 0;
    
    for (i = 0; i < 9; i++)
    {
        if (arr[i] == 0)
            free_indexes++;
        
        if (n == free_indexes - 1)
            break;
    }
    
    //printf("%d", i);
    
    return i;
}

int pandigitals[100000] = {0};

void add(int x)
{
    int i;
    int n = 0;
    
    for (i = 0; i < 100000; i++)
    {
        if (pandigitals[i] == x)
        {
            n = 1;
            break;
        }
        
        if (pandigitals[i] == 0)
            break;
    }
    
    if (!n)
        pandigitals[i] = x;
}

int sum_x()
{
    int res = 0;
    
    for (int i = 0; i < 100000; i++)
    {
        res += pandigitals[i];
    }
    
    return res;
}

int main()
{
    //A 1 through 9 pandigital has 0 digits (da)
    //There are 9! pandigitals -> iterate through them, check if they are a valid product
    
    int arr[9] = {0};
    
    for (int i = 0; i < 9; i++)
    {
        arr[i] = 1;
        
        for (int i1 = 0; i1 < 8; i1++)
        {
            int index_1 = get_n_free(arr, i1);
            arr[index_1] = 2;
            
            for (int i2 = 0; i2 < 7; i2++)
            {
                int index_2 = get_n_free(arr, i2);
                arr[index_2] = 3;
                
                for (int i3 = 0; i3 < 6; i3++)
                {
                    int index_3 = get_n_free(arr, i3);
                    arr[index_3] = 4;
                    
                    for (int i4 = 0; i4 < 5; i4++)
                    {
                        int index_4 = get_n_free(arr, i4);
                        arr[index_4] = 5;
                        
                        for (int i5 = 0; i5 < 4; i5++)
                        {
                            int index_5 = get_n_free(arr, i5);
                            arr[index_5] = 6;
                            
                            for (int i6 = 0; i6 < 3; i6++)
                            {
                                int index_6 = get_n_free(arr, i6);
                                arr[index_6] = 7;
                                
                                for (int i7 = 0; i7 < 2; i7++)
                                {
                                    int index_7 = get_n_free(arr, i7);
                                    arr[index_7] = 8;
                                    
                                    int index_8 = get_n_free(arr, 0);
                                    arr[index_8] = 9;
                                    
                                    for (int j = 0; j < 7; j++)
                                    {
                                        int multiplicant = sum(arr, j+1);
                                        
                                        for (int k = j+1; k < 8; k++)
                                        {
                                            int multiplier = sum(arr+j+1, k-j);
                                            int product = sum(arr+k+1, 8-k);
                                            
                                            /*
                                            for (int l = 0; l < 9; l++)
                                                printf("%d", arr[l]);
                                                
                                            printf("\n");
                                            
                                            printf("%d x %d = %d\n", multiplicant, multiplier, product);
                                            */
                                            if (multiplicant * multiplier == product)
                                            {
                                                // this is a pandigital
                                                add(product);
                                            }
                                        }
                                    }
                                    
                                    /*
                                    for (int l = 0; l < 9; l++)
                                        printf("%d", arr[l]);
                                        
                                    printf("\n");
                                    */
                                    
                                    arr[index_8] = 0;
                                    arr[index_7] = 0;
                                }
                                arr[index_6] = 0;
                            }
                            arr[index_5] = 0;
                        }
                        arr[index_4] = 0;
                    }
                    arr[index_3] = 0;
                }
                arr[index_2] = 0;
            }
            arr[index_1] = 0;
        }
        arr[i] = 0;
    }
    
    printf("the sum of the products of all 1 through 9 pandigitals is %d\n", sum_x());
    
}
