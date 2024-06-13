// Create an AVLNode ADT and complete the following functions:
// 1. createNode  
// 2. displayAVLTree 
// 3. getHeight 
// 4. rotateRight
// 5. rotateLeft
// 6. getBalance
// 7. insert
// 8. freeAVLTree

#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode {
    int data;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
} AVLNode;

// complete this function
AVLNode* createNode(int x){
    AVLNode *a = (AVLNode *)malloc(sizeof(AVLNode));
    a->left=NULL;
    a->right=NULL;
    a->data=x;
    a->height=1;    
    return a;
}
int max(int a,int b){
    return a>b?a:b;
}
// Display the level-order traversal of the Tree
void displayAVLTree(AVLNode* root){
    if (root == NULL)
        return;
    
    // Create a queue for level order traversal
    struct AVLNode *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        AVLNode* current = queue[front++];
        printf("%d ", current->data);

        if (current->left)
            queue[rear++] = current->left;
        if (current->right)
            queue[rear++] = current->right;
    }
}

int getHeight(AVLNode* node){
    if(node==NULL){
        return 0;
    }
    return node->height;
}

// function for performing a right rotate
AVLNode* rotateRight(AVLNode* y){
    AVLNode *x= y->left;
    AVLNode *t2 = x->right;

    x->right= y;
    y->left=t2;

    y->height= max(getHeight(y->left),getHeight(y->right)+1);
    x->height= max(getHeight(x->left),getHeight(x->right)+1);
    return x;
}

// function for performing a left rotate
AVLNode* rotateLeft(AVLNode* x){
    AVLNode *y= x->right;
    AVLNode *t2 = y->left;

    x->right= t2;
    y->left=x;

    y->height= max(getHeight(y->left),getHeight(y->right)+1);
    x->height= max(getHeight(x->left),getHeight(x->right)+1);
    return y;
}

// get balance factor of given node
int getBalance(AVLNode* node){
    if(node==NULL){
        return 0;
    }
    return getHeight(node->left)-getHeight(node->right);
}

// This inserts a node with 'data' into the AVL tree. 
// Please ensure that your function covers all 4 possible rotation cases
AVLNode *insert(AVLNode *node,int key){
    if(node==NULL){
        return createNode(key);
    }
    if(key<(node->data)){
        node->left = insert(node->left,key);
    }
    else if(key>(node->data)){
        node->right = insert(node->right,key);
    }
    node->height = 1+max(getHeight(node->left),getHeight(node->right));
    int bf= getBalance(node);
    if(bf>1 && key<(node->left->data)){
        rotateRight(node);
    }
    if(bf<-1 && key>(node->right->data)){
        rotateRight(node);
    }
    if(bf>1 && key>(node->left->data)){
        node->left=rotateLeft(node->left);
        rotateRight(node);
    }
    if(bf<-1 && key<(node->right->data)){
        node->right=rotateLeft(node->right);
        rotateLeft(node);
    }
return node;
}

// This frees the memory used by the AVL tree
void freeAVLTree(AVLNode* root);

int main(){        
    struct AVLNode* root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    displayAVLTree(root);
    
    return 0;
}
