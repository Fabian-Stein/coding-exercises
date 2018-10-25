/*
 Project Euler
 
 Problem 17
 
 Number letter counts
If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.
*/

#include <stdio.h>

int main()
{
    int number_words[10];
    
    number_words[0] = 3; //one
    number_words[1] = 3; //two 
    number_words[2] = 5; //three
    number_words[3] = 4; //four
    number_words[4] = 4; //five
    number_words[5] = 3; //six
    number_words[6] = 5; //seven
    number_words[7] = 5; //eight
    number_words[8] = 4; //nine
    
    int second_numbers[10];
    
    second_numbers[0] = 6; //eleven
    second_numbers[1] = 6; //twelve
    second_numbers[2] = 8; //thirteen
    
    int large_numbers[10];
    
    large_numbers[0] = 3; //ten
    large_numbers[1] = 6; //twenty
    large_numbers[2] = 6; //thirty
    
    
    
    int sum = 0;
    
    for (int i = 0; i < 10; i++)
    {
        int c = 0;
        
        if (i > 0)
        {
            c += 7; //hundred
            c += number_words[i-1];
        }
        
        for (int j = 0; j < 10; j++)
        {
            int c2 = c;
            
            if (j > 1 && j < 4)
            {
                c2 += large_numbers[j-1];
            }
            else if (j == 5 || j == 4)
            {
                c2 += 5; //fifty forty
            }
            else if (j == 8)
            {
                c2 += 6;
            }
            else if (j > 3)
            {
                c2 += number_words[j-1];
                c2 += 2; //..ty
            }
            
            for (int k = 0; k < 10; k++)
            {
                int c3 = c2;
                
                if (k > 0 && (j > 1 || j == 0))
                {
                    c3 += number_words[k-1];
                }
                else if (j == 1 && k == 0)
                {
                    c3 += 3; //ten
                }
                else if (k > 0 && j == 1)
                {
                    if (k > 0 && k < 4)
                    {
                        c3 += second_numbers[k-1];
                    } 
                    else if (k == 5)
                    {
                        c3 += 7;//fifteen
                    }
                    else if (k == 8)
                    {
                        c3 += 8;
                    }
                    else
                    {
                        c3 += number_words[k-1];
                        c3 += 4; //..teen
                    }
                }
                
                if (i > 0 && (j > 0 || k > 0))
                {
                    c3 += 3; //and
                }
                
                printf("%d: %d\n", i*100 + j*10 +k, c3);
                
                sum += c3;
            }
        }
    }
    
    sum += (3 + 8); //one thousand
    
    printf("The sum of the number strings from 1 to 1000 is %d\n", sum);
}

