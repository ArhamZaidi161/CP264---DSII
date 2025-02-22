#ifndef BIGINT_H
#define BIGINT_H

#include "dllist.h"

/* Define BIGINT as a doubly linked list (DLL) */
typedef DLL BIGINT;

/*
 * Creates and returns a BIGINT object by converting the digit string.
 * If the string is NULL or not valid, returns an empty BIGINT.
 */
BIGINT bigint(char *digitstr);

/*
 * Adds two BIGINT operands and returns the sum as a BIGINT.
 */
BIGINT bigint_add(BIGINT oprand1, BIGINT oprand2);

/*
 * Computes and returns Fibonacci(n) as a BIGINT.
 * Fibonacci(1) and Fibonacci(2) are defined as "1".
 */
BIGINT bigint_fibonacci(int n);

#endif
