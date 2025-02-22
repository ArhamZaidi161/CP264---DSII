#include "polynomial.h"
#include <stdio.h>
#define EPSILON 1e-6
#define MAXCOUNT 100

float horner(float *p, int n, float x)
{
    double ans = p[0]; 
    for (int i= 1; i < n; i++) {
        ans = ans * x + p[i]; 
    }
    return ans; 
} 

void derivative(float *p, float *d, int n)
{ 
    for (int i = 0; i < n-1; i++) {
        d[i] = p[i] * (n-1-i);  
        
    }

}

// add auxilliary function float myfabs(floatx) to return the absolute value x

float newton(float *p, int n, float x0)
{
// your implementation, may use myfabs() to simply the code. 
}