// Fibonacci (top-down recursive approach with callCount)
// Position-based version
#include <stdio.h>

int count = 0;

int fibAtPosition(int pos) 
{
    count++;
    
    if (pos == 0)
    {
        return 0;
    }
    
    if (pos == 1) 
    {
        return 1;
    }
    
    int sum = fibAtPosition(pos - 1) + fibAtPosition(pos - 2);
    return sum;
}

int main() 
{
    int position;
    
    printf("Enter the position in Fibonacci sequence: ");
    scanf("%d", &position);   // take position input from user
    
    int value = fibAtPosition(position);
    
    printf("Fibonacci number at position %d is: %d\n", position, value);
    printf("Total recursive function calls made: %d\n", count);
    
     // Print the entire sequence up to that position
    printf("Fibonacci sequence up to position %d: ", position);
   for (int i = 0; i <= position; i++) 
    {
        printf("%d ", fibAtPosition(i));
    }
    return 0;
}
