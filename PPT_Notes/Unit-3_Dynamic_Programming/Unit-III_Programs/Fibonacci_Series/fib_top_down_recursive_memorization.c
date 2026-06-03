// Fibonacci with memoization top down recursive approach
// Position-based version
#include <stdio.h>

int count = 0;
int memo[100];  // adjust size as needed

int fibAtPosition(int pos) 
{
    // If already computed, return stored value (no new call counted)
    if (memo[pos] != -1) 
    {
        return memo[pos];
    }

    // Count only when computing a fresh value
    count++;

    if (pos == 0) 
    {
        memo[pos] = 0;
        return 0;
    }

    if (pos == 1) 
    {
        memo[pos] = 1;
        return 1;
    }

    // Store result in memo before returning
    memo[pos] = fibAtPosition(pos - 1) + fibAtPosition(pos - 2);
    return memo[pos];
}

int main() 
{
    int position;

    printf("Enter the position in Fibonacci sequence: ");
    scanf("%d", &position);

    // Initialize memo array with -1 (meaning "not computed")
    for (int i = 0; i <= position; i++) 
    {
        memo[i] = -1;
    }

    // Compute Fibonacci at the given position
    int value = fibAtPosition(position);

    // Print the entire sequence up to that position
    printf("Fibonacci sequence up to position %d: ", position);
    for (int i = 0; i <= position; i++) 
    {
        printf("%d ", fibAtPosition(i));
    }
    printf("\n");

    // Print final result and count
    printf("Fibonacci number at position %d is: %d\n", position, value);
    printf("Unique recursive computations call made: %d\n", count);

    return 0;
}
