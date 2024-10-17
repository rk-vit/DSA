#include <stdio.h>
#include <stdlib.h>
typedef struct qnode* nodeptr;

struct qnode{
	int element;
	nodeptr next;
};
struct queue{
	nodeptr qfront;
	nodeptr qrear;	
};
typedef struct queue* QUEUE ;
int isEmpty(QUEUE Q){
	return Q->qfront==NULL;
}
void dequeue(QUEUE Q){
	if(Q->qfront == NULL){
		printf("Queue underflow");
	}else{
		nodeptr temp = Q->qfront;
		Q->qfront=Q->qfront->next;
		free(temp);
		if(Q->qfront==NULL){
			Q->qrear = NULL;
		}
	}
}
void makeEmpty(QUEUE Q){
	if(Q==NULL) printf("Create a Queue First");
	else{
		while(!isEmpty(Q))
		dequeue(Q);
	}
} 

void enqueue(QUEUE Q, int x) {
    nodeptr cell = (nodeptr)malloc(sizeof(struct qnode));
    if (cell == NULL) {
        printf("Fatal error: Memory allocation failed");
    } else {
        cell->element = x;
        cell->next = NULL;

        // Case 1: Queue is empty
        if (isEmpty(Q)) {
            Q->qfront = cell;
            Q->qrear = cell;
        }
        // Case 2: Insert at the front (higher priority)
        else if (x < Q->qfront->element) {
            cell->next = Q->qfront;
            Q->qfront = cell;
        }
        // Case 3: Insert at the correct position based on priority
        else {
            nodeptr current = Q->qfront;
            while (current->next != NULL && current->next->element <= x) {
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

QUEUE createQueue(){
	QUEUE Q = (QUEUE)malloc(sizeof(struct qnode));
	if(Q==NULL) printf("Fatal err");
	else{
		Q->qfront = NULL;
		Q->qrear =NULL;
		return Q;
	}
}

int toq(QUEUE Q){
	printf("%d",Q->qfront->element);
}

int main(){
	QUEUE Q = createQueue();
	enqueue(Q,5);
	enqueue(Q,4);
	toq(Q);
}
