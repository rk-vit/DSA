#include <stdio.h>
#include <stdlib.h>
typedef struct qnode* nodeptr;

struct qnode{
	int element;
	nodeptr next;
};

nodeptr qfront =NULL;
nodeptr qrear = NULL;	
typedef nodeptr QUEUE ;
int isEmpty(QUEUE Q){
	return qfront==NULL;
}
void dequeue(QUEUE Q){
	if(qfront == NULL){
		printf("Queue underflow");
	}else{
		nodeptr temp = qfront;
		qfront=qfront->next;
		free(temp);
		if(qfront==NULL){
			qrear=NULL;
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

void enqueue(QUEUE Q , int x){
	nodeptr cell = (nodeptr)malloc(sizeof(struct qnode));
	if(cell==NULL) printf("fatal err");
	else{
		cell->element=x;
		cell->next=NULL;
		if(qrear==NULL){
			qfront = cell;
			qrear = cell;	
		}else{
			
			qrear=cell;
		}
	}
}
QUEUE createQueue(){
	QUEUE Q = (QUEUE)malloc(sizeof(struct qnode));
	if(Q==NULL) printf("Fatal err");
	else{
		makeEmpty(Q);
		return Q;
	}
}

int toq(QUEUE Q){
	printf("%d",qfront->element);
}

int main(){
	QUEUE Q = createQueue();
	enqueue(Q,5);
	
	toq(Q);
}
