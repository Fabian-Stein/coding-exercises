/*
 Digit cancelling fractions
Problem 33 
The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.

We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.

If the product of these four fractions is given in its lowest common terms, find the value of the denominator.
*/

#import <stdio.h>

typedef struct
{
    int numerator;
    int denominator;
} t_fraction;

int fractions_are_equal(int num1, int denom1, int num2, int denom2)
{
    //not precise
    float d = (float)num1/(float)denom1 - (float)num2/(float)denom2;
    
    if (d > -0.001 && d < 0.001)
        return 1;
    else
        return 0;
}

t_fraction multiply_and_reduce(t_fraction first, t_fraction second)
{
    t_fraction res = {0,0};
    
    res.numerator = first.numerator * second.numerator;
    res.denominator = first.denominator * second.denominator;
    
    for (int i = res.numerator; i > 1; i--)
    {
        if (res.numerator % i == 0 && res.denominator % i == 0)
        {
            res.numerator /= i;
            res.denominator /= i;
            i--;
        }
    }
    
    return res;
}

int main()
{
    t_fraction fractions[10];
    int n_fractions = 0;
    
    int numerator;
    int denominator;
    
    for (numerator = 10; numerator < 99; numerator++)
    {
        for (denominator = numerator+1; denominator < 100; denominator++)
        {
            //extract digits
            int num1 = numerator/10;
            int num2 = numerator % 10;
            
            int denom1 = denominator/10;
            int denom2 = denominator % 10;
            
            //compare digits
            if (num1 == denom2)
            {
                //doesnt happen ever
                
                if (fractions_are_equal(numerator, denominator, num2, denom1))
                {
                    
                    fractions[n_fractions].numerator = num2;
                    fractions[n_fractions].denominator = denom1;
                    
                    n_fractions++;
                    
                }
            }
            
            if (num2 == denom1)
            {
                if (fractions_are_equal(numerator, denominator, num1, denom2))
                {
                    
                    
                    fractions[n_fractions].numerator = num1;
                    fractions[n_fractions].denominator = denom2;
                    
                    n_fractions++;
                }
            }
        }
    }
    
    t_fraction res = {1,1};
    
    for (int i = 0; i < n_fractions; i++)
    {
        printf("%d/%d\n", fractions[i].numerator, fractions[i].denominator);
        
        t_fraction c = multiply_and_reduce(res, fractions[i]);
        res.numerator = c.numerator;
        res.denominator = c.denominator;
    }
    
    printf("The denominator of the product of the fractions is %d\n", res.denominator);
}