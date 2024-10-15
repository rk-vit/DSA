
#include <stdio.h>
int main() {
    printf("Enter n (number of nodes) , m(number of edges): ");
    int n, m;
    scanf("%d %d", &n, &m);
    
    int adj[101][101] = {0}; // Make sure to allocate enough space for the adjacency matrix

    printf("Enter the node relations (edges) in the format 'n1 n2': \n");
    for (int i = 0; i < m; i++) {
        int n1, n2; 
        scanf("%d %d", &n1, &n2);
        adj[n1 - 1][n2 - 1] = 1;
        adj[n2 - 1][n1 - 1] = 1; // Undirected graph
    }
    
    printf("Adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
    
  
    return 0;
}
