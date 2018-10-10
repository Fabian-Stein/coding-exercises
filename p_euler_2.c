/*
Project Euler

Problem 2

Even Fibonacci numbers
Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:

1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
*/
#import <stdio.h>
#import "list.c"


List *fib(int max)
{
    List *result = (List*) malloc(sizeof(List));
    result->value = 1;
    result->next = NULL;
    append_element(result, 2);
    
    List *ll = result;
    List *l = result->next;
    
    for (;;)
    {
        int v = ll->value + l->value;
        
        if (v >= max)
            break;
        
        append_element(l, v);
        ll = l;
        l = l->next;
    }
    
    return result;
}

//happens "inplace" -> the uneven listnodes are deleted
List *filter_for_even(List* l)
{
    List *first = NULL;
    List *last = NULL;
    
    while (l != NULL)
    {
        if (l->value % 2 == 0)
        {
            if (first == NULL)
                first = l;
            
            last = l;
            l = l->next;
            continue;
        }
        
        if (last != NULL)
        {
            last->next = l->next;
            free(l);
            l = last->next;
        }
        else
        {
            List *temp = l;
            l = l->next;
            free(temp);
        }
    }
    
    return first;
}


int main()
{
    List *f = fib(100);
    print_list(f);
    print_list(filter_for_even(f));
}
