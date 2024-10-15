#include <stdio.h>

void dfs(int adj[][101], int n, int startElement, int visited[]) {
    visited[startElement - 1] = 1; // Mark the current node as visited
    printf("%d ", startElement); // Print the current node

    // Visit all the adjacent nodes
    for (int i = 0; i < n; i++) {
        if (adj[startElement - 1][i] == 1 && !visited[i]) {
            dfs(adj, n, i + 1, visited); // Recursive call for the adjacent node
        }
    }
}

int main() {
    printf("Enter n (number of nodes), m (number of edges): ");
    int n, m;
    scanf("%d %d", &n, &m);

    if (n <= 0 || n > 101 || m < 0) {
        printf("Invalid number of nodes or edges.\n");
        return 1; // Exit the program
    }

    int adj[101][101] = {0}; // Initialize the adjacency matrix

    printf("Enter the node relations (edges) in the format 'n1 n2': \n");
    for (int i = 0; i < m; i++) {
        int n1, n2; 
        scanf("%d %d", &n1, &n2);
        if (n1 < 1 || n1 > n || n2 < 1 || n2 > n) {
            printf("Invalid edge: (%d, %d). Nodes must be between 1 and %d.\n", n1, n2, n);
            return 1; // Exit the program
        }
        adj[n1 - 1][n2 - 1] = 1;
        adj[n2 - 1][n1 - 1] = 1; // Undirected graph
    }

    int visited[101] = {0}; // Initialize the visited array

    printf("Adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    // Call DFS starting from node 1 (1-based index)
    printf("DFS Traversal: ");
    dfs(adj, n, 1, visited);
    
    return 0;
}
