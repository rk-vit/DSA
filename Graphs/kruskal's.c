#include <stdio.h>
#include <stdlib.h>

int parent[100], rank[100], size[100];

// Initialize the Disjoint Set (Union-Find) structure
void initialize(int n) {
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
        rank[i] = 0;
        size[i] = 1;
    }
}

// Find function with path compression
int findUPar(int node) {
    if (node == parent[node])
        return node;
    return parent[node] = findUPar(parent[node]);
}

// Union function by rank
void unionByRank(int u, int v) {
    int root_u = findUPar(u);
    int root_v = findUPar(v);

    if (root_u == root_v) return;

    if (rank[root_u] < rank[root_v]) {
        parent[root_u] = root_v;
    } else if (rank[root_v] < rank[root_u]) {
        parent[root_v] = root_u;
    } else {
        parent[root_v] = root_u;
        rank[root_u]++;
    }
}

// Union function by size
void unionBySize(int u, int v) {
    int root_u = findUPar(u);
    int root_v = findUPar(v);

    if (root_u == root_v) return;

    if (size[root_u] < size[root_v]) {
        parent[root_u] = root_v;
        size[root_v] += size[root_u];
    } else {
        parent[root_v] = root_u;
        size[root_u] += size[root_v];
    }
}

// Function to compare edges for sorting
int compareEdges(const void *a, const void *b) {
    int wtA = ((int *)a)[0];
    int wtB = ((int *)b)[0];
    return wtA - wtB;
}

// Function to calculate the weight of the Minimum Spanning Tree using Kruskal's Algorithm
int spanningTree(int V, int edges[][3], int E) {
    // Sorting the edges based on their weights
    qsort(edges, E, sizeof(edges[0]), compareEdges);

    // Initialize the Disjoint Set (Union-Find) structure
    initialize(V);

    int mstWt = 0;  // Sum of weights in the MST
    for (int i = 0; i < E; i++) {
        int wt = edges[i][0];
        int u = edges[i][1];
        int v = edges[i][2];

        // If the current edge doesn't form a cycle
        if (findUPar(u) != findUPar(v)) {
            mstWt += wt;
            unionBySize(u, v);
        }
    }
    return mstWt;
}

int main() {
    int V = 5;  // Number of vertices
    int E = 6;  // Number of edges

    // Edge list: {weight, node1, node2}
    int edges[6][3] = {
        {2, 0, 1},
        {1, 0, 2},
        {1, 1, 2},
        {2, 2, 3},
        {1, 3, 4},
        {2, 4, 2}
    };

    int mstWt = spanningTree(V, edges, E);
    printf("The sum of all the edge weights in the MST: %d\n", mstWt);

    return 0;
}
