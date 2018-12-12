/*
Coded triangle numbers
Problem 42 
The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1); so the first ten triangle numbers are:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value. For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle number then we shall call the word a triangle word.

Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common English words, how many are triangle words?
*/

#import <stdio.h>

int is_triangle_value(int x)
{
    int n = 0;
    
    int current_v = 0;
    
    while (x > current_v)
    {
        current_v = (n*(n+1))/2;
        
        if (x == current_v)
            return 1;
        n++;
    }
    return 0;
}

int main()
{
    int n_triangles = 0;
    
    char words[200000];
    FILE *file;
    
    if ((file = fopen("p042_words.txt", "r")) == NULL)
    {
        printf("no file\n");
    }
    
    fscanf(file, "%s", words);
    
    for (int i = 1;;)
    {
        int length = 0;
        
        while (words[i + length] != '"')
        {
            length++;
        }
        
        
        int word_value = 0;
        
        for (int j = 0; j < length; j++)
        {
            word_value += words[i+j] - 64;
        }
        
        if (is_triangle_value(word_value))
        {
            n_triangles++;
        }
        
        i += length;
        
        if (words[i+2] == '\0')
            break;
        
        i += 3;
        
    }
    
    printf("The number of triangle words in the textfile is %d\n", n_triangles);
}