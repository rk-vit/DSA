// You are using GCC


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node *nodeptr;
struct node{
    int element;
    nodeptr next;
};
typedef nodeptr STACK;
void makeNull(STACK S){
    if(S!=NULL) S->next=NULL;
    else printf("USE CREATE STACK FIRST");
}
STACK createStack(void){
    STACK S;
    S = (STACK)malloc(sizeof(struct node));
    if(S==NULL) printf("Ftal Error :- No space");
    else{
        makeNull(S);
        return S;
    }
}
int isEmpty(STACK S){
    return S->next==NULL;
}
void push(STACK S,int x){
    nodeptr cell;
    cell = (nodeptr)malloc(sizeof(struct node));
    if(cell==NULL) printf("Fatal error:- No space");
    else{
        cell->element=x;
        cell->next=S->next;
        S->next=cell;
    }
    
}
int pop(STACK S){
    nodeptr thr;
    thr = (nodeptr)malloc(sizeof(struct node));
    if(thr==NULL) printf("fatal Error");
    else{
        thr = S->next;
        int ele = thr->element;
        S->next=S->next->next;
        free(thr);
        return ele;
    }
}
int main(){
    STACK S = createStack();
    char a; int cnt=0;
    bool eos = false;
    int result =0;
    while(!eos){
        char loc;
        int res =  scanf("%c",&loc);
        if(res==EOF || loc=='\n') eos=true;
        else{
            if(loc=='+'){
                int n1 = pop(S);
                int n2 = pop(S);
                push(S,n1+n2);
            }else if(loc=='-'){
                int n2 = pop(S);
                int n1= pop(S);
                push(S,n1-n2);
            }else if(loc=='*'){
                int n1 = pop(S);
                int n2 = pop(S);
                push(S,n1*n2);
            }else if(loc=='/'){
                int n2=pop(S);
                int n1=pop(S);
                push(S,n1/n2);
            }else if(loc==' '){
                
            }
            else{
                push(S,(loc-'0'));
            }
            cnt++;
            a=loc;
        }
        
    }
    printf("%d",S->next->element);

}
