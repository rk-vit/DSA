#include <stdio.h>
#include <stdlib.h>
struct queue_record{
	unsigned int q_max_size;
	unsigned int q_rear;
	unsigned int q_front;
	unsigned int q_size;
	int * arr;
};
typedef struct queue_record *QUEUE;
int isEmpty(QUEUE Q){
	return (Q->q_size==0);
}
int isFull(QUEUE Q){
	return (Q->q_size==Q->q_max_size);
}
void makeNull(QUEUE Q){
	Q->q_front=1;
	Q->q_rear=0;
	Q->q_size=0;
}
int succ(unsigned int rear , QUEUE Q){
	if(++rear==Q->q_max_size){
		rear =0;
	}
	return rear;
}
void enqueue(QUEUE Q,int x){
	if(isFull(Q)){
		printf("Error full queue");
	}else{
		Q->q_size++;
		Q->q_rear= succ(Q->q_rear,Q);
		Q->arr[Q->q_rear]=x;
	}
}
int dequeue(QUEUE Q){
	if(isEmpty(Q)){
		printf("Error :- empty stack");
	}else{
		int fir_element = Q->arr[Q->q_front];
		Q->q_size--;
		Q->q_front = succ(Q->q_front,Q);
		return fir_element;
	}
}
QUEUE createQueue(unsigned int max_size){
	QUEUE Q = (QUEUE)malloc(sizeof(struct queue_record));
	if(Q==NULL) printf("Out of space");
	else{
		Q->q_max_size=max_size;
		Q->arr = (int*)malloc(sizeof(int)*max_size);
		if(Q->arr==NULL) printf("Out of space");
		else{
			makeNull(Q);	
		} 
		
	}
}
int top_of_queue(QUEUE Q){
	return Q->arr[Q->q_front];
}
int main(){
	QUEUE Q = createQueue(5);
	enqueue(Q,5);
	enqueue(Q,6);
	dequeue(Q);
	printf("%d",top_of_queue(Q));
}

