#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};
void doubly_forward_traversal(struct node *ptr){
    while(ptr!=NULL){
        printf("The element is %d\n",ptr->data);
        ptr=ptr->next;
    }
}
void doubly_backward_traversal(struct node *ptr){
do{
    printf("The element is %d\n",ptr->data);
        ptr=ptr->prev;
}while(ptr->prev!=NULL);
printf("The element is %d\n",ptr->data);
}
int main(){
    struct node *head = (struct node *)malloc(sizeof(struct node));
struct node *first = (struct node *)malloc(sizeof(struct node));
struct node *second = (struct node *)malloc(sizeof(struct node));
head->data = 8;
head -> prev =NULL;
head->next= first;

first->data = 45;
first->prev=head;
first->next= second;

second->data = 83;
second->prev= first;
second->next= NULL;
//doubly_forward_traversal(head);
doubly_backward_traversal(second);
    return 0; 
}