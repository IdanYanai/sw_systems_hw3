#include "sorter.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* arr = (int*)malloc(50 * sizeof(int));
    for(int i=0;i<50;++i)
        scanf("%d", arr+i);
    
    insertion_sort(arr, 50);

    for(int j=0;j<49;++j)
        printf("%d,", *(arr+j));
    printf("%d", *(arr+49));

    free(arr);
    return 0;
}
