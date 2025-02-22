#include "fibonacci.h"
#include <stdlib.h>


int recursive_fibonacci(int n) {
    int ans = 0;
    if (n == 0) {
        ans = 0; 
    }

    else if (n == 1) {
        ans = 1;
    } else {
        ans = recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2);
    }
    return ans; 
}

int iterative_fibonacci(int n)
{
    int ans = 0;
    if (n == 0) {
        ans = 0; 
    }

    else if (n == 1) {
        ans = 1;
    } 
    int i = 2, p1 = 0, p2 = 1;  
    while (i <= n) {
        ans = p2 + p1;
        p1 = p2; 
        p2 = ans; 
        i++; 
    }
    return ans; 
}

int dpbu_fibonacci(int *f, int n) {
    if (n == 0) {
        f[0] = 0;
    }
    else if (n == 1) {
        f[1] = 1; 
    } else {
        f[n] = dpbu_fibonacci(f, n-2) + dpbu_fibonacci(f, n-1);
    } 
     
    return f[n]; 
}

int dptd_fibonacci(int *f, int n) {
    // Base cases
    if (n == 0) return 0;
    if (n == 1) return 1;

    // If already computed, return the stored value
    if (f[n] > -1) return f[n];  // FIX: Changed condition from `f[n] > 0` to `f[n] > -1`

    // Compute and store the result
    f[n] = dptd_fibonacci(f, n - 1) + dptd_fibonacci(f, n - 2);

    return f[n];  // Return the computed Fibonacci number
}



