#include <stdio.h>
#include <stdlib.h>
struct queue{
int size;
int f;
int r;
int *arr;
};
void enqueue(struct queue *ptr,int a);
int dequeue(struct queue *ptr);
int isEmpty(struct queue *ptr);
int isFull(struct queue *ptr);
int display(struct queue *ptr);
int main(){
    struct queue *a=(struct queue *)malloc(sizeof(struct queue));
    a->size=4;
    a->f=a->r=0;
    a->arr=(int *)malloc(a->size*sizeof(int));
    //enqueue(a,7);
//enqueue(a,6);
enqueue(a,327);
enqueue(a,32);
printf("The dequeue element is %d\n",dequeue(a));
enqueue(a,5);
display(a);
    return 0;
}
int isEmpty(struct queue *ptr){
    if(ptr->f==ptr->r){
        //printf("The queue is empty\n");
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct queue *ptr){
    if(ptr->r==ptr->size-1){
        //printf("The queue is full\n");
        return 1;
    }
    else{
        return 0;
    }
}
void enqueue(struct queue *ptr,int a){
    if(isFull(ptr)){
        printf("The queue is full\n");
    }
    else{
    ptr->r=(ptr->r+1)%ptr->size;
    ptr->arr[ptr->r]=a;
    }
}
int dequeue(struct queue *ptr){
    int x;
    if (isEmpty(ptr))
    {
        printf("The queue is empty\n");
        return -1;
    }
    else{
        ptr->f=(ptr->f+1)%(ptr->size);
        x=ptr->arr[ptr->f];
    }
    return x;
    }
int display(struct queue *ptr){
//return ptr->arr[ptr->f+1];
while(ptr->f!=ptr->r){
    printf("%d ",ptr->arr[ptr->f+1]);
    ptr->f=ptr->f+1;   
}
}