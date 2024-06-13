#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createnode(int val){
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data=val;
    n->left=NULL;
    n->right=NULL;
    return n;
}
void preOrder(struct node *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(struct node *root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}
void inOrder(struct node *root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}
int isBST(struct node *root){
    bool a =true;
    static struct node *prev= NULL; 
    if(root!=NULL){
        if(!isBST(root->left)){
            return !a;
        }
        if(prev!=NULL && root->data<=prev->data){
            return !a;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return a;
    }
}
struct node *search(struct node *root,int key){
    if(root==NULL) return NULL;
    if(root->data==key) return root;
    else if(root->data > key) return search(root->left,key);
    else search(root->right,key);
}
struct node *search_itr(struct node *root,int key){
    while(root!=NULL){
        if(root->data==key) return root;
        else if(key < root->data) root = root->left;
        else root = root->right;
    }
    return NULL;
}
void insert(struct node *root,int key){
    struct node *prev=NULL;
    struct node *ptr;
    while(root!=NULL){
        prev = root;
        if(root->data==key){
            printf("Insertion can not be done\n");
            return;
        }
        else if(key<root->data) root=root->left;
        else root = root->right;
    }
    if(key<prev->data){
        prev->left=ptr;
        ptr->data = key;
        ptr->left=NULL;
        ptr->right=NULL;
    }
    else{
        prev->right=ptr;
        ptr->data = key;
        ptr->left=NULL;
        ptr->right=NULL;
    }
}
struct node *inOrderPredecessor(struct node *root){
    root=root->left;
    while(root->right!=NULL){
        root= root->right;
    }
    return root;
}
struct node *delete(struct node *root,int val){
    struct node *ipre;
    if(root==NULL) return NULL;
    if(root->left==NULL && root->right==NULL){
        free(root);
        return NULL;
    }
    if(val < root->data){
        root->left=delete(root->left,val);
    }
    else if(val > root->data){
        root->right=delete(root->right,val);
    }
    else{
        ipre = inOrderPredecessor(root);
        root->data=ipre->data;
        root->left=delete(root->left,ipre->data);
    }
}

int main(){
    struct node *p=createnode(10);
    struct node *k=createnode(4);
    struct node *q=createnode(12);
    struct node *a=createnode(2);
    struct node *b=createnode(5);
    struct node *c=createnode(11);
    //struct node *e=createnode(0);
    p->left=k;
    p->right=q;
    k->left=a;
    k->right=b;
    q->left=c;
    //preOrder(p);
    //postOrder(p);
   printf("Inorder traversal before deletion\n");
   inOrder(p);
   //printf("\n");
    //printf("%d",isBST(p));
   /*e=search_itr(p,12);
   if(e!=NULL) printf("Found Element:- %d\n",12);
   else printf("Element not found\n");
    return 0;*/
    //insert(p,11);
    delete(p,50);
     printf("Inorder traversal after deletion\n");
   inOrder(p);
}