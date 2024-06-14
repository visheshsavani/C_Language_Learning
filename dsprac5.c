#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *initialize(int x){
    struct node *a=(struct node *)malloc(sizeof(struct node));
    a->data=x;
    a->next=NULL;
    return a;
}
struct node *insertEnd(struct node *head,int x){
    struct node *b=(struct node *)malloc(sizeof(struct node));
    b->data=x;
    b->next=NULL;
    struct node *ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=b;
    return head;
}
struct node *removaldup(struct node *head){
struct node *ptr = head;
while(ptr->next!=NULL){
    if(ptr->data == ptr->next->data){
        struct node* duplicate = ptr->next;
            ptr->next = ptr->next->next;
            free(duplicate);
    }
    else{
    ptr=ptr->next;
    }
}
return head;
}
void linkedlist_traversal(struct node *ptr){
    while (ptr!=NULL)
    {
        printf("The element is %d\n",ptr->data);
        //printf("%d ",ptr->data);
        ptr=ptr->next;
    }    
}
int main(){
    struct node *head = initialize(1);
    head= insertEnd(head,1);
    head= insertEnd(head,2);
    head= insertEnd(head,3);
    head= insertEnd(head,4);
    head= insertEnd(head,4);
    printf("The linked list traversal before removal of duplicates\n");
   linkedlist_traversal(head);
    printf("The linked list traversal after removal of duplicates\n");
   head=removaldup(head);
    linkedlist_traversal(head);
}