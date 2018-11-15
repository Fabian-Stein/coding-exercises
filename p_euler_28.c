/*
 Number spiral diagonals
Problem 28 
Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
*/

#import <stdio.h>

int numbers_in_radius(int r)
{
    return (r*2 + 1)*4 - 2;
}

#define MAX_LENGTH 1001

int main()
{
    int spiral[MAX_LENGTH][MAX_LENGTH];
    
    int radius = 1;
    
    int x = MAX_LENGTH/2;
    int y = MAX_LENGTH/2;
    
    spiral[x][y] = 1;
    x++;
    
    for (int i = 2; i < MAX_LENGTH*MAX_LENGTH;)
    {
        //2 * radius - 1 down
        for (int j = 0; j < 2*radius - 1; j++)
        {
            spiral[x][y] = i;
            y++;
            i++;
        }
        
        //2 * radius left
        for (int j = 0; j < 2*radius; j++)
        {
            spiral[x][y] = i;
            x--;
            i++;
        }
        
        //2 * radius up
        for (int j = 0; j < 2*radius; j++)
        {
            spiral[x][y] = i;
            y--;
            i++;
        }
        
        //2 * radius right
        for (int j = 0; j < 2*radius; j++)
        {
            spiral[x][y] = i;
            x++;
            i++;
        }
        
        spiral[x][y] = i;
        
        //printf("%d %d\n", x, y);
        
        //move 2 right
        x++;
        i++;
        radius++;
    }
    
    int sum_1 = 0;
    int sum_2 = 0;
    
    for (int i = 0; i < MAX_LENGTH; i++)
    {
        sum_1 += spiral[i][i];
        sum_2 += spiral[i][MAX_LENGTH-i-1];
    }
    
    /*
    for (int i = 0; i < MAX_LENGTH; i++)
    {
        for (int j = 0; j < MAX_LENGTH; j++)
        {
            printf("%d ", spiral[j][i]);
        }
        printf("\n");
    }
    */
    
    printf("The sum of the diagonals are %d\n", sum_1 + sum_2 - 1);
}

