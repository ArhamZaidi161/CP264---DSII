#include <ctype.h>
#include <stdio.h> 
/**
 * -------------------------------------
 * @file  sum_integers.c
 * Lab 3 Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "functions.h"

int sum_integers(void) {
    int num; 
    int sum = 0; 

    printf("Enter integers, one per line:");
 
    while (scanf("%d%*[^\n]", &num) == 1) { 
        sum += num;
        printf("Enter integers, one per line:");
    }
    while (getchar() != '\n');
    return sum; 
}
