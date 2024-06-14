#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *initialize(int x)
{
    struct node *a = (struct node *)malloc(sizeof(struct node));
    a->data = x;
    a->next = NULL;
    return a;
}
struct node *insertEnd(struct node *head, int x)
{
    struct node *b = (struct node *)malloc(sizeof(struct node));
    b->data = x;
    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = b;
    b->next = NULL;
    return head;
}
void linkedlist_traversal(struct node *ptr)
{
    struct node *head=ptr;
    while (head != NULL)
    {
        printf("%d-> ", head->data);
        head = head->next;
    }
    printf("\n");
}
struct node *reverse(struct node *head)
{
    struct node *prev = NULL;
    struct node *currentnode = head;
    struct node *nextnode = head;
    while (nextnode != NULL)
    {
        nextnode = nextnode->next;
        currentnode->next = prev;
        prev = currentnode;
        currentnode = nextnode;
    }
    return prev;
}
struct node *addnumber(struct node *l1, struct node *l2)
{
    struct node *ptr1 = reverse(l1);
    struct node *ptr2 = reverse(l2);
    int carry = 0;
    int sum = 0;
    struct node *res = initialize(0);
    while (ptr1 || ptr2)
    {
        sum = 0;
        if (ptr1)
            sum += ptr1->data;
        if (ptr2)
            sum += ptr2->data;
        sum+=carry;
        carry = sum / 10;
        sum = sum % 10;
        res = insertEnd(res, sum);
        if (ptr1)
            ptr1 = ptr1->next;
        if (ptr2)
            ptr2 = ptr2->next;
    }
    if (carry)
        res = insertEnd(res, carry);
    return res->next;
}
int main()
{
    struct node *num1 = initialize(5);
    num1 = insertEnd(num1, 4);
    num1 = insertEnd(num1, 3);
    num1 = insertEnd(num1, 4);
    printf("The linked list 1 is \n");
    linkedlist_traversal(num1);
    struct node *num2 = initialize(4);
    num2 = insertEnd(num2, 6);
    num2 = insertEnd(num2, 5);
    num2 = insertEnd(num2, 1);
    printf("The linked list 2 is \n");
    linkedlist_traversal(num2);
    struct node *result = addnumber(num1,num2);
     printf("The resultant linked list is \n");
    linkedlist_traversal(reverse(result));
    return 0;
}