#include<stdio.h>
#include <stdlib.h>
struct queue{
int front;
int rear;
int size;
int *arr;
};
int isEmpty(struct queue *a){
    if(a->front==a->rear){
        printf("The queue is empty\n");
        return -1;
    }
    else return 0;
}
int isFull(struct queue *a){
    if(a->front==(a->size-1)){
        printf("The queue is full\n");
        return -1;
    }
    else return 0;
}
void enqueue(struct queue *a,int x){
    if(isFull(a)) printf("The queue is overflow\n");
    else{
        a->rear=a->rear+1;
        a->arr[a->rear]=x;
    }
}
int dequeue(struct queue *a){
    if(isEmpty(a)){ 
        printf("The queue is underflow\n");
        return -1;}
    else{
        int x;
        a->front=a->front+1;
        x=a->arr[a->front];
        return x;
    }
}
int main(){
    struct queue *c = (struct queue *)malloc(sizeof(struct queue));
    c->size=10;
    c->front=c->rear=-1;
    c->arr=(int *)malloc(c->size*sizeof(int));
    enqueue(c,8);
    enqueue(c,9);
    enqueue(c,10);
    enqueue(c,11);
    enqueue(c,12);
    printf("The dequeue element is %d\n",dequeue(c));
    printf("The dequeue element is %d\n",dequeue(c));
    printf("The dequeue element is %d\n",dequeue(c));
    return 0;
}
