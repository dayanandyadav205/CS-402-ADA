#include <stdio.h>
#include <stdbool.h>

#define N 8 // Number of vertices

// Adjacency Matrix representing the given graph
int G[N + 1][N + 1] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0}, // Index 0 is unused
    {0, 0, 1, 1, 0, 0, 0, 1, 0}, // Node 1 connects to 2, 3, 7
    {0, 1, 0, 1, 0, 0, 0, 0, 1}, // Node 2 connects to 1,3, 8
    {0, 1, 1, 0, 1, 0, 1, 0, 0}, // Node 3 connects to 1,2, 4, 6
    {0, 0, 0, 1, 0, 1, 0, 0, 0}, // Node 4 connects to 3, 5
    {0, 0, 0, 0, 1, 0, 1, 0, 0}, // Node 5 connects to 4, 6
    {0, 0, 0, 1, 0, 1, 0, 1, 0}, // Node 6 connects to 3, 5, 7
    {0, 1, 0, 0, 0, 0, 1, 0, 1}, // Node 7 connects to 1, 6, 8
    {0, 0, 1, 0, 0, 0, 0, 1, 0}  // Node 8 connects to 2, 7
};

int x[N + 1]; // Global array to store the current path
int n = N;    // Number of vertices globally defined
int cycle_count = 0;

// Function prototype
void Hamiltonian(int k);
void NextValue(int k);

void NextValue(int k) {
    int j;
    while (true) {
        // Line 11: x[k] := (x[k] + 1) mod (n + 1);
        x[k] = (x[k] + 1) % (n + 1);
        
        // Line 12: if (x[k] = 0) then return;
        if (x[k] == 0) return;
        
        // Line 13: if (G[x[k-1], x[k]] != 0) then
        if (G[x[k - 1]][x[k]] != 0) {
            
            // Line 15: for j := 1 to k-1 do if (x[j] = x[k]) then break;
            for (j = 1; j <= k - 1; j++) {
                if (x[j] == x[k]) {
                    break;
                }
            }
            
            // Line 17: if (j = k) then
            if (j == k) {
                // Line 18: if ((k < n) or ((k = n) and G[x[n], x[1]] != 0))
                if ((k < n) || ((k == n) && (G[x[n]][x[1]] != 0))) {
                    // Line 19: then return;
                    return;
                }
            }
        }
    }
}

void Hamiltonian(int k) {
    while (true) {
        // Line 9: NextValue(k);
        NextValue(k);
        
        // Line 10: if (x[k] = 0) then return;
        if (x[k] == 0) return;
        
        // Line 11: if (k = n) then write (x[1:n]);
        if (k == n) {
            cycle_count++;
            printf("Cycle %d: ", cycle_count);
            for (int i = 1; i <= n; i++) {
                printf("%d -> ", x[i]);
            }
            printf("%d\n", x[1]); // Complete the loop visually by returning to start
        } else {
            // Line 12: else Hamiltonian(k + 1);
            Hamiltonian(k + 1);
        }
    }
}

int main() {
    // Initialize the path array with 0
    for (int i = 0; i <= n; i++) {
        x[i] = 0;
    }
    
    // All cycles begin at node 1 as per the textbook description
    x[1] = 1; 
    
    printf("Finding all Hamiltonian cycles...\n\n");
    
    // Start finding values from index 2 onwards
    Hamiltonian(2);
    
    if (cycle_count == 0) {
        printf("No Hamiltonian cycles found.\n");
    }
    
    return 0;
}
