#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct node *nodeptr;
struct node{
	int element;
	nodeptr next;
};
typedef nodeptr STACK;
void makeNull(STACK S){
	if(S!=NULL) S->next=NULL;
}
STACK createStack(void){
	STACK S;
	S = (STACK)malloc(sizeof(struct node));
	if(S==NULL){
		printf("Fatal Error :- Memory full");
	}else{
		makeNull(S);
		return S;
	}
}

int isEmpty(STACK S){
	return S->next==NULL;	
}

void push(STACK S , int x){
	nodeptr cell;
	cell = (nodeptr)malloc(sizeof(struct node));
	if(cell==NULL){
		printf("Fatal error");
	}
	else{
		cell->element=x;
		cell->next=S->next;
		S->next=cell;
	}
}

int pop(STACK S){
	nodeptr bin;
	if(isEmpty(S)){
		printf("Error empty stack");
		return '\0';
	}else{
		bin=S->next;
		int element = bin->element;
		S->next=bin->next;
		free(bin);
		return element;
	}
}
int top(STACK S){
	if(isEmpty(S)){
		printf("Empty stack");
		return '\0';
	}
	return S->next->element;
}

int main(){
	STACK S = createStack();
	
	bool eof=false;
	while(!eof){
		char inp ; scanf("%c",&inp); 
		if(inp=='\0' || inp=='\n'){
			eof=true;
			break;
		}else if(isdigit(inp)){
			push(S,inp-'0');
		}else if(inp=='+'){
			int a = pop(S);
			int b= pop(S);
			push(S,a+b);
		}else if(inp=='-'){
			int a = pop(S);
			int b= pop(S);
			push(S,b-a);
		}else if(inp=='*'){
			int a = pop(S);
			int b= pop(S);
			push(S,a*b);
		}else if(inp=='/'){
			int a = pop(S);
			int b= pop(S);
			push(S,b/a);
		}
	}
	printf("%d",top(S));
}
