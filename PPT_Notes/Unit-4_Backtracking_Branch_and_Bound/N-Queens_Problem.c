#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Global array to store queen positions
int x[100]; 
// Global variable to keep track of total solutions
int total_solutions = 0; 

// Algorithm 7.4: Can a new queen be placed?
bool Place(int k, int i) {
    for (int j = 1; j <= k - 1; j++) {
        // Check if same column or same diagonal
        if ((x[j] == i) || (abs(x[j] - i) == abs(j - k))) {
            return false; 
        }
    }
    return true; 
}

// Algorithm 7.5: All solutions to the n-queens problem
void NQueens(int k, int n) {
    for (int i = 1; i <= n; i++) {
        if (Place(k, i)) {
            x[k] = i;
            // If all queens are placed
            if (k == n) {
                total_solutions++; // Increment solution counter
                
                // Print the current solution
                printf("Solution %d: ", total_solutions);
                for (int m = 1; m <= n; m++) {
                    printf("%d ", x[m]);
                }
                printf("\n");
            } else {
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
    
    // Print the final count
    printf("\nTotal number of solutions: %d\n", total_solutions);
    
    return 0;
}
