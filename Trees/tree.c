#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct treeNode* Tree;
typedef struct qnode* nodeptr;

struct treeNode {
    int data;
    Tree left;
    Tree right;
};

Tree createNode(int data) {
    Tree t = (Tree)malloc(sizeof(struct treeNode));
    t->data = data;
    t->right = NULL;
    t->left = NULL;
    return t;
}

struct qnode {
    Tree element;
    nodeptr next;
};

struct queue {
    nodeptr front;
    nodeptr rear;
};

typedef struct queue* QUEUE;

int isEmpty(QUEUE Q) {
    return Q->front == NULL;
}

Tree front(QUEUE Q) {
    if (!isEmpty(Q)) {
        return Q->front->element;
    }
    return NULL;
}

Tree dequeue(QUEUE Q) {
    if (Q->front == NULL) {
        printf("Underflow\n");
        return NULL;
    } else {
        nodeptr temp = Q->front;
        Tree result = temp->element;
        Q->front = Q->front->next;
        free(temp);
        if (Q->front == NULL) Q->rear = NULL;
        return result;
    }
}




void enqueue(QUEUE Q, Tree element) {
    nodeptr cell = (nodeptr)malloc(sizeof(struct qnode));
    if (cell == NULL) printf("Fatal error\n");
    else {
        cell->element = element;
        cell->next = NULL;
        if (Q->rear == NULL) {
            Q->front = cell;
            Q->rear = cell;
        } else {
            Q->rear->next = cell;
            Q->rear = cell;
        }
    }
}

QUEUE createQueue() {
    QUEUE q = (QUEUE)malloc(sizeof(struct queue));
    if (q == NULL) printf("Fatal error\n");
    else {
        q->front = NULL;
        q->rear = NULL;
    }
    return q;
}

void insertLevelOrder(Tree* root, int data, QUEUE Q) {
    Tree newNode = createNode(data);
    if (*root == NULL) {
        *root = newNode;
        enqueue(Q, newNode);
        return;
    }

    while (!isEmpty(Q)) {
        Tree current = front(Q);
        if (current->left == NULL) {
            current->left = newNode;
            enqueue(Q, newNode);
            return;
        } else if (current->right == NULL) {
            current->right = newNode;
            enqueue(Q, newNode);
            return;
        }
        dequeue(Q);
    }
}

void preOrderTraversal(Tree root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Tree root) {
    if (root == NULL) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->data);
}

void inOrderTraversal(Tree root) {
    if (root == NULL) return;
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

void levelOrderTraversal(Tree root) {
    if (root == NULL) return;
    QUEUE Q = createQueue();
    enqueue(Q, root);
    while (!isEmpty(Q)) {
        Tree current = front(Q);
        printf("%d ", current->data);
        dequeue(Q);
        if (current->left != NULL) enqueue(Q, current->left);
        if (current->right != NULL) enqueue(Q, current->right);
    }
}

Tree dfs(Tree root, int key) {
    if (root == NULL) return NULL;
    if (root->data == key) return root;
    Tree left = dfs(root->left, key);
    if (left != NULL) return left;
    return dfs(root->right, key);
}

Tree bfs(Tree root, int element) {
    if (root == NULL) return NULL;

    QUEUE q = createQueue();
    enqueue(q, root);
    while (!isEmpty(q)) {
        Tree current = dequeue(q);
        if (current->data == element) {
            return current;
        }
        if (current->left != NULL) enqueue(q, current->left);
        if (current->right != NULL) enqueue(q, current->right);
    }
    return NULL;  // Element not found
}

int height(Tree root) {
    if (root == NULL) return -1;
    int left = height(root->left);
    int right = height(root->right);
    return (left > right ? left : right) + 1;
}

int depth(Tree root, int value, int currentDepth) {
    if (root == NULL) return -1;
    if (root->data == value) return currentDepth;
    int leftDepth = depth(root->left, value, currentDepth + 1);
    if (leftDepth != -1) return leftDepth;
    return depth(root->right, value, currentDepth + 1);
}

int main() {
    int n;
    Tree root = NULL;
    QUEUE Q = createQueue();
    printf("Enter number of iterations: ");
    scanf("%d", &n);
    printf("Enter the tree for level order:\n");
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        insertLevelOrder(&root, temp, Q);
    }
    printf("Preorder: ");
    preOrderTraversal(root);
    printf("\nPostorder: ");
    postOrderTraversal(root);
    printf("\nInorder: ");
    inOrderTraversal(root);
    printf("\nLevelorder: ");
    levelOrderTraversal(root);
    printf("\nHeight of Tree: %d", height(root));
    printf("\nDepth of element 3: %d", depth(root, 3, 0));

    Tree foundDfs = dfs(root, 2);
    if (foundDfs != NULL)
        printf("\nSearched element (DFS) 2: %d\n", foundDfs->data);
    else
        printf("\nElement 2 not found (DFS)\n");

    Tree foundBfs = bfs(root, 4);
    if (foundBfs != NULL)
        printf("\nSearched element (BFS) 4: %d\n", foundBfs->data);
    else
        printf("\nElement 4 not found (BFS)\n");

    return 0;
}

