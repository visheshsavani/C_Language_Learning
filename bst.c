#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};


// Function for creating a new BST node
struct TreeNode* createNode(int x) {
struct TreeNode *a=(struct TreeNode *)malloc(sizeof(struct TreeNode));
a->data = x;
a->left=NULL;
a->right=NULL;
return a;
}

// Function to insert a new value into the BST
struct TreeNode* insertNode(struct TreeNode* root, int x){
if (root == NULL) {
return createNode(x);
}
if (x < root->data) {
root->left = insertNode(root->left, x);
} else if (x > root->data) {
root->right = insertNode(root->right, x);
}
return root;
}


// Function to delete a node with given value from the BST
struct TreeNode* deleteNode(struct TreeNode* root, int x){
if (root == NULL) {
return root;
}
if (x < root->data) {
root->left = deleteNode(root->left, x);
} else if (x > root->data) {
root->right = deleteNode(root->right, x);
} else {
if (root->left == NULL) {
struct TreeNode* temp = root->right;
free(root);
return temp;
} else if (root->right == NULL) {
struct TreeNode* temp = root->left;
free(root);
return temp;
}
}
}

// Function to display the BST in-order
void display(struct TreeNode* root){
if(root!=NULL){
display(root->left);
printf("%d ",root->data);
display(root->right);
}
}

struct TreeNode* findMinValueNode(struct TreeNode* root){
if (root == NULL || root->left == NULL) {
return root;
}
return findMinValueNode(root->left);
}

struct TreeNode* findMaxValueNode(struct TreeNode* root){
if (root == NULL || root->right == NULL) {
return root;
}
return findMaxValueNode(root->right);    
}

struct TreeNode* findNode(struct TreeNode* root, int x){
if (root == NULL || root->data == x) {
return root;
}
if (x < root->data) {
return findNode(root->left, x);
} else {
return findNode(root->right, x);
}
}

void swapValues(struct TreeNode* root, int data_1, int data_2){
struct TreeNode* node1 = findNode(root, data_1);
struct TreeNode* node2 = findNode(root, data_2);
if (node1 == NULL || node2 == NULL) {
printf("one of the values or both, is not found.\n");
return;
}
int temp = node1->data;
node1->data = node2->data;
node2->data = temp;
}

int main(){
struct TreeNode *root = NULL;
root = insertNode(root, 6);
root = insertNode(root,4);
root = insertNode(root, 46);
root = insertNode(root, 32);
root = insertNode(root, 28);
root = insertNode(root, 24);
root = insertNode(root, 18);
root = insertNode(root, 52);

printf("Inorder Traversal :- ");
display(root);
printf("\n");

struct TreeNode* min_node = findMinValueNode(root);
printf("Minimum Value in the node :- %d \n", min_node->data);

struct TreeNode* max_node = findMaxValueNode(root);

printf("Maximum Value Node: %d\n", max_node->data);
int value_Find = 43;
struct TreeNode* node_Find = findNode(root, value_Find);
if (node_Find != NULL) {
printf("The value found in the tree is %d \n",
value_Find);
} else {
printf("The value not found in the tree is %d \n",
value_Find);
}
int value_Delete = 24;
root = deleteNode(root, value_Delete);
printf("Tree after deletion of value %d: ",
value_Delete);
display(root);
printf("\n");
int valueToSwap1 = 46;
int valueToSwap2 = 32;
swapValues(root, valueToSwap1, valueToSwap2);
printf("Binary Tree after swapping values %d and %d: ",
valueToSwap1, valueToSwap2);
display(root);
printf("\n");
free(root);
return 0;
}