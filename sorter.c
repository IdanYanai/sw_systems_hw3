#include "sorter.h"
#include <stdlib.h>

void shift_element(int* arr, int i) {
    for(int j=1;j<=i;j++)
        *(arr+i-j+1) = *(arr+i-j);
}

void insertion_sort(int* arr, int len) {
    int saver;
    int j=0;
    for(int i=1;i<len;i++) {
        saver = *(arr+i);
        j=i-1;
        while((j>=0) && (*(arr+j)>saver))
            j--;
        shift_element(arr+j+1, i-j-1);
        *(arr+j+1) = saver;
    }
}