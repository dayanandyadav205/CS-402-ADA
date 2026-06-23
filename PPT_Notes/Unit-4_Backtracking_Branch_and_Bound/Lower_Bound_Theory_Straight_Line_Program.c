#include <stdio.h>

// Function to add two numbers
int Sum(int a, int b) 
{
    int c = a + b;
    return c;
}

int main() 
{
    int num1 = 5;
    int num2 = 10;
    int result;

    // Call the Sum function
    result = Sum(num1, num2);

    // Print the result
    printf("The sum of %d and %d is: %d\n", num1, num2, result);

    return 0;
}
