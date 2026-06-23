#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Global array to store queen positions
int x[100]; 

// Algorithm: Can a new queen be placed?
bool Place(int k, int i) 
{
    for (int j = 1; j <= k - 1; j++) 
	{
        // Check if same column or same diagonal
        if ((x[j] == i) || (abs(x[j] - i) == abs(j - k))) 
		{
            return false; 
        }
    }
    return true; 
}

// Algorithm: All solutions to the n-queens problem
void NQueens(int k, int n) 
{
    for (int i = 1; i <= n; i++) 
	{
        if (Place(k, i)) 
		{
            x[k] = i;
            // If all queens are placed
            if (k == n) 
			{
                // Print the current solution
                for (int m = 1; m <= n; m++) 
				{
                    printf("%d", x[m]);
                }
                printf("\n");
            } 
			else 
			{
                NQueens(k + 1, n);
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of queens (n): ");
    scanf("%d", &n);
    
    printf("\nThe solutions are:\n");
    NQueens(1, n);
    
    return 0;
}
