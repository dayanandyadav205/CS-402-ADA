//Exp_10_Floyd_Warshall's_Algorithm
#include <stdio.h>

// Define Infinity as a large value to represent no direct path
#define INF 99999
#define V 4

// Function to run the Floyd-Warshall algorithm
void floydWarshall(int graph[V][V]) {
    int dist[V][V];
    int i, j, k;

    // Initialize the solution matrix with the same values as the input graph
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Add all vertices one by one to the set of intermediate vertices
    for (k = 0; k < V; k++) {
        // Pick all vertices as source one by one
        for (i = 0; i < V; i++) {
            // Pick all vertices as destination for the picked source
            for (j = 0; j < V; j++) {
                // If vertex k is on the shortest path from i to j,
                // then update the value of dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

	printf("Exp_10_Floyd_Warshall's_Algorithm \n");
    // Print the final shortest distance matrix
    printf("Shortest distance matrix between every pair of vertices:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V] = {
        {0, 3, INF, 7},   // Path from Node 1
        {8, 0, 2, INF},   // Path from Node 2
        {5, INF, 0, 1},   // Path from Node 3
        {2, INF, INF, 0}    // Path from Node 4
    };

    // Run the algorithm
    floydWarshall(graph);

    return 0;
}
