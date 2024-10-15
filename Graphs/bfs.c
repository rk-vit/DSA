#include <stdio.h>
#include <stdlib.h>

typedef struct qnode* nodeptr;
struct qnode{
    int element;
    nodeptr next;
};
struct queue{
    nodeptr front;
    nodeptr rear;
};
typedef struct queue* QUEUE;

QUEUE createQueue() {
    QUEUE q = (QUEUE)malloc(sizeof(struct queue));
    if (q == NULL) return NULL;
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int isEmpty(QUEUE Q) {
    return Q->front == NULL;
}

void push(QUEUE Q, int x) {
    nodeptr tmp = (nodeptr)malloc(sizeof(struct qnode));
    if (tmp == NULL) return;
    tmp->element = x;
    tmp->next = NULL;
    if (Q->front == NULL) {
        Q->front = tmp;
        Q->rear = tmp;
    } else {
        Q->rear->next = tmp;
        Q->rear = tmp;
    }
}

int pop(QUEUE Q) {
    if (isEmpty(Q)) {
        printf("Underflow\n");
        return -1;
    } else {
        nodeptr tmpcell = Q->front; 
        int el = tmpcell->element;
        Q->front = Q->front->next;
        if (Q->front == NULL) Q->rear = NULL;
        free(tmpcell);
        return el;
    }
}

int front(QUEUE Q) {
    if (!isEmpty(Q)) {
        return Q->front->element;
    }
    return -1; // Should handle this case properly in your application
}

void bfs_traversal(int adj[][101], int n, int startElement) {
    QUEUE Q = createQueue();
    int visited[n];
    for (int i = 0; i < n; i++) visited[i] = 0;
    
    visited[startElement - 1] = 1; // Mark start element as visited
    push(Q, startElement - 1); 
    
    while (!isEmpty(Q)) {
        int node = front(Q);
        pop(Q);
        printf("%d ", node + 1); // Print current node (convert back to 1-based index)
        
        // Check for neighbours
        for (int j = 0; j < n; j++) {
            if (adj[node][j] == 1 && !visited[j]) {
                visited[j] = 1; // Mark as visited
                push(Q, j); // Enqueue the unvisited neighbour
            }
        }
    }
}

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
    
    printf("BFS Traversal:\n");
    bfs_traversal(adj, n, 1);
    
    return 0;
}
