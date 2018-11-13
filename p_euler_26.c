/*
Reciprocal cycles
Problem 26 
A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:

1/2	= 	0.5
1/3	= 	0.(3)
1/4	= 	0.25
1/5	= 	0.2
1/6	= 	0.1(6)
1/7	= 	0.(142857)
1/8	= 	0.125
1/9	= 	0.(1)
1/10	= 	0.1

Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
*/

#import <stdio.h>

int main()
{
    int max_cycles = 0;
    int d = 0;
    
    for (int i = 2; i < 1000; i++)
    {
        int c[1000] = {0};
        int index = 0;
        int r = 10;
        int rests[1000] = {0};
        int do_break = 0;
        
        for (;;)
        {
            c[index] = r/i;
            
            r = (r % i)*10;
            rests[index] = r;
            
            for (int j = 0; j < index; j++)
            {
                if (r == rests[j])
                {
                    do_break = 1;
                    
                    if (index - j > max_cycles)
                    {
                        max_cycles = index - j;
                        d = i;
                    }
                    break;
                }
            }
            
            if (do_break)
            {
                do_break = 0;
                break;
            }
            
            if (r == 0)
            {
                break;
            }
            
            if (index == 999)
                break;
            
            index++;
        }
        
        //for (int j = 0; j < index+1; j++)
        //printf("%d", c[j]);
        
        //printf("\n");
    }
    
    printf("The largest recurring cycle %d is part of 1/%d \n", max_cycles, d);
}
