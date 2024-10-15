#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct treeNode* searchTree;

struct treeNode{
    int data;
    searchTree left;
    searchTree right;
};

searchTree createNode(int data){
    searchTree t = (searchTree)malloc(sizeof(struct treeNode));
    t->data = data;
    t->left = NULL;
    t->right = NULL;
    return t;
}
int isEmpty(searchTree root){
    return root==NULL;
}
searchTree insert(searchTree root,int data){
    if(root==NULL) return createNode(data);
    if(data<root->data) root->left = insert(root->left,data);
    if(data>root->data) root->right = insert(root->right,data);
    return root;
}
searchTree search(searchTree root,int key){
    if(root==NULL || root->data == key) return root;
    if(key<root->data){
        return search(root->left,key);
    }
    return search(root->right,key);
}
void inOrderTraversal(searchTree root){
    if(root==NULL) return;
    inOrderTraversal(root->left);
    printf("%d ",root->data);
    inOrderTraversal(root->right);
}

void makeEmpty(searchTree T){
    if(T!=NULL){
        makeEmpty(T->left);
        makeEmpty(T->right);
        free(T);
    }
}
searchTree find(int x , searchTree T){
    if(isEmpty(T)){
        printf("No elements to search");
        return NULL;
    }
    else{
        if(x==T->data) return T;
        if(x<T->data) find(x,T->left);
        if(x>T->data) find(x , T->right);
        
    }
}
searchTree findMin(searchTree T){
    if(isEmpty(T)){
        printf("No elements to search");
        return NULL;
    }
    while(T->left !=NULL) T = T->left;
    return T;
}
int main(){
    int n;
    searchTree root = NULL;
    printf("No of elements: -");
    scanf("%d",&n);
    printf("The tree in BST form:-\n ");
    int rootele; scanf("%d",&rootele);
    root =  insert(root,rootele);
    for(int i=0;i<n-1;i++){
        int temp; scanf("%d",&temp);
        insert(root,temp);
    }
    inOrderTraversal(root);
    printf("\n Element found:- %d" , find(4,root)->data); 
    printf("\nThe minimum element is:- %d",findMin(root)->data);

}


