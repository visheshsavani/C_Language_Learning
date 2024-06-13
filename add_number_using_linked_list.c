#include "linkedlist_insertion.c"
#include <stdio.h>
#include <stdlib.h>
struct node *Newnode(int data);
struct node* addTwoLists(struct node *list1,struct node *list2);
int main(){
    struct node *k = intialize(4,6,5,3);
    struct node *d = intialize(6,5,2,3);
    struct node *c = addTwoLists(k,d);
    printf("The resultant linked list :-\n");
    linkedlist_traversal(c);
    return 0;
}
struct node *Newnode(int data)
{
    struct node* new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
struct node* addTwoLists(struct node *list1,struct node *list2)
{
    struct node *a =reverse(list1);
    struct node *b =reverse(list2);
    struct node *res = NULL;
    struct node *temp = NULL;
    struct node *prev = NULL;
    int carry = 0;
    int sum;
 
    while (a != NULL || b != NULL) {
        sum = carry + (a ? a->data : 0) + (b ? b->data : 0);
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;
        temp = Newnode(sum);
        if (res == NULL)
            res = temp;
        else
            prev->next = temp;
        prev = temp;
        if (a)
            a = a->next;
        if (b)
            b = b->next;
    }
    if (carry > 0)
        temp->next = Newnode(carry);
    return reverse(res);
}
