/*

*/
#include <stdio.h>

void print_array(int *arr, int n)
{
    for (int i = 0; i < n; i++) 
    {
        printf("%d: %d\n", i, arr[i]);
    }
    
}

void naive_sort(int *arr, int n)
{
    
    for (int i = 0; i < n; i++)
    {
        int small = i;
        
        for (int j = i; j < n; j++)
        {
            //search for index with smallest element
            if (arr[small] > arr[j])
            {
                small = j;
            }
        }
        
        //swap
        int temp = arr[i];
        arr[i] = arr[small];
        arr[small] = temp;
    }
}

void quick_sort(int *arr, int  n)
{
    if (n > 1)
    {
        int current = 0;
        
        for (int i = 1; i < n; i++) 
        {
            int swap_element = arr[i];
            
            if (arr[current] > swap_element) 
            {
                int next_element = arr[current+1];
                
                arr[current+1] = arr[current];
                arr[current] = swap_element;
                
                if (!(current == i-1))
                {
                    arr[i] = next_element;
                }
                current++;
            }
        }
        quick_sort(arr, current);
        quick_sort(&(arr[current+1]), n - current - 1);
    }
}

void merge_sort(int *arr, int n)
{
    
    if (n > 1)
    {
        merge_sort(arr, n/2);
        
        merge_sort(&(arr[n/2]), n - n/2);
        
        int *help_arr = malloc(n * sizeof(int));
        
        int first_index = 0;
        int second_index = n/2;
        
        for (int i = 0; i < n; i++)
        {
            if (first_index == n/2) 
            {
                help_arr[i] = arr[second_index];
                second_index++;
            }
            else if (second_index == n)
            {
                help_arr[i] = arr[first_index];
                first_index++;
            }
            else if (arr[first_index] > arr[second_index])
            {
                help_arr[i] = arr[second_index];
                second_index++;
            }
            else
            {
                help_arr[i] = arr[first_index];
                first_index++;
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            arr[i] = help_arr[i];
        }
        
        free(help_arr);
    }
}


void heap_sort(int *arr, int n)
{
    //build heap
    for (int i = 1; i < n; i++)
    {
        int c = arr[i];
        int parent = arr[i/2];
        int j = i;
        
        while (parent < c)
        {
            arr[j] = parent;
            arr[j/2] = c;
            
            j /= 2;
            
            if (j == 0) break;
            parent = arr[j/2];
        }
    }
    
    //sorting
    for (int i = 0; i < n; i++)
    {
        int new_parent = arr[n-i-1];
        arr[n-i-1] = arr[0];
        arr[0] = new_parent;
        
        int j = 0;
        while (j*2 + 1 < n-i-1) //has left child -> has atleast 1 child
        {
            new_parent = arr[j];
            int l_child = arr[j*2 + 1];
            
            if (j*2 + 2 < n-i-1) //has right child
            {
                int r_child = arr[j*2 + 2];
                
                if (r_child > l_child && r_child > new_parent)
                {
                    arr[j] = r_child;
                    arr[j*2 + 2] = new_parent;
                    
                    j = j*2 + 2;
                    continue;
                } 
            }
            
            if (l_child > new_parent)
            {
                arr[j] = l_child;
                arr[j*2 + 1] = new_parent;
                j = j*2 + 1;
            } 
            else
            {
                break;
            }
        }
        
    }
}


int main () {
    //test here
    int arr[10] = {1,6,8,2,4,3,7,0,9,5};
    
    heap_sort(arr, 10);
    
    print_array(arr, 10);
}


