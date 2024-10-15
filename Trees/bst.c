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
        if(x<T->data) return find(x,T->left);
        if(x>T->data) return find(x , T->right);
        
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
searchTree findMax(searchTree T){
    if(isEmpty(T)){
        printf("No elements to search");
        return NULL;
    }
    while(T->right!=NULL) T = T->right;
    return T;
}

searchTree delete(int x,searchTree T){
    searchTree tmpcell;
    if(isEmpty(T)) printf("No element to delete");
    else if(x<T->data) T->left = delete(x,T->left);
    else if(x>T->data) T->right = delete(x,T->right);
    else{
        if(T->left && T->right){
            tmpcell = findMin(T->right);
            T->data = tmpcell->data;
            T->right = delete(T->data,T->right);
        }else{
            tmpcell = T;
            if(T->left==NULL) T= T->right;
            else if(T->right==NULL) T= T->left;
            free(tmpcell);
        }
    return T;
    }

}
searchTree findKthMin(searchTree T,int k){
    static int count = 0;
    if(T==NULL) return NULL;
    searchTree left = findKthMin(T->left,k);
    if(left!=NULL) return left;
    count++;
    if(count==k) return T;
    return findKthMin(T->right,k);
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
    //printf("InorderTraversal before deletion ");
    //inOrderTraversal(root);
    //printf("\n Element found:- %d" , find(4,root)->data); 
    //printf("\nThe minimum element is:- %d",findMin(root)->data);
    //printf("\nThe maximum element is:- %d",findMax(root)->data);
    //delete(2,root);
    //printf("\nInorderTraversal after deletion ");
    //inOrderTraversal(root);
    printf("%d",findKthMin(root,2)->data);


}


