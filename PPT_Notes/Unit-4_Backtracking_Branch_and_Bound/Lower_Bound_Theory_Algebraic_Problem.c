#include <stdio.h>

// Function to calculate x raised to the power of n
double power(double x, int n) 
{ 
    double p = 1.0; 
    for (int i = 1; i <= n; i++) 
    {
        p = p * x;
    }
    return p; 
} 

// Function to evaluate the polynomial
double polynomial(double A[], double x, int n) 
{ 
    double v = 0.0; 
    for (int i = 0; i <= n; i++) 
    {
        v = v + A[i] * power(x, i); 
    }
    return v; 
}

int main() 
{
    // Example coefficients for: 1 + 2x + 3x^2
    double A[] = {1.0, 2.0, 3.0}; 
    double x = 2.0;
    int n = 2; 

    double result = polynomial(A, x, n);
    printf("The result of the polynomial is: %.2f\n", result);

    return 0;
}
