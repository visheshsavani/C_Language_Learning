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
struct node *reverse(struct node *head){
    struct node *prev=NULL;
    struct node *current=head;
    struct node *next=head;
    while(next!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;        
    }
    return prev;
}
void linkedlist_traversal(struct node *ptr){
    while (ptr!=NULL)
    {
        printf("The element is %d\n",ptr->data);
        //printf("%d ",ptr->data);
        ptr=ptr->next;
    }    
}
int isPalindrome(struct node *head){
   if(head==NULL || head->next==NULL){
    return 1;
   }
   struct node *slow = head;
   struct node *fast= head;
   while(fast!=NULL && fast->next!=NULL){
    slow = slow->next;
    fast= fast->next->next;
   } 
   struct node *secondhalf = reverse(slow);
   //linkedlist_traversal(secondhalf);

   while(secondhalf != NULL){
    if(head->data != secondhalf->data){ 
        return 0;
        }
    head=head->next;
    secondhalf=secondhalf->next;
   }
   return 1;
}
int main(){
    struct node *head = initialize(1);
    head= insertEnd(head,1);
    head= insertEnd(head,1);
    head= insertEnd(head,1);
    head= insertEnd(head,1);
    head= insertEnd(head,1);
    head= insertEnd(head,1);
    head= insertEnd(head,1);
    head= insertEnd(head,1);
    head= insertEnd(head,1);
    head= insertEnd(head,1);
    head= insertEnd(head,1);
    head= insertEnd(head,1);
    head= insertEnd(head,1);
    head= insertEnd(head,1);
    head= insertEnd(head,1);
    head= insertEnd(head,1);
    
    //int a=isPalindrome(head);
    if(isPalindrome(head)) printf("The linked list is a palindrome");
    else printf("The linked list is not a palindrome");
    return 0;
}