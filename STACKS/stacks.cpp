#include <stdio.h>
#include <stdlib.h>

typedef struct node *node_ptr;
struct node{
	int element;
	node_ptr next;
};

typedef node_ptr STACK;

void makeNull(STACK S){
	if(S!=NULL) S->next=NULL;
	else printf("Use createStack");
}

STACK createStack(void){
	STACK S ;
	S = (STACK)malloc(sizeof(struct node));
	
	if(S==NULL) printf("Fatal Error - Out of space");
	makeNull(S);
	return S;
}

int isEmpty(STACK S){
	return (S->next==NULL);
}

void push(int x,STACK S){
	node_ptr tmp;
	tmp = (node_ptr)malloc(sizeof(struct node));
	if(tmp==NULL) printf("Fatal error out of space");
	else{
		tmp->element=x;
		tmp->next=S->next;
		S->next=tmp;
	}
}

int topOfStack(STACK S){
	if(isEmpty(S)) return -1;
	return S->next->element;
}
void popStack(STACK S){
	node_ptr first;
	first = node_ptr(malloc(sizeof(struct node)));
	if(isEmpty(S)) printf("Stack Empty");
	else{
		first = S->next;
		S->next=S->next->next;
		free(first);
		
	}
}
int main(){
	STACK S = createStack();
	push(4,S);
	push(5,S);
	popStack(S);
	printf("%d",topOfStack(S));
}
