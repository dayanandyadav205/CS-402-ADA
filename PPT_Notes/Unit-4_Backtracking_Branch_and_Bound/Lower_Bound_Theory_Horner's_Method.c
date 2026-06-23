#include <stdio.h>

// Function to evaluate polynomial using Horner's Method
int polynomial(int A[], int x, int n)
{
    int p, v = 0;

    // Loop executes from n down to 0
    for (int i = n; i >= 0; i--)
    {
        v = (v + A[i]) * x;
    }

    return v;
}

int main()
{
    // Example coefficients for: A[0] + A[1]x + A[2]x^2
    int A[] = {1, 2, 3}; 
    int x = 2;
    int n = 2; // Maximum index of the array

    int result = polynomial(A, x, n);
    printf("The result of the polynomial function is: %d\n", result);

    return 0;
}
