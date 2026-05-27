// Fibonacci bottom-up iterative approach (tabulation)
#include <stdio.h>

int main() 
{
	int pos;
	printf("Enter the position: ");
	scanf("%d", &pos);
    
    int fib[pos];   
    int count = 0;

    fib[0] = 0;
    fib[1] = 1;
    count += 2; // we computed fib(0) and fib(1)

    // Bottom-up filling
    for (int i = 2; i <= pos; i++) 
    {
        fib[i] = fib[i - 1] + fib[i - 2];
        count++;
    }

    printf("Fibonacci number at position %d is: %d\n", pos, fib[pos]);
    printf("Total computations made: %d\n", count);

    // Print full sequence up to that position
    printf("Fibonacci sequence up to position %d: ", pos);
    for (int i = 0; i <= pos; i++) 
    {
        printf("%d ", fib[i]);
    }
    printf("\n");

    return 0;
}
