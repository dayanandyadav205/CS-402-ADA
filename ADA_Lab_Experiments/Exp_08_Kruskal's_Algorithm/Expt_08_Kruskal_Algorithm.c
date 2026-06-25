#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000

// Structure to represent an edge
typedef struct {
    int u, v;
    double cost;
} Edge;

// Global variables for Disjoint-Set (Union-Find)
int parent[MAX_VERTICES + 1];

// Global array for the min-heap (1-indexed for easy child calculation)
Edge heap[MAX_EDGES + 1];
int heapSize = 0;

// Disjoint-Set: Find operation with path compression
int Find(int i) {
    int root = i;
    while (parent[root] > 0) {
        root = parent[root];
    }
    // Path compression
    int curr = i;
    while (curr != root) {
        int nxt = parent[curr];
        parent[curr] = root;
        curr = nxt;
    }
    return root;
}

// Disjoint-Set: Union operation by size/weight
void Union(int i, int j) {
    // parent stores negative of set size if it is a root
    int temp = parent[i] + parent[j];
    if (parent[i] > parent[j]) { // j has more elements
        parent[i] = j;
        parent[j] = temp;
    } else { // i has more or equal elements
        parent[j] = i;
        parent[i] = temp;
    }
}

// Heap: Adjust (or heapify-down) routine
void Adjust(int r, int n) {
    Edge item = heap[r];
    int j = 2 * r;
    while (j <= n) {
        if (j < n && heap[j].cost > heap[j + 1].cost) {
            j++; // j points to the smaller child
        }
        if (item.cost <= heap[j].cost) {
            break;
        }
        heap[j / 2] = heap[j];
        j = 2 * j;
    }
    heap[j / 2] = item;
}

// Heap: Create min-heap from an unordered array of edges
void heapify(Edge E[], int numEdges) {
    heapSize = numEdges;
    for (int i = 1; i <= numEdges; i++) {
        heap[i] = E[i - 1]; // Copy 0-indexed E to 1-indexed heap
    }
    for (int i = heapSize / 2; i >= 1; i--) {
        Adjust(i, heapSize);
    }
}

// Heap: Delete and return the minimum cost edge
Edge deleteMin() {
    Edge minEdge = heap[1];
    heap[1] = heap[heapSize];
    heapSize--;
    Adjust(1, heapSize);
    return minEdge;
}

// Kruskal's Algorithm
double Kruskal(Edge E[], int numEdges, int n, int t[][3]) {
    // 1. Construct a heap out of the edge costs using heapify
    heapify(E, numEdges);
    
    // 2. Initialize parent array: each vertex is its own set (-1 indicates root with size 1)
    for (int k = 1; k <= n; k++) {
        parent[k] = -1;
    }
    
    int i = 0;
    double mincost = 0.0;
    
    // 3. Main loop
    while ((i < n - 1) && (heapSize > 0)) {
        // Delete a minimum cost edge (u, v) from the heap and re-heapify using Adjust
        Edge minEdge = deleteMin();
        int u = minEdge.u;
        int v = minEdge.v;
        
        int j = Find(u);
        int k = Find(v);
        
        // Check if they belong to different sets
        if (j != k) {
            i = i + 1;
            t[i][1] = u;
            t[i][2] = v;
            mincost = mincost + minEdge.cost;
            Union(j, k);
        }
    }
    
    // 4. Check if a valid spanning tree was found
    if (i < n - 1) {
        printf("no spanning tree\n");
        return -1.0;
    } else {
        return mincost;
    }
}

// Driver program to test the algorithm
int main() {
    int n = 4; // Number of vertices
    int numEdges = 5; // Number of edges
    
    // Sample Graph Edge List
    Edge E[] = {
        {1, 2, 10},
        {1, 3, 6},
        {1, 4, 5},
        {2, 4, 15},
        {3, 4, 4}
    };
    
    // t[i][1] will store 'u' and t[i][2] will store 'v' for the i-th edge in MST
    int t[MAX_VERTICES][3]; 
    
    double result = Kruskal(E, numEdges, n, t);
    printf("Exp 08 Kruskal's Algorithm'\n");
    if (result != -1.0) {
        printf("Minimum Cost Spanning Tree Edges:\n");
        for (int i = 1; i <= n - 1; i++) {
            printf("Edge %d: (%d, %d)\n", i, t[i][1], t[i][2]);
        }
        printf("Total Minimum Cost: %.2f\n", result);
    }
    
    return 0;
}
 