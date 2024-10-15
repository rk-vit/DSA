#include <stdio.h>
#include <stdlib.h>
#define EMPTY_TOS -1
#define MIN_STACK_SIZE 5

struct stack_record{
	unsigned int stack_size;
	int tos;
	int *arr_record;
};

typedef struct stack_record *STACK;

STACK createStack(unsigned int max_elements){
	STACK S;
	if(max_elements<MIN_STACK_SIZE){
		printf("Error the size of stack is too small");
	}
	S = (STACK)malloc(sizeof(struct stack_record));
	if(S==NULL) printf("Fatal Error :- out of space");
	S->arr_record = (int*)malloc(sizeof(int)*max_elements);
	if(S->arr_record==NULL) printf("Fatal error :- out of space");
	S->tos=EMPTY_TOS;
	S->stack_size=max_elements;
	return(S);
}
void dispose(STACK S){
	if(S!=NULL){
		free(S->arr_record);
		free(S);
	}
}

int isEmpty(STACK S){
	return (S->tos==EMPTY_TOS);
}

int isFull(STACK S){
	return (S->tos==S->	stack_size);
}

void push(int element,STACK S){
	if(isFull(S)) printf("Error Full stack");
	else S->arr_record[++S->tos]=element;
}

int topElement(STACK S){
	if(isEmpty(S)) return -1;
	return S->arr_record[S->tos];
}

void pop(STACK S){
	if(isEmpty(S)) printf("Empty Stack");
	
	else{
		S->tos--;	
	}
}


int main(){
	STACK S = createStack(6);
	push(5,S);
	push(1,S);
	printf("%d",topElement(S));
}
