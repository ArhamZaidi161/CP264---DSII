/**
 * -------------------------------------
 * @file  by_ptr.c
 * Lab 2 Pointer Functions Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "by_ptr.h"

void fill_values_by_ptr(int *values, int size) {

    for(int i = 0; i < size; i++) {
        *(values + i) = i + 1;
    }
}

void fill_squares_by_ptr(int *values, long int *squares, int size) {

    for(int i = 0; i < size; i++) {
        *(squares + i) = (*(values + i)) * (*(values + i));
    }

}

void print_by_ptr(int *values, long int *squares, int size) {
    printf("Value  Square    \n");
    printf("-----  ----------\n");

    for (int i = 0; i < size; i++) {
        printf("%5d" "%12ld\n", *(values + i), *(squares + i)); 
    }
}
