/*
Naively implemented list
*/

#include <stdio.h>
#include <stdlib.h>

struct list_t
{
    int value;
    struct list_t *next;
};

typedef struct list_t List;

void append_element(List* l, int value)
{
    if (l == NULL)
    {
        l = (List *) malloc(sizeof(List));
        l->value = value;
        l->next = NULL;
    }
    else if ((l->next) == NULL)
    {
        List *n = (List *) malloc(sizeof(List));
        n->value = value;
        n->next = NULL;
        l->next = n;
    }
    else
        append_element(l->next, value);
}


void delete_element(List *l, int value)
{
    
    if(l != NULL) {
        
        List *n = l->next;
        
        if (n != NULL)
        {
            if (n->value == value)
            {
                List *nn = n->next;
                l->next = nn;
                free(n);
            }
            else
                delete_element(n, value);
        }
    }
}

int count_list(List* l)
{
    if (l == NULL)
        return 0;
    else
        return 1 + count_list(l->next);
}

int sum_list(List *l)
{
    if ((l->next) == NULL)
        return l->value;
    else
        return l->value + sum_list(l->next);
}

void print_list(List *l)
{
    if (l != NULL)
    {
        printf("%d\n", l->value);
        print_list(l->next);
    } 
    else
    {
        printf("End of List \n");
    }
}


