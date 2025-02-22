#include "mysort.h"

/**
 * Use selection sort algorithm to sort array of pointers such that their 
 * pointed values are in increasing order.
 *
 * @param *a[] - array of void pointers.
 * @param left - the start index of pointer in array.
 * @param right - the end index of pointer in array
 */
void select_sort(void *a[], int left, int right) {
    int size = right - left + 1; 

     
    for (int i = left; i <= right; i++) {
        int min = i;
        for (int j = i + 1; j <= right ;j++ ) {
            if (*(int*)a[min] > *(int*)a[j]) {
                min = j; 
            }
        }
    void *temp = a[i];  
    a[i] = a[min]; 
    a[min] = temp; 
    }
}

/**
 * Use quick sort algorithm to sort array of pointers such that 
 * their pointed values are in increasing order.
 *
 * @param *a[] - array of void pointers. 
 * @param left - the start index of pointer in array.
 * @param right - the end index of pointer in array
 */

int partition(void *a[], int left, int right) {
    int pivot = *(int*)a[right]; 
    void *temp; 
    int i = left - 1; 

    for (int j = left; j <= right - 1; j++) {
        if (*(int*)a[j] < pivot) {
            i++; 
            temp = a[i]; 
            a[i] = a[j]; 
            a[j] = temp; 
        } 
    }
    i++; 
    temp = a[i]; 
    a[i] = a[right]; 
    a[right] = temp; 

    return i; 
}

void quick_sort(void *a[], int left, int right) {
    if (right <= left) return;

    int pivot = partition(a, left, right); 
    quick_sort(a, left, pivot - 1); 
    quick_sort(a, pivot + 1, right);
}

/**
 * Use either selection or quick sort algorithm to sort array of pointers 
 * such that their pointed values are in order defined by the given 
 * comparison function
 *
 * @param *a[] - array of void pointers. 
 * @param left - the start index of pointer in array.
 * @param right - the end index of pointer in array
 * @param (*cmp) - pointer to a comparison function used to compaire 
 * pointers by their pointed values.
 */
void my_sort(void *a[], int left, int right, int (*cmp)(void*, void*) ) {

    for (int i = left; i <= right; i++) {
        int min = i; 
        for (int j = i + 1; j <= right; j++) {
            if (cmp((void*)a[min], (void*)a[j]) > 0) {
                min = j; 
            }
        }
    void *temp = a[i];
    a[i] = a[min]; 
    a[min] = temp; 
    }

}
