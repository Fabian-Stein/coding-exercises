/*
Self powers
Problem 48 
The series, 1e1 + 2e2 + 3e3 + ... + 10e10 = 10405071317.

Find the last ten digits of the series, 1e1 + 2e2 + 3e3 + ... + 1000e1000.
*/

#include <stdio.h>

int main()
{
    long long result = 0;
    
    //strategy: we can savely discart all digits above 10, because when multiplying with >1 the higher digits wont have any effects
    
    for (int i = 1; i < 1000; i++)
    {
        long long current = i;
        
        for (int j = 0; j < i-1; j++)
        {
            current = (current*(long long)i) % 10000000000;
        }
        result = (result + current) % 10000000000;
    }
    
    printf("The last 10 digits of the series are %lld\n", result);
}

