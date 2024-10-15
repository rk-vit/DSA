#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
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

int isEmpty(STACK S){
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
	if(isEmpty(S)){
		printf("Empty stack");
		return '\0';
	}
	return S->next->element;
}

int priority(char e){
	switch (e){
		case '^' : return 3 ; 
		case '*' : return 2 ; 
		case '/' : return 2 ; 
		case '+' : return 1 ;  
		case '-' : return 1 ; 
		default : return -1;
	}
}

void infix_to_postfix(char arr[],int n){
	STACK S = createStack();
	char ans[100] ;
	int cnt =0;
	for(int i=0;i<n;i++){
		char ch = arr[i];
		if(isalnum(ch)){
			ans[cnt++] =ch;
		}else if(arr[i]=='('){
			push(S,ch);
		}else if(ch==')'){
			while(!isEmpty(S)&& top(S)!='('){
				ans[cnt++] = pop(S);
			}
			if(!isEmpty(S)&& top(S)=='('){
				pop(S);
			}
		}else{
			while(!isEmpty(S) && priority(ch) <= priority(top(S))){
				ans[cnt++] = pop(S);
			}
			push(S,arr[i]);
		}
	}
	while(!isEmpty(S)){
		ans[cnt++] = pop(S);
	}
	ans[cnt]='\0';
	printf("\nPostfix expression is %s",ans);
}
int main(){
	char infix[100] ; // "A+B*(C-D)/E"
	printf("Enter the infix expression to be converted :- ");
	fgets(infix,sizeof(infix),stdin);
    int len = strlen(infix);
    infix_to_postfix(infix, len);
    return 0;
}
