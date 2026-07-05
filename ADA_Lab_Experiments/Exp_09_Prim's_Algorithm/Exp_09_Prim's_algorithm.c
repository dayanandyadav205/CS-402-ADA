#include <stdio.h>

#define INF 999999.0f // Represents infinity for missing edges
#define MAX 100        // Maximum number of vertices

float prim(float cost[MAX][MAX], int n, int t[MAX][2]) {
    float mincost = 0;
    int near[MAX];
    int k = 1, l = 1;
    float min_edge_cost = INF;

    // 1. Find the absolute minimum cost edge (Scan upper triangle only)
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) { 
            if (cost[i][j] < min_edge_cost) {
                min_edge_cost = cost[i][j];
                k = i;
                l = j;
            }
        }
    }

    mincost = cost[k][l];
    t[1][0] = k; 
    t[1][1] = l; 

    // 2. Initialize near[] array
    for (int i = 1; i <= n; i++) {
        if (i == k || i == l) {
            near[i] = 0; // The starting vertices are already in the tree
        } else if (cost[i][l] < cost[i][k]) {
            near[i] = l;
        } else {
            near[i] = k;
        }
    }

    // 3. Find the remaining n - 2 edges
    for (int i = 2; i <= n - 1; i++) {
        int j = 0;
        float min_near_cost = INF;

        // Find index j with minimum cost to the current tree
        for (int m = 1; m <= n; m++) {
            if (near[m] != 0 && cost[m][near[m]] < min_near_cost) {
                min_near_cost = cost[m][near[m]];
                j = m;
            }
        }

        // If no valid edge is found, the graph is disconnected
        if (j == 0) {
            break; 
        }

        t[i][0] = j;
        t[i][1] = near[j];
        mincost += cost[j][near[j]];
        near[j] = 0; // Mark vertex j as included in the tree

        // Update near[] array for remaining unselected vertices
        for (int next_k = 1; next_k <= n; next_k++) {
            if ((near[next_k] > 0) && (cost[next_k][near[next_k]] > cost[next_k][j])) {
                near[next_k] = j;
            }
        }
    }

    return mincost;
}

int main() {
    // FIX 1: Set n to 4 because there are only 4 active vertices (Indices 1 to 4)
    int n = 4; 
    int t[MAX][2]; 

    // FIX 2: Ensured the matrix dimensions match the layout size
    float cost[MAX][MAX] = {
        {INF, INF, INF, INF, INF},     // Row 0 (Ignored padding)
        {INF, INF, 10.0f, 6.0f, 5.0f},  // Row 1 (Vertex 1 connections)
        {INF, 10.0f, INF, INF, 15.0f},  // Row 2 (Vertex 2 connections)
        {INF, 6.0f, INF, INF, 4.0f},   // Row 3 (Vertex 3 connections)
        {INF, 5.0f, 15.0f, 4.0f, INF}   // Row 4 (Vertex 4 connections)
    };

    float total_cost = prim(cost, n, t);
    printf("Exp 09 Prim's Algorithm\n");
    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 1; i <= n - 1; i++) {
        printf("Edge %d: (%d, %d)\n", i, t[i][0], t[i][1]);
    }
    printf("Total Minimum Cost: %.2f\n", total_cost);

    return 0;
}
