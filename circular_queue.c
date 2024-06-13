#include <stdio.h>
#include <stdlib.h>
struct queue{
int size;
int f;
int r;
char *arr;
};
int isEmpty(struct queue *ptr);
int isFull(struct queue *ptr);
void enqueue(struct queue *ptr,int val);
char dequeue(struct queue *ptr);
struct queue *initialize_queue(struct queue *ptr,unsigned size);
char front(struct queue *ptr);
char rear(struct queue *ptr);
void display(struct queue *queue);
int main(){
    struct queue a;
    initialize_queue(&a,10);
    enqueue(&a,'9');
    enqueue(&a,'7');
    enqueue(&a,'5');
    display(&a);
    printf("the dequeue element is %c\n",dequeue(&a));
    enqueue(&a,'6');
    front(&a);
    rear(&a);
    return 0;
}
void display(struct queue *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    int i = ptr->f;
    do
    {
        i = (i + 1) % ptr->size;
        printf("%c ", ptr->arr[i]);
    } while (i != ptr->r);

    printf("\n");
}

struct queue *initialize_queue(struct queue *ptr,unsigned size){
    //struct queue *a=(struct queue *)malloc(sizeof(struct queue));
    ptr->size= size;
    ptr->f=ptr->r=0;
    ptr->arr=(char *)malloc(ptr->size*sizeof(char));
}
void enqueue(struct queue *ptr,int val){
    if(isFull(ptr)){
        printf("Queue is overflow\n");
    }
    else{
        ptr->r=(ptr->r+1)%(ptr->size);
        ptr->arr[ptr->r]=val;
        printf("Enqueue element : %c\n",val);
    }
}
char dequeue(struct queue *ptr){
    char val='\0';
    if(isEmpty(ptr)){
        printf("Queue is underflow\n");
    }
    else{
        ptr->f=(ptr->f+1)% ptr->size;
        val=ptr->arr[ptr->f];
    }
    return val;
}
int isFull(struct queue *ptr){
    if((ptr->r+1)% (ptr->size)==ptr->f){
        return 1;
    }
    return 0;
}
int isEmpty(struct queue *ptr){
    if(ptr->r==ptr->f){
        return 1;
    }
    return 0;
}
char front(struct queue *ptr){
    if (isEmpty(ptr)) {
        printf("Queue is empty\n");
        return '\0';
    }
      printf("The front is : %c\n", ptr->arr[(ptr->f + 1) % ptr->size]);
}
char rear(struct queue *ptr){
    if (isEmpty(ptr)) {
        printf("Queue is empty\n");
        return '\0';
    }
    printf("The rear is : %c\n", ptr->arr[ptr->r]);
}