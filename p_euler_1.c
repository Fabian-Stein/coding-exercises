/*
Project Euler 

Problem 1

Multiples of 3 and 5
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.c"

List *multiples_of(int max, int *numbers, int size)
{
    List *first = NULL;
    List *current = NULL;
    
    for (int i = 1; i < max; i++)
    {
        int is_multiple = 0;
        
        for(int j = 0; j < size; j++)
        {
            int c = numbers[j];
            if ((i % c) == 0)
            {
                is_multiple = 1;
                break;
            }
        }
        
        if (is_multiple)
        {
            if (first != NULL)
            {
                List* new_list = (List *) malloc(sizeof(List));
                new_list->value = i;
                new_list->next = NULL;
                
                current->next = new_list;
                current = new_list;
                
            } 
            else
            {
                first = (List *) malloc(sizeof(List));
                first->value = i;
                first->next = NULL;
                current = first;
            }
        }
        
    }
    return first;
}

int main()
{
    int arr[] = {3,5};
    List *l = multiples_of(10, arr, 2);
    print_list(l);
    
    List *null_list = NULL;
    print_list(null_list);
    
    int sum = sum_list(l);
    printf("sum = %d\n", sum);
}
