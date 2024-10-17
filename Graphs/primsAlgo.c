#include <stdio.h>
#include <stdlib.h>

typedef struct qnode* nodeptr;

struct qnode {
    int weight;  // Weight of the edge
    int node;    // Adjacent node
    int parent;  // Parent node
    nodeptr next;
};

struct queue {
    nodeptr qfront;
    nodeptr qrear;
};

typedef struct queue* QUEUE;

int isEmpty(QUEUE Q) {
    return Q->qfront == NULL;
}

// Dequeue operation to remove the minimum weight node
void dequeue(QUEUE Q) {
    if (Q->qfront == NULL) {
        printf("Queue underflow\n");
    } else {
        nodeptr temp = Q->qfront;
        Q->qfront = Q->qfront->next;
        free(temp);
        if (Q->qfront == NULL) {
            Q->qrear = NULL;
        }
    }
}

// Enqueue operation to maintain the min-heap property
void enqueue(QUEUE Q, int weight, int node, int parent) {
    nodeptr cell = (nodeptr)malloc(sizeof(struct qnode));
    if (cell == NULL) {
        printf("Fatal error: Memory allocation failed\n");
    } else {
        cell->weight = weight;
        cell->node = node;
        cell->parent = parent;
        cell->next = NULL;

        // Case 1: Queue is empty
        if (isEmpty(Q)) {
            Q->qfront = cell;
            Q->qrear = cell;
        }
        // Case 2: Insert at the front (higher priority)
        else if (weight < Q->qfront->weight) {
            cell->next = Q->qfront;
            Q->qfront = cell;
        }
        // Case 3: Insert at the correct position based on priority
        else {
            nodeptr current = Q->qfront;
            while (current->next != NULL && current->next->weight <= weight) {
                current = current->next;
            }
            cell->next = current->next;
            current->next = cell;

            // If inserted at the rear
            if (cell->next == NULL) {
                Q->qrear = cell;
            }
        }
    }
}

QUEUE createQueue() {
    QUEUE Q = (QUEUE)malloc(sizeof(struct queue));
    if (Q == NULL) {
        printf("Fatal error: Memory allocation failed\n");
        exit(1);
    }
    Q->qfront = NULL;
    Q->qrear = NULL;
    return Q;
}

// Function to find the sum of weights of edges of the Minimum Spanning Tree
int spanningTree(int n, int adj[101][101]) {
    QUEUE pq = createQueue();
    int visited[101] = {0};  // Visited nodes array
    int sum = 0;             // Sum of weights
    // This array can be used to store the MST edges if needed
    // int mst[101][2]; // Uncomment if you wish to store the MST

    // Start from the first node (node 0)
    enqueue(pq, 0, 0, -1);  // (weight, node, parent)

    while (!isEmpty(pq)) {
        // Get the edge with the minimum weight
        int minWeight = pq->qfront->weight;
        int nextNode = pq->qfront->node;
        int parentNode = pq->qfront->parent;  // If storing MST
        dequeue(pq);

        // If the node has already been visited, skip it
        if (visited[nextNode]) continue;

        // Include this edge in MST
        visited[nextNode] = 1;  // Mark as visited
        sum += minWeight;       // Add weight to the total sum
        
        // If storing the MST, uncomment below
        // if (parentNode != -1) {
        //     mst[nextNode][0] = parentNode;
        //     mst[nextNode][1] = nextNode;
        // }

        // Enqueue all edges from this node to the priority queue
        for (int j = 0; j < n; j++) {
            if (adj[nextNode][j] > 0 && !visited[j]) {
                enqueue(pq, adj[nextNode][j], j, nextNode);
            }
        }
    }

    // If you wish to print the MST, uncomment below
    // printf("Edges in the Minimum Spanning Tree:\n");
    // for (int i = 1; i < n; i++) {
    //     printf("%d - %d\n", mst[i][0] + 1, mst[i][1] + 1); // Print 1-based indexing
    // }

    return sum;  // Return the sum of weights in MST
}

int main() {
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
    
    // Compute the sum of weights of the Minimum Spanning Tree
    int totalWeight = spanningTree(n, adj);
    printf("The sum of all the edge weights in the MST: %d\n", totalWeight);
    
    return 0;
}
