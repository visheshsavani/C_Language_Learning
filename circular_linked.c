#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
void circular_linked_list_traversal(struct node *ptr){
    struct node *p;
    p=ptr;
    do{
        printf("The element is %d\n",p->data);
        p=p->next;
    }while(p!=ptr);
}
struct node *insertatFirst(struct node *ptr,int val){
    struct node *a = (struct node *)malloc(sizeof(struct node *));
    a->data=val;
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p= ptr->next;
    while(p->next!=ptr){
        p = p->next;
    }
    p->next = a;
    a->next = ptr;
    ptr=a;
    return ptr;
}
int main(){
struct node *head = (struct node *)malloc(sizeof(struct node));
struct node *first = (struct node *)malloc(sizeof(struct node));
struct node *second = (struct node *)malloc(sizeof(struct node));
head->data = 8;
head->next= first;

first->data = 45;
first->next= second;

second->data = 83;
second->next= head;
printf("Circular Linked list before insertion\n");
circular_linked_list_traversal(head);
head = insertatFirst(head,46);
head = insertatFirst(head,67);
head = insertatFirst(head,36);
head = insertatFirst(head,666);
printf("Circular Linked list after insertion\n");
circular_linked_list_traversal(head);
    return 0;
}