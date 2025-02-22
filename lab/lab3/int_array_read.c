/**
 * -------------------------------------
 * @file  int_array_read.c
 * Lab 3 Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "functions.h"

void int_array_read(int *array, int size) {

    printf("Enter 4 values for an array of int.\n");
    

    int num, i = 0; 
    while (i < size) {
        printf("Value for index %d:", i); 
        if (scanf("%d%*[^\n]",&num) == 1) { 
            array[i] = num;
            i += 1; 
        } 
        else {
            printf("Not a valid integer"); 
            while (getchar() != '\n');
        }   
    }

}
