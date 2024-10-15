#include <stdio.h>
#include <stdlib.h>
typedef struct node *nodeptr;
struct node{
	char element;
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

char isEmpty(STACK S){
	return S->next==NULL;	
}

void push(STACK S , char x){
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

char pop(STACK S){
	nodeptr bin;
	if(isEmpty(S)){
		printf("Error empty stack");
		return '\0';
	}else{
		bin=S->next;
		char element = bin->element;
		S->next=bin->next;
		free(bin);
		return element;
	}
}
char top(STACK S){
	if(isEmpty){
		printf("Empty stack");
		return '\0';
	}
	return S->next->element;
}

bool isMatching(char open , char close){
	return 	(open=='(' && close==')')||
			(open=='{' && close=='}')||
			(open=='[' && close==']') ;
}

int main(){
	STACK S = createStack();
	bool eof = false;
	bool balanced = true;
	while(!eof && balanced ){
		char inp ; scanf("%c",&inp);
		if(inp=='\0' || inp=='\n'){
			eof=true;
		}else if(inp=='{' || inp =='(' || inp=='['){
			push(S,inp);
		}else if(inp=='}'||inp==')'||inp==']'){
			if(isEmpty(S)){
				balanced = false;
				break;
			}
			char topChar = pop(S);
			if(!isMatching(topChar,inp)){
				balanced = false;
				break;
			}
			
		}
	}
	if(balanced&&isEmpty(S)){
		printf("balanced");
	}else{
		printf("Not balanced");
	}
}

