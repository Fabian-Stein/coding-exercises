/*
Project Euler

Problem 22

Names scores
Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?
*/

#import <stdio.h>

void copy_string(char *from, char *to, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        to[i] = from[i];
    }
    to[i+1] = '\0';
}

void copy_unknown_string(char *from, char *to)
{
    int i;
    for (i = 0; from[i] != '\0' ;i++)
    {
        to[i] = from[i];
    }
    to[i] = '\0';
}

int is_bigger(char *first, char *second)
{
    int i = 0;
    while (first[i] == second[i])
    {
        i++;
        
        if (first[i] == '\n')
            return 0;
        
        if (second[i] == '\n')
            return 1;
    }
    
    if (first[i] > second[i])
        return 1;
    else
        return 0;
}

void alphabetical_quick_sort(char *arr, int n)
{
    if (n > 1)
    {
        int c = 0;
        
        for (int i = 0; i < n; i++)
        {
            if (is_bigger(arr + c*15, arr + i*15))
            {
                char temp[15];
                copy_unknown_string(arr + (c+1)*15, temp);
                
                copy_unknown_string(arr + i*15, arr + c*15);
                
                if (c != i-1)
                    copy_unknown_string(temp, arr + i*15);
                
                c++;
            }
        }
        alphabetical_quick_sort(arr, c);
        alphabetical_quick_sort(arr + (c + 1)*15, n - c - 1);
    }
    
}

int name_score(char *arr)
{
    int i = 0;
    int sum = 0;
    while (arr[i] != '\0')
    {
        sum += arr[i] - 64; 
        i++;
    }
    
    return sum;
}

int main()
{
    FILE *name_file = fopen("p022_names.txt", "r");
    
    char names[300000];
    fscanf(name_file, "%s", names);
    
    char sorted_names[300000];
    int n_sorted_names = 0;
    
    for (int i = 1;;)
    {
        int length = 0;
        
        while (names[i+length] != '"')
            length++;
        
        copy_unknown_string(names + i, sorted_names + n_sorted_names*15);
        n_sorted_names++;
        
        i += length;
        
        if (names[i+2] == '\0')
            break;
        
        i += 3; //beginning of next word
    }
    
    alphabetical_quick_sort(sorted_names, n_sorted_names);
    
    //for (int i = 0; i < n_sorted_names; i++)
    //printf("%d: %s\n", i, sorted_names + i*15);
    
    int sum = 0;
    
    for (int i = 0; i < n_sorted_names; i++)
    {
        sum += name_score(sorted_names + i*15)*(i+1);
    }
    
    printf("The total of namescores is %d\n", sum);
}


