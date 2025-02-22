#include <stdio.h>
#include <stdlib.h>
#include "bigint.h"

/* 
 * Converts a digit string into a BIGINT.
 * It creates an empty BIGINT and then inserts each valid digit at the end.
 * If the string is NULL, not starting with a digit, or empty, returns an empty BIGINT.
 */
BIGINT bigint(char *p) {
    BIGINT bn = {0};  // Initializes bn.length = 0, bn.start = NULL, bn.end = NULL.
    if (p == NULL)
        return bn;
    else if (!(*p >= '0' && *p <= '9')) {  // First character not a digit.
        return bn;
    }
    else if (*p == '0' && *(p+1) == '\0') {  // String "0"
        dll_insert_end(&bn, dll_node(*p - '0'));
        return bn;
    }  
    else { 
        while (*p) {
            if (*p >= '0' && *p <= '9') {
                dll_insert_end(&bn, dll_node(*p - '0'));
            } else { // if any non-digit encountered, clean and break.
                dll_clean(&bn);
                break;
            }
            p++;
        }
        return bn;
    }
}

/*
 * Adds two BIGINT numbers.
 * The addition is done digit-by-digit starting from the least significant digit
 * (the end of the doubly linked list), with proper carry propagation.
 * The resulting digits are inserted at the start of the result so that the final
 * number is in the correct order.
 */
BIGINT bigint_add(BIGINT op1, BIGINT op2) {
    BIGINT result = {0};   // Start with an empty result.
    int carry = 0;
    NODE *p1 = op1.end;
    NODE *p2 = op2.end;
    while (p1 != NULL || p2 != NULL || carry != 0) {
        int d1 = (p1 != NULL) ? p1->data : 0;
        int d2 = (p2 != NULL) ? p2->data : 0;
        int sum = d1 + d2 + carry;
        carry = sum / 10;
        int digit = sum % 10;
        // Insert digit at the beginning so that most significant digit is at the start.
        dll_insert_start(&result, dll_node(digit));
        if (p1 != NULL) p1 = p1->prev;
        if (p2 != NULL) p2 = p2->prev;
    }
    return result;
}

/*
 * Computes Fibonacci(n) as a BIGINT.
 * Fibonacci(1) and Fibonacci(2) are "1". For n >= 3, iteratively compute:
 *   F(n) = F(n-1) + F(n-2)
 * Temporary BIGINT values are cleaned appropriately.
 */
BIGINT bigint_fibonacci(int n) {
    if (n <= 0) {
        return bigint("0");
    }
    if (n == 1 || n == 2) {
        return bigint("1");
    }
    BIGINT a = bigint("1");
    BIGINT b = bigint("1");
    BIGINT temp;
    for (int i = 3; i <= n; i++) {
        temp = bigint_add(a, b);
        dll_clean(&a);   // Clean previous a.
        a = b;
        b = temp;
    }
    dll_clean(&a);
    return b;
}
