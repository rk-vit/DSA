
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>  // for strlen

typedef struct node *nodeptr;
struct node {
    int element;
    nodeptr next;
};
typedef nodeptr STACK;

void makeNull(STACK S) {
    if (S != NULL) S->next = NULL;
}

STACK createStack(void) {
    STACK S;
    S = (STACK)malloc(sizeof(struct node));
    if (S == NULL) {
        printf("Fatal Error :- Memory full\n");
        exit(1);
    } else {
        makeNull(S);
        return S;
    }
}

int isEmpty(STACK S) {
    return S->next == NULL;
}

void push(STACK S, int x) {
    nodeptr cell;
    cell = (nodeptr)malloc(sizeof(struct node));
    if (cell == NULL) {
        printf("Fatal error\n");
        exit(1);
    } else {
        cell->element = x;
        cell->next = S->next;
        S->next = cell;
    }
}

int pop(STACK S) {
    nodeptr bin;
    if (isEmpty(S)) {
        printf("Error: empty stack\n");
        exit(1);
    } else {
        bin = S->next;
        int element = bin->element;
        S->next = bin->next;
        free(bin);
        return element;
    }
}

int top(STACK S) {
    if (isEmpty(S)) {
        printf("Error: empty stack\n");
        exit(1);
    }
    return S->next->element;
}

int main() {
    STACK S = createStack();
    char arr[100];
    
    // Read the prefix expression from the user
    printf("Enter the prefix expression: ");
    fgets(arr, sizeof(arr), stdin);
    
    // Remove newline character from input (if present)
    int len = strlen(arr);
    if (arr[len - 1] == '\n') {
        arr[len - 1] = '\0';
        len--; // Update length after removing newline
    }

    // Traverse the input expression from right to left for prefix evaluation
    for (int i = len - 1; i >= 0; i--) {
        char inp = arr[i];
        if (isdigit(inp)) {
            // Push operands (numbers) to stack after converting char to int
            push(S, inp - '0');
        } else if (inp == '+' || inp == '-' || inp == '*' || inp == '/') {
            // Pop two operands from the stack
            int a = pop(S);
            int b = pop(S);

            // Perform the operation and push the result back onto the stack
            switch (inp) {
                case '+': push(S, a + b); break;
                case '-': push(S, a - b); break;
                case '*': push(S, a * b); break;
                case '/': push(S, a / b); break;
                default: printf("Unknown operator\n"); break;
            }
        }
    }

    // The final result is on top of the stack
    printf("Result of the prefix expression: %d\n", top(S));

    return 0;
}

