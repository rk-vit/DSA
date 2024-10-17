#include <stdio.h>
#define MAX_NODES 100
int rank[MAX_NODES], parent[MAX_NODES];

// Initialize the disjoint set
void initialize(int n) {
    for (int i = 0; i <= n; i++) {
        rank[i] = 0;
        parent[i] = i;  // Each element is its own parent
    }
}

// Find the ultimate parent of a node with path compression
int findUPar(int node) {
    if (node == parent[node])
        return node;
    // Path compression
    return parent[node] = findUPar(parent[node]);
}

// Perform union of two sets by rank
void unionByRank(int u, int v) {
    int root_u = findUPar(u);
    int root_v = findUPar(v);

    if (root_u == root_v) return;

    // Union by rank
    if (rank[root_u] < rank[root_v]) {
        parent[root_u] = root_v;
    } else if (rank[root_v] < rank[root_u]) {
        parent[root_v] = root_u;
    } else {
        parent[root_v] = root_u;
        rank[root_u]++;
    }
}

int main() {
    int n = 7;  // Number of elements (nodes)

    // Initialize parent and rank arrays
    initialize(n);

    // Perform union operations
    unionByRank(1, 2);
    unionByRank(2, 3);
    unionByRank(4, 5);
    unionByRank(6, 7);
    unionByRank(5, 6);

    // Check if 3 and 7 are in the same set
    if (findUPar(3) == findUPar(7)) {
        printf("Same\n");
    } else {
        printf("Not same\n");
    }

    // Perform union of 3 and 7
    unionByRank(3, 7);

    // Check again if 3 and 7 are in the same set
    if (findUPar(3) == findUPar(7)) {
        printf("Same\n");
    } else {
        printf("Not same\n");
    }

    return 0;
}
