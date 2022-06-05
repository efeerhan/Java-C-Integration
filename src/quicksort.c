#include "test.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


void swap(int* a, int* b) { 
    int t = *a; 
    *a = *b; 
    *b = t; 
}

int rearrange(int* arr, int n, int pivot_index) {
    int pivot = arr[pivot_index];
    size_t f = 0;
    swap(&arr[pivot_index], &arr[0]);
    size_t final = 0;
    int iLeft = 0;
    int jRight = n;
    while ( iLeft++ < n ) {
        if ( final == 1 ) break;
        if ( arr[iLeft] > pivot ) {
            f = 1;
            while ( jRight >= iLeft) {
                jRight--;
                if ( jRight < iLeft ) {
                    swap(&arr[0], &arr[jRight]);
                    final = 1;
                    break;
                }
                if ( arr[jRight] < pivot ) {
                    swap(&arr[iLeft], &arr[jRight]);
                    break;
                }
            }
        }
    }
    if ( f == 0 ) { jRight--; swap(&arr[0],&arr[n-1]); }
    return jRight;
}

void quick_sort(int* arr, int n)  {
    srand(time(NULL)); 
    if ( n > 1 ) {
        int pi;
        int x = rand() % n;
        int y = rand() % n;
        int z = rand() % n;
        if ( x+z < y+z ) {
            if ( x < z ) pi = x;
            else pi = z;
        }
        else {
            if ( y < z ) pi = y;
            else pi = z;
        }
        if ( pi < n ) {  
            //printf("checking pi %d\n", pi);
            int index = rearrange(arr, n, pi);

            quick_sort(arr, index);
            if ( index > 0 ) quick_sort(arr+index, n-index); 
            else quick_sort(arr+1, n-1); 
        }
    }
}

int main (int argc, char* argv[]) {

    char** new_argv = malloc((argc+1) * sizeof(*new_argv));
    for(int i = 0; i < argc; ++i)
    {
        size_t length = strlen(argv[i])+1;
        new_argv[i] = malloc(length);
        memcpy(new_argv[i], argv[i], length);
    }
    new_argv[argc] = NULL;
    int* int_argv = malloc(sizeof(int)*(argc-1));

    for(int i = 0; i < argc-1; ++i)
    {
        int_argv[i] = atoi(new_argv[i+1]);
    }

    for(int i = 0; i < argc; ++i)
    {
        free(new_argv[i]);
    }
    free(new_argv);

    int n = argc - 1;
    quick_sort(int_argv,n);
    for ( size_t j = 0; j < n; j++ ) {
        if ( j > 0 )
            printf(" ");
        printf("%d", int_argv[j]);
    }

    free(int_argv);
}

