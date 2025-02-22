/**
 * -------------------------------------
 * @file  functions.c
 * Lab 2 Functions Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "functions.h"

int sum_three_integers(void) {
    printf("Enter three comma-separated integers:");
    int num1, num2, num3; 
    int i = 0;
    int sum; 
    
    while (i == 0) {
        if (scanf("%d,%d,%d", &num1, &num2, &num3) == 3) {
            sum = num1 + num2 + num3;
            i = 1;
        } else {
            printf("The integers were not properly entered.\n");
            printf("Enter three comma-separated integers:"); 
            while (getchar() != '\n'); 
        }
    }
    return sum; 
}
