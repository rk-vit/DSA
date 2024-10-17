#include <stdio.h>
int main(){
    printf("Enter n (number of nodes), m (number of edges): ");
    int n, m;
    scanf("%d %d", &n, &m);
    
    // Initialize adjacency matrix with 0 for weights
    int adj[101][101] = {0}; // Adjust size based on maximum number of nodes

    printf("Enter the node relations (edges) in the format 'n1 n2 weight': \n");
    for (int i = 0; i < m; i++) {
        int n1, n2, weight; 
        scanf("%d %d %d", &n1, &n2, &weight);
        adj[n1 - 1][n2 - 1] = weight; // Store weight for the edge
        adj[n2 - 1][n1 - 1] = weight; // Undirected graph: store weight in both directions
    }
}