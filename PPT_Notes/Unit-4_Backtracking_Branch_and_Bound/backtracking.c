#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Global variables as specified in the pseudocode
char x[MAX_SIZE]; 
int n = 3; // Length of the sequence

// Bounding function B_k: Checks if the choice is valid
int Bk(int k) {
    // 1. Check if the character was already used (no duplicates)
    for (int i = 1; i < k; i++) {
        if (x[i] == x[k]) {
            return 0; // Invalid choice
        }
    }
    
    // 2. New Rule: 'L' cannot be at the very end of the sequence
//	if (k == n && x[k] == 'L') {
//        return 0; // Invalid choice
//    }
    
    return 1; // Valid choice
}

// Algorithm 7.1: Recursive backtracking algorithm
void Backtrack(int k) {
    // Available choices for x[k]
    char T[] = {'B', 'M', 'L'};
    int choices_count = 3;

    // Line 7: Loop through each choice
    for (int i = 0; i < choices_count; i++) {
        x[k] = T[i];

        // Line 9: Check the bounding condition
        if (Bk(k) != 0) {
            
            // Line 11-12: Complete path to an answer node
            if (k == n) {
                for (int m = 1; m <= k; m++) {
                    printf("%c ", x[m]);
                }
                printf("\n");
            }
            
            // Line 13: Move to next level if k < n
            if (k < n) {
                Backtrack(k + 1);
            }
        }
    }
}

int main() {
    printf("Unique permutations (Factorial 3!=> 3x2x1=6):\n");
    Backtrack(1);
    return 0;
}
